// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

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
    let n: number = +readLine();
    let array: number[] = readIntArray();
    array.sort((a, b) => a - b);

    let obj = new MigratoryBirds(array);
    console.log(obj.mostSpottedBird());
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    class MigratoryBirds {
        private birdSightings: number[];
        private nMostSpottedBird: number;

        constructor(birdSightings: number[]) {
            this.birdSightings = [...birdSightings];
            this.nMostSpottedBird = null;
            this.findMostSpottedBird();
        }

            private findMostSpottedBird() {
                this.nMostSpottedBird = this.birdSightings[0];
                let countMostSpottedBird: number = 1;
                let tempCountMostSpottedBird: number = 1;
                let n: number = this.birdSightings.length;

                for (let i = 1; i < n; ++i) {

                    if (this.birdSightings[i] === this.birdSightings[i - 1])
                        ++tempCountMostSpottedBird;
                    else if (tempCountMostSpottedBird > countMostSpottedBird) {
                        this.nMostSpottedBird = this.birdSightings[i - 1];
                        countMostSpottedBird = tempCountMostSpottedBird;
                        tempCountMostSpottedBird = 1;
                    }
                }

                if (tempCountMostSpottedBird > countMostSpottedBird) {
                    this.nMostSpottedBird = this.birdSightings[n - 1];
                }
            }

        public mostSpottedBird(): number {
            return this.nMostSpottedBird;
        }
    }
