// https://www.hackerrank.com/challenges/30-arrays/problem?isFullScreen=true

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

function main() {
  readLine(); // Ignore not used n
  let array: number[] = readLine().split(' ').map(Number);
  // From ES2023. Not set in the 'lib' compiler option to 'es2023' in HackerRank
  // array.findLast(x => { process.stdout.write(`${x} `);});
  for (let i = array.length; i--; )
    process.stdout.write(`${array[i]} `);
}
