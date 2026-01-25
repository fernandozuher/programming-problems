// https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

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
  console.log(factorial(n).toString());
}

// T: O(n)
// S: O(1) extra space (excluding the size of the resulting integer)
function factorial(n) {
  let res = BigInt(1);
  for (let i = BigInt(1); i <= n; i++) res *= i;
  return res;
}
