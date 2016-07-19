/**
 * Created by KICT-02 on 2016-07-19.
 */

let array_test = [52,101,32,45,73,270,129,63];

//100이상 수만 골라서 지우기
for(let i=0;i<array_test.length;i++) {
    if(array_test[i] <100) {
        console.log(array_test[i]);
    }
}

//for(let i=0;i<array_test.length;i++) {
for(let i=array_test.length;i>=0;i--) {
    if(array_test[i] > 100) {
        array_test.splice(i,1);
    }
}
//[52,32,45,73,63]
console.log(array_test);