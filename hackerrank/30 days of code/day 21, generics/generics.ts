// https://www.hackerrank.com/challenges/30-generics/problem?isFullScreen=true

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
    let intArray = [];
    for (let n = +readLine(); n--; intArray.push(+readLine()));

    let stringArray = [];
    for (let n = +readLine(); n--; stringArray.push(readLine()));

    printArray<number>(intArray);
    printArray<string>(stringArray);
}

    function printArray<T>(array: T[]) {
        array.forEach(x => console.log(x));
    }
