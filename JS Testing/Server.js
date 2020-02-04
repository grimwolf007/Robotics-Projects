// Creating an Http Server that just prints Hello World 
//  and listens on port 8888

//require accesses a module; http ships with node.
//  effectively http = new http
var PORT = 3000;

var http = require("http");

server = http.createServer(function(request, response) {
    response.writeHead(200, { "Content-Type": "text/plain" });
    response.write("Hello World");
    response.end();
})

server.listen(PORT, function() {
    console.log('Server is running at ' + PORT);
});