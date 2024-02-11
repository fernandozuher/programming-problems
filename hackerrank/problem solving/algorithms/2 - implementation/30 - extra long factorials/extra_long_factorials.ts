// https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

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
    let number: number = +readLine();
    let factorial: bigint = calculateFactorialOf(number);
    console.log(factorial.toString());
}

    function calculateFactorialOf(number: number): bigint {
        let factorial: bigint = BigInt(1);
        for (let currentNumber = BigInt(2); currentNumber <= number; ++currentNumber)
            factorial *= currentNumber;
        return factorial;
    }
