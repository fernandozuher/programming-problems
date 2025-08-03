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

//////////////////////////////////////////////////

function main() {
  const n = +readLine();

  Array(n)
    .fill('')
    .map((_) => {
      const threshold = readNumbers()[1];
      const arrivalTimes = readNumbers();
      return angryProfessor(arrivalTimes, threshold);
    })
    .forEach((cancelled) => console.log(cancelled ? 'YES' : 'NO'));
}

function readLine() {
  return inputLines[currentLine++];
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function angryProfessor(arrivalTimes, threshold) {
  const count = arrivalTimes.filter((t) => t <= 0).length;
  return count < threshold;
}
