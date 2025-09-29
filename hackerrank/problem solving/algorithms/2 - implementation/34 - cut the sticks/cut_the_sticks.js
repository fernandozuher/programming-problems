// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

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
  const arr = readNumbers();
  arr.sort((a, b) => a - b);
  cutTheSticks(arr).forEach((x) => console.log(x));
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function cutTheSticks(arr) {
  const res = [];
  for (let i = 0, n = arr.length; i < n; ) {
    res.push(n - i);
    for (const shortest = arr[i]; i < n && arr[i] === shortest; i++);
  }
  return res;
}
