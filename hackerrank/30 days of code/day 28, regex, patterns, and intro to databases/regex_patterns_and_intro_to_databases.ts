// https://www.hackerrank.com/challenges/30-regex-patterns/problem?isFullScreen=true

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

function main() {
  const n: number = +readLine();
  const names: string[] = collectGmailUsers(n);
  names.sort();
  console.log(names.join('\n'));
}

function readLine(): string {
  return inputLines[currentLine++];
}

function collectGmailUsers(n: number): string[] {
  const names: string[] = [];

  while (n--) {
    const [name, email] = readLine().split(' ');
    if (email.endsWith('@gmail.com'))
      names.push(name);
  }

  return names;
}
