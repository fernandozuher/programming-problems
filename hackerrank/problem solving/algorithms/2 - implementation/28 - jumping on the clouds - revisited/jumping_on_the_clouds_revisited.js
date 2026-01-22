// https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

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
  const [_, jumpLength] = readNumbers();
  const arr = readNumbers();
  console.log(jumpingOnTheClouds(arr, jumpLength));
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

// n: length of array clouds; 2 to 25
// k (jumpLength): 1 <= k <= n
// n % k = 0
// c[i] = 0 or 1
// T: O(n) = O(25) = O(1)
// S: O(1) extra space
function jumpingOnTheClouds(clouds, jumpLength) {
  let energy = 100;
  let cloudIndex = 0;

  do {
    energy -= clouds[cloudIndex] === 0 ? 1 : 3;
    cloudIndex = (cloudIndex + jumpLength) % clouds.length;
  } while (cloudIndex !== 0);

  return energy;
}
