// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

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
    +readLine();
    let array = readIntArray();
    let records = new BreakingBestAndWorstRecords(array);
    console.log(`${records.mostPointsRecords()} ${records.leastPointsRecords()}`);
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    class BreakingBestAndWorstRecords {
        #scores;
        #breakingMostPointsRecords;
        #breakingLeastPointsRecords;

        constructor(array) {
            this.#scores = [...array];
            this.#breakingMostPointsRecords = 0;
            this.#breakingLeastPointsRecords = 0;
            this.#breakingRecords();
        }

            #breakingRecords() {
                let mostPoints = this.#scores[0];
                let leastPoints = this.#scores[0];

                for (const score of this.#scores)
                    if (score > mostPoints) {
                        mostPoints = score;
                        ++this.#breakingMostPointsRecords;
                    } else if (score < leastPoints) {
                        leastPoints = score;
                        ++this.#breakingLeastPointsRecords;
                    }
            }
        
        mostPointsRecords() {
            return this.#breakingMostPointsRecords;
        }

        leastPointsRecords() {
            return this.#breakingLeastPointsRecords;
        }
    }
