// Source: https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

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
    const N_TEST_CASES = readANumber();
    const output = new Array(N_TEST_CASES).fill();

    for (let i = 0; i < N_TEST_CASES; i++) {
        const NUMBER = readANumber();
        output[i] = findNumberDivisorsQuantity(NUMBER);
    }

    printOutput(output);
}

function readANumber() {
    const NUMBER = +readLine();
    return NUMBER;
}

function findNumberDivisorsQuantity(number) {
    let divisors = 0;

    for (let currentNumber = number; currentNumber != 0; currentNumber = Math.trunc(currentNumber / 10)) {
        const POTENTIAL_DIVISOR = currentNumber % 10;
        if (isNumberEvenlyDividedByDivisor(number, POTENTIAL_DIVISOR))
            divisors++;
    }

    return divisors;
}

function isNumberEvenlyDividedByDivisor(number, divisor) {
    return divisor != 0 && number % divisor == 0;
}

function printOutput(array) {
    array.forEach(number => console.log(number));
}
