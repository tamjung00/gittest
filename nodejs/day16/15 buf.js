/**
 * Created by KICT-02 on 2016-07-19.
 */

let buff = new Buffer(4);
buff.writeFloatBE(3.14);

console.log(buff);

buff.writeFloatLE(3.14);
console.log(buff);