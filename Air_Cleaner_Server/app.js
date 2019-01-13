const express = require("express");
const app = express();
var mysql = require('mysql');
var connection = mysql.createConnection({
	host : 'localhost',
	user : 'drkim',
	password : 'qwe123!@#',
	database : 'test'
});

connection.connect();
console.log('[Database] Connected to the Air_Cleaner database');

app.use(express.static('public'));
app.set('views', __dirname);
app.set('view engine', 'ejs');
app.engine('html', require('ejs').renderFile);


app.get('/', (req, res) => {
    res.render('index.html');
});

app.get('/run', (req, res) => {
	const child_process = require('child_process');
	
	var workerProcess = child_process.exec('../runAirCleaner run',function 
     		(error, stdout, stderr) {
      
      	if (error) {
       	  	console.log(error.stack);
       	  	console.log('Error code: '+error.code);
       	  	console.log('Signal received: '+error.signal);
      	}
      		console.log('stdout: ' + stdout);
      		console.log('stderr: ' + stderr);
  	});

 		workerProcess.on('exit', function (code) {
      		console.log('Child process exited with exit code '+code);
		
   	});
	res.set('Content-Type', 'text/plain');
	res.send("Test.. Test ..");

});

app.get('/info', (req, res) => {
	connection.query('SELECT * FROM weather ORDER BY _time DESC Limit 10',
	function (err, rows, fields) {
		if (err) {
			throw error;
		}else{
			console.log("[Server] SELECT * From weather");
			res.header("Content-Type", "text/json");
			res.json({"weather": rows});
		}
	});
});	

app.listen(8080, () => {
	console.log("[Server] Air_Cleaner_Server is listening on port 8080");
})
	
