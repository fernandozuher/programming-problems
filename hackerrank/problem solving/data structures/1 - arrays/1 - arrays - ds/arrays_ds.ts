// https://www.hackerrank.com/challenges/arrays-ds/problem?isFullScreen=true

function main() {
  readLine();
  readLine()
    .split(' ')
    .reverse()
    .values()
    .map((x: string) => +x)
    .forEach((x: number) => process.stdout.write(x + ' '));
}

//////////////////////////////////////////////////

import readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
const inputLines: string[] = [];
rl.on('line', (line: string) => inputLines.push(line));
rl.on('close', main);

function readLine(): string {
  return inputLines.shift()!;
}
