// Source: https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

'use strict';
const fs = require('fs');
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
    const birdSightings = readLineAsNumberArray();

    birdSightings.sort((a, b) => a - b);

    const result = new Result(birdSightings);
}

    function readLineAsNumberArray() {
        const numbers = readLine().split(" ").map(Number);
        return numbers;
    }

    class Result {
        #birdSightings;
        #mostSpottedBird;

        constructor(birdSightings) {
            this.#birdSightings = [...birdSightings];
            this.#mostSpottedBird = null;

            this.#migratoryBirds();
            this.printResult();
        }

            #migratoryBirds() {
                this.#mostSpottedBird = this.#birdSightings[0];
                let countMostSpottedBird = 1;
                let tempCountMostSpottedBird = 1;

                const n = this.#birdSightings.length;
                for (let i = 1; i < n; i++) {

                    if (this.#birdSightings[i] === this.#birdSightings[i - 1])
                        tempCountMostSpottedBird++;
                    
                    else if (tempCountMostSpottedBird > countMostSpottedBird) {
                        this.#mostSpottedBird = this.#birdSightings[i - 1];
                        countMostSpottedBird = tempCountMostSpottedBird;
                        tempCountMostSpottedBird = 1;
                    }
                }

                if (tempCountMostSpottedBird > countMostSpottedBird) {
                    this.#mostSpottedBird = this.#birdSightings[n - 1];
                }
            }
        
            printResult() {
                console.log(this.#mostSpottedBird);
            }
    }
