var rtu = require('serialport').SerialPort
var serial = new rtu('/dev/slave', {
    baudrate : 57600})

var rotationsMade = 0;

setInterval(function(){
    rotationsMade += 123;
    serial.write(rotationsMade)
    console.log("Foo Bar: " + rotationsMade)
},200);
