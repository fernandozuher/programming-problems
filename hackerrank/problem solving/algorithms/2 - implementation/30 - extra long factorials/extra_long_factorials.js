// https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine() {
    return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
    let number = +readLine();
    let factorial = calculateFactorialOf(number);
    console.log(factorial.toString());
}

    function calculateFactorialOf(number) {
        let factorial = BigInt(1);
        for (let currentNumber = BigInt(2); currentNumber <= number; ++currentNumber)
            factorial *= currentNumber;
        return factorial;
    }
