/**
 * Created by KICT-02 on 2016-07-19.
 */
 let array_test = [
    {
        name : 'jinhee',
        hp:52
    },
    {
        name : 'mongu',
        hp:27
    },
    {
        name : 'orc',
         hp:47
    },
    {
        name : 'trol',
        hp:35
    }
];


console.log(array_test);

array_test.sort((left,right)=> {
    //return left.hp - right.hp;
    return right.hp - left.hp;
} );
console.log('===============================');
console.log(array_test);