// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

function main() {
    const tripletA: number[] = readInput();
    const tripletB: number[] = readInput();
    const [scoreA, scoreB]: number[] = compareTriplets(tripletA, tripletB);
    console.log(scoreA, scoreB);
}

function readInput(): number[] {
    return readLine()
        .split(' ')
        .map((x) => +x);
}

// n: length of a and b = 3
// T: O(3) = O(1)
// S: O(1) extra space
function compareTriplets(tripletA: number[], tripletB: number[]): number[] {
    let [scoreA, scoreB]: number[] = [0, 0];

    for (let i = 0; i < tripletA.length; i++)
        if (tripletA[i] > tripletB[i]) scoreA++;
        else if (tripletB[i] > tripletA[i]) scoreB++;

    return [scoreA, scoreB];
}

//////////////////////////////////////////////////

import readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines: string[] = [];
rl.on('line', (line: string) => inputLines.push(line));
rl.on('close', main);

function readLine(): string {
    return inputLines.shift()!;
}
