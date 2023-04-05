// Source: https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');
    main();
});

function readLine() {
    return inputString[currentLine++];
}


function main() {
    const NUMBER = +readLine();
    const FACTORIAL = calculateFactorialOf(NUMBER);
    console.log(FACTORIAL.toString());
}

    function calculateFactorialOf(number) {
        let factorial = BigInt(1);
        for (let i = BigInt(2); i <= number; i++) factorial *= i;
        return factorial;
    }
