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
        const OBJ = new SherlockAndSquares(BEGIN, END);
        OUTPUT[i] = OBJ.getQuantityOfSquareIntegers();
    }

    printArray(OUTPUT);
}

    function readAnArray() {
        const ARRAY = readLine().split(" ").map(Number);
        return ARRAY;
    }

    function printArray(array) {
        array.forEach(element => console.log(element));
    }

    class SherlockAndSquares {
        #begin;
        #end;
        #quantityOfSquareIntegers;

        constructor(begin, end) {
            this.#begin = begin;
            this.#end = end;
            this.#quantityOfSquareIntegers = 0;

            this.#calculateNumberOfSquareIntegersInRange();
        }

            #calculateNumberOfSquareIntegersInRange() {
                const FIRST_SQUARE_INTEGER = this.#findFirstSquareIntegerFromBeginNumber();
                for (let number = FIRST_SQUARE_INTEGER; this.#isPowerOf2OfNumberLessThanOrEqualToEndNumber(number); number++)
                   this.#quantityOfSquareIntegers++;
            }

                #findFirstSquareIntegerFromBeginNumber() {
                    const SQUARE_ROOT_NUMBER = Math.sqrt(this.#begin);
                    const SQUARE_INTEGER = this.#getSquareIntegerFromNumber(SQUARE_ROOT_NUMBER);
                    return SQUARE_INTEGER;
                }

                    #getSquareIntegerFromNumber(number) {
                        const INTEGER_PART = Math.trunc(number);
                        return number === INTEGER_PART ? INTEGER_PART : INTEGER_PART + 1;
                    }

                #isPowerOf2OfNumberLessThanOrEqualToEndNumber(number) {
                    return Math.pow(number, 2) <= this.#end;
                }

        getQuantityOfSquareIntegers() {
            return this.#quantityOfSquareIntegers;
        }
    }
