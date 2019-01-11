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
	
