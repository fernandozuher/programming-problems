// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

function main() {
  const tripletA = readNums();
  const tripletB = readNums();
  const [scoreA, scoreB] = computeTripletScores(tripletA, tripletB);
  console.log(scoreA, scoreB);
}

function readNums() {
  return readLine().split(' ').map(Number);
}

// n: length of a and b = 3
// T: O(3) => O(1)
// S: O(1) extra space
function computeTripletScores(tripletA, tripletB) {
  let [scoreA, scoreB] = [0, 0];

  for (let i = 0; i < tripletA.length; i++) {
    if (tripletA[i] > tripletB[i]) scoreA++;
    else if (tripletB[i] > tripletA[i]) scoreB++;
  }

  return [scoreA, scoreB];
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
