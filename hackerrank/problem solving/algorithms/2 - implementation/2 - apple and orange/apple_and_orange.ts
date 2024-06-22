// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

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
    let input: AppleAndOrange = readInput();
    countApplesAndOranges(input);
}

class AppleAndOrange {
    public startingSam: number;
    public endingSam: number;
    public appleTreeLocation: number;
    public orangeTreeLocation: number;
    public applesDistanceFromTree: number[];
    public orangesDistanceFromTree: number[];
}

function readInput(): AppleAndOrange {
    let input: AppleAndOrange = new AppleAndOrange();
    [input.startingSam, input.endingSam] = readIntArray();
    [input.appleTreeLocation, input.orangeTreeLocation] = readIntArray();
    readLine(); // Discard sizes of arrays
    input.applesDistanceFromTree = readIntArray();
    input.orangesDistanceFromTree = readIntArray();
    return input;
}

function readIntArray(): number[] {
    return readLine().split(' ').map(Number);
}

function countApplesAndOranges(input: AppleAndOrange) {
    let applesOnHouse: number = countFruitsOnHouse(input, 'apple');
    let orangesOnHouse: number = countFruitsOnHouse(input, 'orange');
    console.log(`${applesOnHouse}\n${orangesOnHouse}`);
}

function countFruitsOnHouse(input: AppleAndOrange, fruit: string) {
    let [treeLocation, fruits]: any[] = filterInput(input, fruit);
    return fruits.filter(partialLocation => {
        let location: number = treeLocation + partialLocation;
        return location >= input.startingSam && location <= input.endingSam;
    }).length;
}

function filterInput(input: AppleAndOrange, fruit: string): any[] {
    return fruit === 'apple' ?
        [input.appleTreeLocation, input.applesDistanceFromTree]
        : [input.orangeTreeLocation, input.orangesDistanceFromTree];
}
