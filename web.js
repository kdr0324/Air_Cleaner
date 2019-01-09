var http = require('http');

function onRequest(request,response){

    console.log("user request " + request.url);

    response.writeHead(200,{"Context-Type": "text/plain"});

    response.write("Hello World");

    response.end();

}

http.createServer(onRequest).listen(8080);

console.log("Nodejs web server start");



