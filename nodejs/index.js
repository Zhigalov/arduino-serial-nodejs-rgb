var SerialPort = require('serialport').SerialPort;
var serialPort = new SerialPort('/dev/tty.usbmodem1411', { baudrate: 9600 });

function onData(data) {
    process.stdout.write(data);
}

function onSerialOpen() {
  serialPort.on('data', onData);
}

function onError(err) {
    err && console.error(err);
}

function writeData(data) {
    serialPort.write(data, onError)
}

serialPort.on('open', onSerialOpen);
serialPort.on('error', onError);

process.stdin.on('data', writeData);
