// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

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

////////////////////////////////////////////////

function main() {
    let [n, maximumHeightCanJump] = readIntArray();
    let hurdlesHeights = readIntArray();
    let obj = new HurdleRace(hurdlesHeights, maximumHeightCanJump);
    console.log(obj.doses());
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    class HurdleRace {
        #hurdlesHeights;
        #maximumHeightCanJump;
        #doses;

        constructor(hurdlesHeights, maximumHeightCanJump) {
            this.#hurdlesHeights = hurdlesHeights;
            this.#maximumHeightCanJump = maximumHeightCanJump;
            this.#doses = 0;
            this.#hurdleRace();
        }

            #hurdleRace() {
                let highestHurdle = Math.max(...this.#hurdlesHeights)
                this.#doses = highestHurdle > this.#maximumHeightCanJump ? highestHurdle - this.#maximumHeightCanJump : 0;
            }

        doses() {
            return this.#doses;
        }
    }
