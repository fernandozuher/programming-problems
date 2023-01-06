// Source: https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

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
    readLineAsNumberArray();
    const steps: string = readLineAsString();

    const result = new Result(steps);
}

    function readLineAsNumberArray() {
        const inputLine: number[] = readLine().split(" ").map(Number);
        return inputLine;
    }

    function readLineAsString() {
        const inputLine = readLine();
        return inputLine;
    }

    class Result {
        private _steps: string;
        private _traversedValleys: number;

        constructor(steps: string) {
            this._steps = steps;
            this._traversedValleys = 0;

            this._countingValleys();
            this.printResult();
        }

            private _countingValleys() {
                let currentAltitude: number = 0;

                for (let step of this._steps) {
                    const wasTravessingAValley: boolean = currentAltitude < 0;
                    currentAltitude += step === 'D' ? -1 : 1;
                    
                    if (this._isInSeaLevelFromValley(wasTravessingAValley, currentAltitude))
                        this._traversedValleys++;
                }
            }

                private _isInSeaLevelFromValley(wasTravessingAValley: boolean, currentAltitude: number) {
                    return wasTravessingAValley && !currentAltitude;
                }

        
            printResult() {
                console.log(this._traversedValleys);
            }
    }
