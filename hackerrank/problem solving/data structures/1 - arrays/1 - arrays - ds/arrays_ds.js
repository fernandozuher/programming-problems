// https://www.hackerrank.com/challenges/arrays-ds/problem?isFullScreen=true

function main() {
  readLine();
  readLine()
    .split(' ')
    .map((x) => +x)
    .reverse()
    .forEach((x) => process.stdout.write(x + ' '));
}

////////////////////////////////////////////////

const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines = [];
rl.on('line', (line) => inputLines.push(line));
rl.on('close', main);

function readLine() {
  return inputLines.shift();
}
