// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

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
  utopianTree(readNumbers(n)).forEach((x) => console.log(x));
}

function readLine() {
  return inputLines[currentLine++];
}

function readNumbers(n) {
  return Array(n)
    .fill(0)
    .map((_) => +readLine());
}

function utopianTree(testCases) {
  return testCases.map(calculateHeight);
}

function calculateHeight(cycles) {
  let height = 1;
  for (let cycle = 1; cycle <= cycles; cycle++)
    height = isCycleHappeningDuringSpring(cycle) ? height * 2 : height + 1;
  return height;
}

function isCycleHappeningDuringSpring(cycle) {
  return cycle & 1;
}
