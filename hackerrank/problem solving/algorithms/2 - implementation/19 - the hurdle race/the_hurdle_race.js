// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

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

////////////////////////////////////////////////

function main() {
  const maxJump = readNumbers()[1];
  const hurdles = readNumbers();
  console.log(hurdleRace(hurdles, maxJump));
}

function readLine() {
  return inputLines[currentLine++];
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function hurdleRace(hurdles, maxJump) {
  return Math.max(0, Math.max(...hurdles) - maxJump);
}
