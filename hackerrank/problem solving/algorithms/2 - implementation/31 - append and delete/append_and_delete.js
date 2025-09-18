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
  const initialString = readLine();
  const finalString = readLine();
  const nOperations = +readLine();
  console.log(
    appendAndDelete(initialString, finalString, nOperations) ? 'Yes' : 'No',
  );
}

function appendAndDelete(s1, s2, nOps) {
  const prefixLen = commonPrefixLength(s1, s2);
  const totalOpsNeeded = s1.length - prefixLen + (s2.length - prefixLen);
  const canRemoveAll = nOps >= s1.length + s2.length;
  return (
    canRemoveAll ||
    (nOps >= totalOpsNeeded && (nOps - totalOpsNeeded) % 2 === 0)
  );
}

function commonPrefixLength(s1, s2) {
  const minLen = Math.min(s1.length, s2.length);
  for (let i = 0; i < minLen; i++)
    if (s1[i] !== s2[i]) return i;
  return minLen;
}
