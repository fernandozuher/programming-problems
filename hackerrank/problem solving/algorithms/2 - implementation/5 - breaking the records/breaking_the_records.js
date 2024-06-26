// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function (inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function () {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine() {
    return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
    +readLine();
    let array = readIntArray();
    let [mostPointsRecords, leastPointsRecords] = breakingRecords(array);
    console.log(`${mostPointsRecords} ${leastPointsRecords}`);
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    function breakingRecords(scores) {
        let mostPoints = scores[0], leastPoints = scores[0];
        let breakingMostPointsRecords = 0, breakingLeastPointsRecords = 0;

        for (const score of scores)
            if (score > mostPoints) {
                mostPoints = score;
                ++breakingMostPointsRecords;
            } else if (score < leastPoints) {
                leastPoints = score;
                ++breakingLeastPointsRecords;
            }

        return [breakingMostPointsRecords, breakingLeastPointsRecords];
    }
