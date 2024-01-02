// Source: https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

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

function main() {
    let n = +readLine();
    let chocolateSquares = readIntArray();
    let dayMonth = readIntArray();

    let obj = new TheBirthdayBar(chocolateSquares, dayMonth);
    console.log(obj.waysBarCanBeDivided());
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    class TheBirthdayBar {
        #chocolateSquares;
        #day;
        #month;
        #nDivisions;

        constructor(chocolateSquares, dayMonth) {
            this.#chocolateSquares = [...chocolateSquares];
            this.#day = dayMonth[0];
            this.#month = dayMonth[1];
            this.#nDivisions = 0;

            this.#birthday();
        }

            #birthday() {
                for (let i = 0, n1 = this.#chocolateSquares.length - this.#month + 1; i < n1; ++i) {
                    let sum = 0;

                    for (let j = i, n2 = i + this.#month; j < n2; sum += this.#chocolateSquares[j++]);
                    if (sum === this.#day)
                        ++this.#nDivisions;
                }
            }
        
        waysBarCanBeDivided() {
            return this.#nDivisions;
        }
    }
