// https://www.hackerrank.com/challenges/30-generics/problem?isFullScreen=true

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
  let numbers: number[] = readInput<number>(x => +x);
  let strings: string[] = readInput<string>(x => x);
  printArray(numbers);
  printArray(strings);
}

function readInput<T>(converter: (value: string) => T): T[] {
  const n = +readLine();
  let a: T[] = [];
  for (let i = 0; i < n; i++) {
    a.push(converter(readLine()));
  }
  return a;
}

function printArray<T>(a: T[]) {
  console.log(a.join('\n'));
}
