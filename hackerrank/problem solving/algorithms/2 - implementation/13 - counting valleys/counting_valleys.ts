// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

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

////////////////////////////////////////////////

function main() {
    let n: number = +readLine();
    let array: string = readLine();
    let obj = new CountValleys(array);
    console.log(obj.traversedValleys());
}

    class CountValleys {
        private steps: string;
        private nTraversedValleys: number;

        constructor(steps: string) {
            this.steps = steps;
            this.nTraversedValleys = 0;
            this.countingValleys();
        }

            private countingValleys() {
                let currentAltitude: number = 0;

                for (const step of this.steps) {
                    let wasTravessingAValley: boolean = currentAltitude < 0;
                    currentAltitude += step === 'D' ? -1 : 1;

                    if (this.isInSeaLevelFromValley(wasTravessingAValley, currentAltitude))
                        ++this.nTraversedValleys;
                }
            }

                private isInSeaLevelFromValley(wasTravessingAValley: boolean, currentAltitude: number): boolean {
                    return wasTravessingAValley && !currentAltitude;
                }

            public traversedValleys(): number {
                return this.nTraversedValleys;
            }
    }
