// https://www.hackerrank.com/challenges/30-exceptions-string-to-integer/problem?isFullScreen=true

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
  let s: string = readLine();
  try {
    let error = () => { throw 'Bad String'; };
    let num: number = parseInt(s) ? parseInt(s) : error();
    console.log(num);
  } catch (e) {
    console.log(e);
  }
}
