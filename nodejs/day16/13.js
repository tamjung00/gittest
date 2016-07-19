/**
 * Created by KICT-02 on 2016-07-19.
 */

let test = new Buffer([0x41,0x42,0x43]);
console.log(test);
console.log(test[1]);
console.log(String(test));
console.log(String.fromCharCode(test[1]));