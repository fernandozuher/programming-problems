// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

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
    const threshold = readNumbers()[1];
    const arrivalTimes = readNumbers();
    console.log(angryProfessor(arrivalTimes, threshold) ? 'YES' : 'NO');
  }
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

// k: length of array arrivalTimes
// T: O(k)
// S: O(1) extra space
function angryProfessor(arrivalTimes, threshold) {
  const onTime = arrivalTimes.reduce(
    (count, t) => (t <= 0 ? count + 1 : count),
    0,
  );
  return onTime < threshold;
}
