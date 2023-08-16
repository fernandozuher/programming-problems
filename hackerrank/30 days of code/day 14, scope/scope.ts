// https://www.hackerrank.com/challenges/30-scope/problem?isFullScreen=true

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

function main() {
    const N: number = +readLine(); // Not used
    const ARRAY: number[] = readLine().split(" ").map(Number);
    
    const DIFFERENCE = new Difference(ARRAY);
    DIFFERENCE.computeDifference();
    console.log(DIFFERENCE.maximumDifference);
}

    class Difference {
        #elements: number[];
        maximumDifference: number;

        constructor(elements: number[]) {
            this.#elements = elements;
        }

        computeDifference() {
            this.#elements.sort((a, b) => a - b);
            this.maximumDifference = this.#elements[this.#elements.length - 1] - this.#elements[0];
        }
    }
