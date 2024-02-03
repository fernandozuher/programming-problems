// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

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
    let [startingDayNumber, endingDayNumber, divisor] = readIntArray();
    let obj = new BeautifulDays(startingDayNumber, endingDayNumber, divisor);
    console.log(obj.nBeautifulDays());
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    class BeautifulDays {
        #startingDayNumber;
        #endingDayNumber;
        #divisor;
        #nBeautifulDays;

        constructor(startingDayNumber, endingDayNumber, divisor) {
            this.#startingDayNumber = startingDayNumber;
            this.#endingDayNumber = endingDayNumber;
            this.#divisor = divisor;
            this.#nBeautifulDays = 0;
            this.#calculateBeautifulDaysQuantity();
        }

            #calculateBeautifulDaysQuantity() {
                for (let number = this.#startingDayNumber; number <= this.#endingDayNumber; ++number) {
                    let reverseNumber = this.#generateReverseNumber(number);
                    if (this.#isDayBeautiful(number, reverseNumber))
                        ++this.#nBeautifulDays;
                }
            }

                #generateReverseNumber(number) {
                    let reverseNumber = 0;
                    for (; number > 0; number = Math.trunc(number / 10))
                        reverseNumber = (reverseNumber * 10) + (number % 10);
                    return reverseNumber;
                }

                #isDayBeautiful(number, reverseNumber) {
                    return Math.abs(number - reverseNumber) % this.#divisor == 0;
                }

        nBeautifulDays() {
            return this.#nBeautifulDays;
        }
    }
