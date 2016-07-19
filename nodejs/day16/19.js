/**
 * Created by KICT-02 on 2016-07-19.
 */

const net = require('net');
const PORT = 8080;

let solution;
let bSolved = false;
solution = Math.round(Math.random() * 100);
console.log(solution);

net.createServer((socket)=> {

    console.log('connect :' + socket.remoteAddress + ':'
        + socket.remotePort
    );
    socket.on('error',(evt)=>{
        console.log(evt);
    });
    socket.on('close',(evt)=>{
        console.log('connection closed');
        console.log(evt);
    });
    socket.on('data',(evt)=>{
        //console.log(evt.toString());
        let data = JSON.parse(evt.toString());
        let resultObj = {};
        if(bSolved == false) {
            console.log(data.name + "try game ...");

            if (data.value > solution) {
                resultObj.txt = "high";
            }
            else if (data.value < solution) {
                resultObj.txt = "low";
            }
        }
            else {
                resultObj.txt = "game over";
            }
            socket.write(JSON.stringify(resultObj));
        });
}).listen(PORT);

console.log('server listen :' + PORT);

