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
        const OBJ = new FindDigits(NUMBER);
        output[i] = OBJ.getDivisors();
    }

    printOutput(output);
}

    function readANumber() {
        const NUMBER = +readLine();
        return NUMBER;
    }

    function printOutput(array) {
        array.forEach(number => console.log(number));
    }

    class FindDigits {
        #number;
        #divisors;

        constructor(number) {
            this.#number = number;
            this.#divisors = 0;
            this.#findNumberDivisorsQuantity();
        }

            #findNumberDivisorsQuantity(number) {
                for (let currentNumber = this.#number; currentNumber != 0; currentNumber = this.#removeLastDigitOfNumber(currentNumber)) {
                    const DIVISOR = this.#getLastDigitOfNumber(currentNumber);
                    if (this.#isNumberEvenlyDividedByDivisor(DIVISOR))
                        this.#divisors++;
                }
            }

                #getLastDigitOfNumber(number) {
                    return number % 10;
                }

                #isNumberEvenlyDividedByDivisor(divisor) {
                    return divisor != 0 && this.#number % divisor == 0;
                }

                #removeLastDigitOfNumber(number) {
                    return Math.trunc(number / 10);
                }

        getDivisors() {
            return this.#divisors;
        }
    }
