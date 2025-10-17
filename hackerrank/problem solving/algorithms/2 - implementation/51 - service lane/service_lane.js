// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

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
  const [_, nPoints] = readNumbers();
  const widths = readNumbers();
  for (let i = 0; i < nPoints; i++)
    console.log(maxAffordableWidthVehicleInRange(widths, readNumbers()));
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function maxAffordableWidthVehicleInRange(widths, point) {
  return Math.min(...widths.slice(point[0], point[1] + 1));
}
