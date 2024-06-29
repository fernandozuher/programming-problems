// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

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
    readLine();
    let array: number[] = readIntArray();
    array.sort((a, b) => a - b);
    console.log(findMostSpottedBird(array));
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }
    
    function findMostSpottedBird(birdSightings: number[]): number {
        let mostSpottedBird: number = birdSightings[0];
        let countMostSpottedBird = 1;
        let tempCountMostSpottedBird = 1;
        let n = birdSightings.length;
    
        for (let i = 1; i < n; ++i) {
            if (birdSightings[i] === birdSightings[i - 1])
                ++tempCountMostSpottedBird;
            else if (tempCountMostSpottedBird > countMostSpottedBird) {
                mostSpottedBird = birdSightings[i - 1];
                countMostSpottedBird = tempCountMostSpottedBird;
                tempCountMostSpottedBird = 1;
            }
        }
    
        if (tempCountMostSpottedBird > countMostSpottedBird)
            mostSpottedBird = birdSightings[n - 1];
    
        return mostSpottedBird;
    }
