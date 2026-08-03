// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true&is_full_screen=true

function main() {
  const n = +readLine();
  for (let i = 0; i < n; i++) console.log(findNearestCatOrNot(readNums()));
}

function readNums() {
  return readLine().split(' ').map(Number);
}

// T: O(1)
// S: O(1) extra space
function findNearestCatOrNot(positions) {
  const [catA, catB, mouse] = positions;
  const catAFromMouse = Math.abs(catA - mouse);
  const catBFromMouse = Math.abs(catB - mouse);

  if (catAFromMouse < catBFromMouse) return 'Cat A';
  if (catAFromMouse > catBFromMouse) return 'Cat B';
  return 'Mouse C';
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
