// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

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
  readLine();
  console.log(minJumps(readNumbers()));
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

// n: length of array clouds
// T: O(n)
// S: O(1) extra space
function minJumps(clouds) {
  let jumps = 0;
  for (let i = 0, n = clouds.length - 1; i < n; i += skip(i, clouds), jumps++);
  return jumps;
}

function skip(idx, clouds) {
  return isNextSecondCloudCumulus(idx, clouds) ? 2 : 1;
}

function isNextSecondCloudCumulus(idx, clouds) {
  return idx + 2 < clouds.length && clouds[idx + 2] === 0;
}
