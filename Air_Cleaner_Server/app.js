//Create Express Application
const express = require("express");
const app = express();
//mysql module
var mysql = require('mysql');

//mysql connection id information
//mysql server installed in raspberry pi
//db server has information about air quality in my room
//tmeperature, humidity, air quality
var connection = mysql.createConnection({
	host : 'localhost',
	user : 'drkim',
	password : 'qwe123!@#',
	database : 'test'
});

//connect to mysql server
connection.connect();
console.log('[Database] Connected to the Air_Cleaner database');


//Mounts the specified path
app.use(express.static('public'));
//setting name to value  'views'->__dirname
app.set('views', __dirname);
//setting anme to value 'view engine'->'ejs'
app.set('view engine', 'ejs');
app.engine('html', require('ejs').renderFile);

//Routes HTTP GET requests to the specified path with the specified callback functions.
//just test code about server state
app.get('/', (req, res) => {
	//Returns the rendered HTML of a view via the callback function
    res.render('index.html');
});

//get HTTP request /[start | stop] -> ../runAirClinear [start / stop]
//remote control Air Cleaner

//start runAirCleaner App
app.get('/start', (req, res) => {
	//using child process module
	const child_process = require('child_process');
	
	//exec ../runAirCleaner [start]
	var workerProcess = child_process.exec('../runAirCleaner start',function 
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


//get HTTP request for room condition from data base
//results will send json type
app.get('/info', (req, res) => {

	//query to mysql db for get 10 line information about room conditions
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


//server start listen port 8080
app.listen(8080, () => {
	//console log..
	console.log("[Server] Air_Cleaner_Server is listening on port 8080");
})
	
