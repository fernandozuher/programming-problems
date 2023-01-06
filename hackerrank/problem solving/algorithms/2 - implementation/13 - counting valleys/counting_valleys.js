// Source: https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

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
    readLineAsNumberArray();
    const steps = readLineAsString();

    const result = new Result(steps);
}

    function readLineAsNumberArray() {
        const inputLine = readLine().split(" ").map(Number);
        return inputLine;
    }

    function readLineAsString() {
        const inputLine = readLine();
        return inputLine;
    }

    class Result {
        #steps;
        #traversedValleys;

        constructor(steps) {
            this.#steps = [...steps];
            this.#traversedValleys = 0;

            this.#countingValleys();
            this.printResult();
        }

            #countingValleys() {
                let currentAltitude = 0;

                for (let step of this.#steps) {
                    const wasTravessingAValley = currentAltitude < 0;
                    currentAltitude += step === 'D' ? -1 : 1;
                    
                    if (this.#isInSeaLevelFromValley(wasTravessingAValley, currentAltitude))
                        this.#traversedValleys++;
                }
            }

                #isInSeaLevelFromValley(wasTravessingAValley, currentAltitude) {
                    return wasTravessingAValley && !currentAltitude;
                }
        
            printResult() {
                console.log(this.#traversedValleys);
            }
    }
