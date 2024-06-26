// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function (inputStdin: string): void {
    inputString += inputStdin;
});

process.stdin.on('end', function (): void {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine(): string {
    return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
    +readLine();
    let array: number[] = readIntArray();
    let [mostPointsRecords, leastPointsRecords]: number[] = breakingRecords(array);
    console.log(`${mostPointsRecords} ${leastPointsRecords}`);
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }
    
    function breakingRecords(scores: number[]): number[] {
        let mostPoints: number = scores[0];
        let leastPoints: number = scores[0];
        let breakingMostPointsRecords: number = 0;
        let breakingLeastPointsRecords: number = 0;
    
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
