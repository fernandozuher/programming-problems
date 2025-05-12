// https://www.hackerrank.com/challenges/30-regex-patterns/problem?isFullScreen=true

'use strict';
process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function (inputStdin) {
  inputString += inputStdin;
});

process.stdin.on('end', function () {
  inputLines = inputString.split('\n');
  inputString = '';
  main();
});

//////////////////////////////////////////////////

function main() {
  const n = +readLine();
  const names = collectGmailUsers(n);
  names.sort();
  console.log(names.join('\n'));
}

function readLine() {
  return inputLines[currentLine++];
}

function collectGmailUsers(n) {
  const names = [];

  while (n--) {
    const [name, email] = readLine().split(' ');
    if (email.endsWith('@gmail.com'))
      names.push(name);
  }

  return names;
}
