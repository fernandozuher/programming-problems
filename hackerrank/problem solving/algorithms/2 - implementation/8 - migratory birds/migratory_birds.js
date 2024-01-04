// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

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

function main() {
    let n = +readLine();
    let array = readIntArray();
    array.sort((a, b) => a - b);

    let obj = new MigratoryBirds(array);
    console.log(obj.mostSpottedBird());
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    class MigratoryBirds {
        #birdSightings;
        #mostSpottedBird;

        constructor(birdSightings) {
            this.#birdSightings = [...birdSightings];
            this.#mostSpottedBird = null;
            this.#findMostSpottedBird();
        }

            #findMostSpottedBird() {
                this.#mostSpottedBird = this.#birdSightings[0];
                let countMostSpottedBird = 1;
                let tempCountMostSpottedBird = 1;
                let n = this.#birdSightings.length;

                for (let i = 1; i < n; ++i) {

                    if (this.#birdSightings[i] === this.#birdSightings[i - 1])
                        ++tempCountMostSpottedBird;
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

        mostSpottedBird() {
            return this.#mostSpottedBird;
        }
    }
