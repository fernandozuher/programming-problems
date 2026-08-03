// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

function main() {
  for (let i = 0, n = +readLine(); i < n; i++) {
    const threshold = readNums()[1];
    const arrivalTimes = readNums();
    console.log(angryProfessor(arrivalTimes, threshold) ? 'YES' : 'NO');
  }
}

function readNums() {
  return readLine().split(' ').map(Number);
}

// k: length of arrivalTimes
// T: O(k)
// S: O(1) extra space
function angryProfessor(arrivalTimes, threshold) {
  const onTime = arrivalTimes.reduce(
    (count, t) => (t <= 0 ? count + 1 : count),
    0,
  );
  return onTime < threshold;
}

////////////////////////////////////////////////

const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
const inputLines = [];
rl.on('line', (line) => inputLines.push(line));
rl.on('close', main);

function readLine() {
  return inputLines.shift();
}
