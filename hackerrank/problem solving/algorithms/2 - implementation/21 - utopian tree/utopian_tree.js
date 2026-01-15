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

function readLine() {
  return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
  const n = +readLine();
  const utopianTree = generateHeightsUtopianTree();
  for (let i = 0; i < n; i++) {
    const cycles = +readLine();
    console.log(utopianTree[cycles]);
  }
}

// k: length of output array = 61
// T: O(k) = O(61) = O(1). S: O(61) = O(1) extra space.
function generateHeightsUtopianTree() {
  const maxCycles = 60;
  let height = 0;
  return Array(maxCycles + 1)
    .fill(0)
    .map(
      (_, cycle) =>
        (height += isCycleHappeningDuringSpring(cycle) ? height : 1),
    );
}

function isCycleHappeningDuringSpring(cycle) {
  return (cycle & 1) === 1;
}
