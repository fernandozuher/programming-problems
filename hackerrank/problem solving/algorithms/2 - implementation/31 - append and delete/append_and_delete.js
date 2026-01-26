// https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

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
  const s1 = readLine();
  const s2 = readLine();
  const nOps = +readLine();
  console.log(appendAndDelete(s1, s2, nOps) ? 'Yes' : 'No');
}

// n1: length of string s1
// n2: length of string s2
// T: O(min(n1, n2))
// S: O(1) extra space
function appendAndDelete(s1, s2, nOps) {
  const prefixLen = commonPrefixLength(s1, s2);
  const opsNeeded = s1.length - prefixLen + (s2.length - prefixLen);
  if (nOps < opsNeeded) return false;
  if (nOps >= s1.length + s2.length) return true;
  return (nOps - opsNeeded) % 2 === 0;
}

function commonPrefixLength(s1, s2) {
  const minLen = Math.min(s1.length, s2.length);
  for (let i = 0; i < minLen; i++) if (s1[i] !== s2[i]) return i;
  return minLen;
}
