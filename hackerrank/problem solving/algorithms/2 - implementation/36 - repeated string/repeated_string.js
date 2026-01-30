// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

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
  const inputString = readLine();
  const nCharacters = +readLine();
  const letter = 'a';
  console.log(countInRepeatedString(inputString, letter, nCharacters));
}

// n: length of string
// T: O(n)
// S: O(1) extra space
function countInRepeatedString(inputString, letter, nCharacters) {
  const fullRepeats = Math.trunc(nCharacters / inputString.length);
  const nSubstring = nCharacters % inputString.length;

  let count = countChar(inputString, inputString.length, letter);
  count *= fullRepeats;
  return count + countChar(inputString, nSubstring, letter);
}

function countChar(inputString, n, letter) {
  let count = 0;
  for (let i = 0; i < n; i++) {
    if (inputString[i] === letter) count++;
  }
  return count;
}
