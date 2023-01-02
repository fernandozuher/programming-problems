// Source: https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

'use strict';
const fs = require('fs');
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
    const year = readLineAsNumberArray();

    const result = new Result(year[0]);
}

    function readLineAsNumberArray() {
        const numbers = readLine().split(" ").map(Number);
        return numbers;
    }

    class Result {
        #year;
        #date;

        constructor(year) {
            this.#year = year;
            this.#date = "";

            this.#dayOfProgrammer();
            this.printResult();
        }

    	    #dayOfProgrammer() {
                if (this.#year != 1918) {
                    const isLeap = this.#year > 1918 ? this.#isLeapGregorianYear() : this.#isLeapJulianYear();
                    this.#date = isLeap ? "12.09." : "13.09.";
                }
                else
                    this.#date = "26.09.";

                this.#date += this.#year.toString();
            }

                #isLeapGregorianYear() {
                    return !(this.#year % 400) || (!(this.#year % 4) && this.#year % 100);
                }

                #isLeapJulianYear() {
                    return !(this.#year % 4);
                }
        
            printResult() {
                console.log(this.#date);
            }
    }
