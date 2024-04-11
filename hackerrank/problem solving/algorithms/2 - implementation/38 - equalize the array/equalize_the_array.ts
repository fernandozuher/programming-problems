// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function(inputStdin: string): void {
    inputString += inputStdin;
});

process.stdin.on('end', function(): void {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine(): string {
    return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
    let n: number = +readLine();
    let array: number[] = readLine().split(' ').map(Number);
    let frequency: {[key: number]: number} = {};
    array.forEach(x => {frequency[x] = (frequency[x] ?? 0) + 1;});
    console.log(equalizeArray(frequency, n));
}

    function equalizeArray(map: {[key: number]: number}, n: number): number {
        let maximumQuantityOfEqualElement: number = Math.max(...Object.values(map));
        let minimumNumberRequiredDeletions: number = n - maximumQuantityOfEqualElement;
        return minimumNumberRequiredDeletions;
    }
