/**
 * Created by KICT-02 on 2016-07-19.
 */

let buf = new Buffer(8);

buf.writeInt32BE(0x01020304,0);
buf.writeInt32BE(0x01020304,4);
console.log(buf);

let  buf2 = new Buffer(2);

buf2.writeInt16BE(7);
console.log(buf2);

buf2.writeInt16LE(7);
console.log(buf2);

let buf3 = new Buffer([0x00,0x07]); //16비트 정수형 빅엔디언
let a =buf3.readInt16BE();
console.log('a = ' + a);
let b =buf3.readInt16LE();
console.log('b = ' + b);