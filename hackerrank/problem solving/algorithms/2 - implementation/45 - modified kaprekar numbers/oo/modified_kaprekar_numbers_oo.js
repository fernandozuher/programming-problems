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

    const OBJ = new KaprekarNumbers(LOWER_LIMIT, UPPER_LIMIT);
    printOutput(OBJ.getKaprekarNumbers());
}

    class KaprekarNumbers {
        #lowerLimit;
        #upperLimit;
        #kaprekarNumbers;

        constructor(lowerLimit, upperLimit) {
            this.#lowerLimit = lowerLimit;
            this.#upperLimit = upperLimit;
            this.#kaprekarNumbers = [];

            this.#findKaprekarNumbersInRange();
        }

            #findKaprekarNumbersInRange() {
                for (let number = this.#lowerLimit; number <= this.#upperLimit; number++) {
                    const POTENTIAL_KAPREKAR_NUMBER = this.#calculatePotentialKaprekarNumber(number)
                    if (number == POTENTIAL_KAPREKAR_NUMBER)
                        this.#kaprekarNumbers.push(number);
                }
            }

                #calculatePotentialKaprekarNumber(number) {
                    const SQUARE_NUMBER_IN_STRING = Math.pow(number, 2).toString();
                    const LENGTH_OF_NUMBER_IN_STRING = number.toString().length;

                    const LEFT_NUMBER_IN_STRING = this.#getLeftNumberInString(SQUARE_NUMBER_IN_STRING, LENGTH_OF_NUMBER_IN_STRING);
                    const RIGHT_NUMBER_IN_STRING = this.#getRightNumberInString(SQUARE_NUMBER_IN_STRING, LENGTH_OF_NUMBER_IN_STRING);

                    const POTENTIAL_KAPREKAR_NUMBER = this.#sumNumbersInStrings(LEFT_NUMBER_IN_STRING, RIGHT_NUMBER_IN_STRING);

                    return POTENTIAL_KAPREKAR_NUMBER;
                }

                    #getLeftNumberInString(squareNumberInString, lengthOfNumberInString) {
                        const DIGITS_TO_SKIP = 0;
                        const DIGITS_TO_TAKE = squareNumberInString.length - lengthOfNumberInString;
                        const NUMBER_IN_STRING = squareNumberInString.substring(DIGITS_TO_SKIP, DIGITS_TO_TAKE);
                        return NUMBER_IN_STRING;
                    }

                    #getRightNumberInString(squareNumberInString, lengthOfNumberInString) {
                        const DIGITS_TO_SKIP = squareNumberInString.length - lengthOfNumberInString;
                        const NUMBER_IN_STRING = squareNumberInString.substring(DIGITS_TO_SKIP);
                        return NUMBER_IN_STRING;
                    }

                    #sumNumbersInStrings(leftNumberinString, rightNumberInString) {
                        if (leftNumberinString.length > 0 && rightNumberInString.length > 0)
                            return parseInt(leftNumberinString) + parseInt(rightNumberInString);
                        else if (leftNumberinString.length == 0)
                            return parseInt(rightNumberInString);
                        else if (rightNumberInString.length == 0)
                            return parseInt(leftNumberinString);

                        return 0;
                    }

        getKaprekarNumbers() {
            return this.#kaprekarNumbers;
        }
    }

    function printOutput(array) {
        if (array.length > 0)
            console.log(...array);
        else
            console.log("INVALID RANGE");
    }
