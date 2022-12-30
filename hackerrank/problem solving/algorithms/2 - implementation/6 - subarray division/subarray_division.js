// Source: https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

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
    readLineAsNumberArray();
    const chocolateSquares = readLineAsNumberArray();
    const dayMonth = readLineAsNumberArray();

    const result = new Result(chocolateSquares, dayMonth);
}

    function readLineAsNumberArray() {
        const numbers = readLine().split(" ").map(Number);
        return numbers;
    }

    class Result {
        #chocolateSquares;
        #day;
        #month;
        #waysBarCanBeDivided;

        constructor(chocolateSquares, dayMonth) {
            this.#chocolateSquares = [...chocolateSquares];
            this.#day = dayMonth[0];
            this.#month = dayMonth[1];
            this.#waysBarCanBeDivided = 0;

            this.#birthday();
            this.printResult();
        }

    	    #birthday() {
    			for (let i = 0, n1 = this.#chocolateSquares.length - this.#month + 1; i < n1; i++) {
                    let sum = 0;
                    for (let j = i, n2 = i + this.#month; j < n2; sum += this.#chocolateSquares[j++]);
                    if (sum === this.#day)
                        this.#waysBarCanBeDivided++;
                }
    		}
        
            printResult() {
                console.log(this.#waysBarCanBeDivided);
            }
    }
