/**
 * Created by KICT-02 on 2016-07-19.
 */

const net = require('net');


const ip = 'localhost';
const PORT = 8080;

let socket = new net.Socket();

socket.connect(PORT,ip,()=>{
    console.log("connect to :" + ip + PORT);
    socket.write("여보세요");

});

socket.on('data',(evt)=>{
        console.log(String(evt));
        //socket.end("bye");
        socket.destroy();
});
socket.on('error',(evt)=>{

});
socket.on('close',()=>{

});