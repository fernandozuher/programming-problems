// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

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

function readLine() {
  return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
  const n = +readLine();
  for (let i = 0; i < n; i++) {
    const [a, b] = readLine().split(' ').map(Number);
    console.log(squares(a, b));
  }
}

function squares(startNum, endNum) {
  const minSquare = Math.ceil(Math.sqrt(startNum));
  const maxSquare = Math.floor(Math.sqrt(endNum));
  return maxSquare - minSquare + 1;
}
