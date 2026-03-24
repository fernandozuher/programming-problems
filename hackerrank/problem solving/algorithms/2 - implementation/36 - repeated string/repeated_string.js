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
  const str = readLine();
  const nChars = +readLine();
  const letter = 'a';
  console.log(countInRepeatedString(str, letter, nChars));
}

// n: length of str
// T: O(n)
// S: O(1) extra space
function countInRepeatedString(str, letter, nChars) {
  const fullRepeats = Math.trunc(nChars / str.length);
  const nSubstr = nChars % str.length;

  let count = countChar(str, str.length, letter);
  count *= fullRepeats;
  return count + countChar(str, nSubstr, letter);
}

function countChar(str, n, letter) {
  let count = 0;
  for (let i = 0; i < n; i++) if (str[i] === letter) count++;
  return count;
}
