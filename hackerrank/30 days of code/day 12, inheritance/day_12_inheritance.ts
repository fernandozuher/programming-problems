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

function calculate(testScores: Array<number>): string {

    const avg = testScores.reduce( ( p, c ) => p + c, 0 ) / testScores.length;

    if (avg >= 90 && avg <= 100)
        return 'O'
    else if (avg >= 80 && avg < 90)
        return 'E'
    else if (avg >= 70 && avg < 80)
        return 'A'
    else if (avg >= 55 && avg < 70)
        return 'P'
    else if (avg >= 40 && avg < 55)
        return 'D'
    else
        return 'T'
}

function main() {
    let line = readLine().split(" ")
    console.log(`Name: ${line[1]}, ${line[0]}`)
    console.log(`ID: ${line[2]}`)
    readLine()
    const numberArray = readLine().split(" ").map(Number)
    console.log(`Grade: ${calculate(numberArray)}`)
}