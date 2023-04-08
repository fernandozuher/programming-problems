// Source: https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

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
    const N_TEST_CASES = +readLine();
    const OUTPUT = new Array(N_TEST_CASES).fill();

    for (let i in OUTPUT) {
        const [BEGIN, END] = readAnArray();
        OUTPUT[i] = calculateNumberOfSquareIntegersInRange(BEGIN, END);
    }

    printArray(OUTPUT);
}

    function readAnArray() {
        const ARRAY = readLine().split(" ").map(Number);
        return ARRAY;
    }

    function calculateNumberOfSquareIntegersInRange(begin, end) {
        let squares = 0;
        for (let number = findFirstSquareIntegerFromNumber(begin); isPowerOf2OfNumberLessThanOrEqualToLimit(number, end); number++)
            squares++;
        return squares;
    }

        function findFirstSquareIntegerFromNumber(number) {
            const SQUARE_ROOT_NUMBER = Math.sqrt(number);
            const SQUARE_INTEGER = getSquareIntegerFromNumber(SQUARE_ROOT_NUMBER);
            return SQUARE_INTEGER;
        }

            function getSquareIntegerFromNumber(number) {
                const INTEGER_PART = Math.trunc(number);
                return number === INTEGER_PART ? INTEGER_PART : INTEGER_PART + 1;
            }

        function isPowerOf2OfNumberLessThanOrEqualToLimit(number, limit) {
            return Math.pow(number, 2) <= limit;
        }

    function printArray(array) {
        array.forEach(element => console.log(element));
    }
