var express = require('express');
var app = express();
var server  = require('http').createServer(app);
var fs = require('fs');
var io = require('socket.io').listen(server);

var rtu = require('serialport');
var serial = new rtu.SerialPort('/dev/cu.usbmodem1421', {
    parser: rtu.parsers.readline("\n")
})

app.use(express.static(__dirname + '/public'));
app.use(express.bodyParser());

server.listen(8080);

app.get('/', function(req, res){
    console.log("Connection was made!!");
    var file = fs.readFileSync('./public/index.html');
    res.render(file);
    res.end();
});

app.post('/startCollection', function(req, res){
    console.log('Sending request to start collection');

});

var rawVal
var timeArduino
serial.on('data', function(data){
    data = data.split(',')
    rawVal = parseInt(data[1]);
    timeArduino = parseInt(data[0])
    console.log(rawVal / 685);
    io.sockets.emit('hello', {time: timeArduino, rawVal : rawVal, adjusted : (rawVal/685)});
});

io.sockets.on('connection', function(socket){
    socket.on('Foo', function(data){
        if(data.start === true){
            serial.write('g');
        } else serial.write('s');
    })

})

