// https://www.hackerrank.com/challenges/arrays-ds/problem?isFullScreen=true

function main() {
  readLine();
  readLine()
    .split(' ')
    .map((x: string) => +x)
    .reverse()
    .forEach((x: number) => process.stdout.write(x + ' '));
}

//////////////////////////////////////////////////

import readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines: string[] = [];
rl.on('line', (line: string) => inputLines.push(line));
rl.on('close', main);

function readLine(): string {
  return inputLines.shift()!;
}
