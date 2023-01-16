// Source: https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

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
    const inputLine = readLineAsNumberArray();
    const maximumHeightCanJump = inputLine[1]

    const hurdlesHeights = readLineAsNumberArray()

    const result = new Result(hurdlesHeights, maximumHeightCanJump);
}

    function readLineAsNumberArray() {
        const inputLine = readLine().split(" ").map(Number);
        return inputLine;
    }

        class Result {
            #hurdlesHeights;
            #maximumHeightCanJump;
            #doses;

            constructor(hurdlesHeights, maximumHeightCanJump) {
                this.#hurdlesHeights = [...hurdlesHeights];
                this.#maximumHeightCanJump = maximumHeightCanJump;
                this.#doses = 0;

                this.#hurdleRace();
                this.printResult();
            }

                #hurdleRace() {
                    const highestHurdle = Math.max(...this.#hurdlesHeights)
                    this.#doses = highestHurdle > this.#maximumHeightCanJump ? highestHurdle - this.#maximumHeightCanJump : 0;
                }

                printResult() {
                    console.log(this.#doses);
                }
        }
