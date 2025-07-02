// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

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

//////////////////////////////////////////////////

const TRANSITION_YEAR: number = 1918;

function main() {
    let year: number = +readLine();
    console.log(calculateDateOf256thDay(year));
}

function readLine(): string {
    return inputLines[currentLine++];
}

function calculateDateOf256thDay(year: number): string {
    let day;
    if (year === TRANSITION_YEAR) day = '26';
    else day = isLeapYear(year) ? '12' : '13';
    return day + '.09.' + year.toString();
}

function isLeapYear(year: number): boolean {
    if (year < TRANSITION_YEAR)
      return isLeapJulianYear(year);
    if (year > TRANSITION_YEAR)
      return isLeapGregorianYear(year);
    return false;
}

function isLeapJulianYear(year: number): boolean {
    return year % 4 === 0;
}

function isLeapGregorianYear(year: number): boolean {
    return year % 400 === 0 || (year % 4 === 0 && year % 100 !== 0);
}
