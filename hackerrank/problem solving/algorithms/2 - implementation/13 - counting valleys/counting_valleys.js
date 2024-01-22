// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

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
    let n = +readLine();
    let array = readLine();
    let obj = new CountValleys(array);
    console.log(obj.traversedValleys());
}

    class CountValleys {
        #steps;
        #traversedValleys;

        constructor(steps) {
            this.#steps = steps;
            this.#traversedValleys = 0;
            this.#countingValleys();
        }

            #countingValleys() {
                let currentAltitude = 0;
                for (const step of this.#steps) {
                    let wasTravessingAValley = currentAltitude < 0;
                    currentAltitude += step === 'D' ? -1 : 1;

                    if (this.#isInSeaLevelFromValley(wasTravessingAValley, currentAltitude))
                        ++this.#traversedValleys;
                }
            }

                #isInSeaLevelFromValley(wasTravessingAValley, currentAltitude) {
                    return wasTravessingAValley && !currentAltitude;
                }

        traversedValleys() {
            return this.#traversedValleys;
        }
    }
