// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

function main() {
  readLine();
  console.log(minJumps(readNumbers()));
}

function readNumbers() {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length of clouds
// T: O(n)
// S: O(1) extra space
function minJumps(clouds) {
  let jumps = 0;
  for (let i = 0, n = clouds.length - 1; i < n; i += skip(i, clouds)) jumps++;
  return jumps;
}

function skip(idx, clouds) {
  return isNextSecondCloudCumulus(idx, clouds) ? 2 : 1;
}

function isNextSecondCloudCumulus(idx, clouds) {
  return idx + 2 < clouds.length && clouds[idx + 2] === 0;
}

////////////////////////////////////////////////

const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines = [];
rl.on('line', (line) => inputLines.push(line));
rl.on('close', main);

function readLine() {
  return inputLines.shift();
}
