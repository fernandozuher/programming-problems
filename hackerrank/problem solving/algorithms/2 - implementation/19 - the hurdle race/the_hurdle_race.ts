// Source: https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function(inputStdin: string): void {
    inputString += inputStdin;
});

process.stdin.on('end', function(): void {
    inputLines = inputString.split('\n');
    inputString = '';

    main();
});

function readLine(): string {
    return inputLines[currentLine++];
}


function main() {
    const inputLine: number[] = readLineAsNumberArray();
    const maximumHeightCanJump: number = inputLine[1]

    const hurdlesHeights: number[] = readLineAsNumberArray()

    const result = new Result(hurdlesHeights, maximumHeightCanJump);
}

function readLineAsNumberArray() {
    const inputLine = readLine().split(" ").map(Number);
    return inputLine;
}

    class Result {
        private _hurdlesHeights: number[];
        private _maximumHeightCanJump: number;
        private _doses: number;

        constructor(hurdlesHeights: number[], maximumHeightCanJump: number) {
            this._hurdlesHeights = [...hurdlesHeights];
            this._maximumHeightCanJump = maximumHeightCanJump;
            this._doses = 0;

            this._hurdleRace();
            this.printResult();
        }

            private _hurdleRace() {
                const highestHurdle: number = Math.max(...this._hurdlesHeights)
                this._doses = highestHurdle > this._maximumHeightCanJump ? highestHurdle - this._maximumHeightCanJump : 0;
            }

            public printResult() {
                console.log(this._doses);
            }
    }
