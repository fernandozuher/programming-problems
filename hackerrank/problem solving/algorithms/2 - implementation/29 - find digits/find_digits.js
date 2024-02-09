// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

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
    let n = +readLine();
    let nNumberDivisors = new Array(n).fill(0);

    for (let i = 0; i < n; ++i) {
        let number = +readLine();
        let obj = new FindDigits(number);
        nNumberDivisors[i] = obj.divisors();
    }

    nNumberDivisors.forEach(x => console.log(x));
}

    class FindDigits {
        #number;
        #divisors;

        constructor(number) {
            this.#number = number;
            this.#divisors = 0;
            this.#findNumberDivisorsQuantity();
        }

            #findNumberDivisorsQuantity() {
                for (let currentNumber = this.#number; currentNumber != 0; currentNumber = this.#removeLastDigitOfNumber(currentNumber)) {
                    let divisor = this.#getLastDigitOfNumber(currentNumber);
                    if (this.#isNumberEvenlyDividedByDivisor(divisor))
                        ++this.#divisors;
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

        divisors() {
            return this.#divisors;
        }
    }
