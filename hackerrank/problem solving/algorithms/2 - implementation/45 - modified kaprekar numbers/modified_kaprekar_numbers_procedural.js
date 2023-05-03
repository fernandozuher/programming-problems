// Source: https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

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
    const LOWER_LIMIT = +readLine();
    const UPPER_LIMIT = +readLine();

    const OUTPUT = findKaprekarNumbersInRange(LOWER_LIMIT, UPPER_LIMIT);
    printOutput(OUTPUT);
}

    function findKaprekarNumbersInRange(lowerLimit, upperLimit) {
        let kaprekarNumbers = Array();

        for (let number = lowerLimit; number <= upperLimit; number++) {
            const POTENTIAL_KAPREKAR_NUMBER = calculatePotentialKaprekarNumber(number)
            if (number == POTENTIAL_KAPREKAR_NUMBER)
                kaprekarNumbers.push(number);
        }

        return kaprekarNumbers;
    }

        function calculatePotentialKaprekarNumber(number) {
            const SQUARE_NUMBER_IN_STRING = Math.pow(number, 2).toString();
            const SIZE_OF_STRING = number.toString().length;

            const LEFT_NUMBER_IN_STRING = getLeftNumberInString(SQUARE_NUMBER_IN_STRING, SIZE_OF_STRING);
            const RIGHT_NUMBER_IN_STRING = getRightNumberInString(SQUARE_NUMBER_IN_STRING, SIZE_OF_STRING);

            const POTENTIAL_KAPREKAR_NUMBER = sumNumbersInStrings(LEFT_NUMBER_IN_STRING, RIGHT_NUMBER_IN_STRING);

            return POTENTIAL_KAPREKAR_NUMBER;
        }

            function getLeftNumberInString(squareNumberInString, sizeOfString) {
                const DIGITS_TO_SKIP = 0;
                const DIGITS_TO_TAKE = squareNumberInString.length - sizeOfString;
                const NUMBER_IN_STRING = squareNumberInString.substring(DIGITS_TO_SKIP, DIGITS_TO_TAKE);
                return NUMBER_IN_STRING;
            }

            function getRightNumberInString(squareNumberInString, sizeOfString) {
                const DIGITS_TO_SKIP = squareNumberInString.length - sizeOfString;
                const NUMBER_IN_STRING = squareNumberInString.substring(DIGITS_TO_SKIP);
                return NUMBER_IN_STRING;
            }

            function sumNumbersInStrings(leftNumberinString, rightNumberInString) {
                if (leftNumberinString.length > 0 && rightNumberInString.length > 0)
                    return parseInt(leftNumberinString) + parseInt(rightNumberInString);
                else if (leftNumberinString.length == 0)
                    return parseInt(rightNumberInString);
                else if (rightNumberInString.length == 0)
                    return parseInt(leftNumberinString);

                return 0;
            }

    function printOutput(array) {
        if (array.length > 0)
            console.log(...array);
        else
            console.log("INVALID RANGE");
    }
