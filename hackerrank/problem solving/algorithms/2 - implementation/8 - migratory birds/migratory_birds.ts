// Source: https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

'use strict';

import { WriteStream, createWriteStream } from "fs";
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
    readLineAsNumberArray();
    const birdSightings: number[] = readLineAsNumberArray();

    birdSightings.sort((a, b) => a - b);

    const result = new Result(birdSightings);
}

    function readLineAsNumberArray(): number[] {
        const numbers: number[] = readLine().split(" ").map(Number);
        return numbers;
    }

    class Result {
        private _birdSightings: number[];
        private _mostSpottedBird: number;

        constructor(birdSightings: number[]) {
            this._birdSightings = [...birdSightings];
            this._mostSpottedBird = null;

            this._migratoryBirds();
            this.printResult();
        }

            private _migratoryBirds() {
                this._mostSpottedBird = this._birdSightings[0];
                let countMostSpottedBird = 1;
                let tempCountMostSpottedBird = 1;

                const n = this._birdSightings.length;
                for (let i = 1; i < n; i++) {

                    if (this._birdSightings[i] === this._birdSightings[i - 1])
                        tempCountMostSpottedBird++;
                    
                    else if (tempCountMostSpottedBird > countMostSpottedBird) {
                        this._mostSpottedBird = this._birdSightings[i - 1];
                        countMostSpottedBird = tempCountMostSpottedBird;
                        tempCountMostSpottedBird = 1;
                    }
                }

                if (tempCountMostSpottedBird > countMostSpottedBird) {
                    this._mostSpottedBird = this._birdSightings[n - 1];
                }
            }
        
            printResult() {
                console.log(this._mostSpottedBird);
            }
    }
