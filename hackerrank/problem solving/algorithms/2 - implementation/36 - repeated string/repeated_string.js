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

function countInRepeatedString(inputString, letter, nCharacters) {
  const fullRepeats = Math.trunc(nCharacters / inputString.length);
  const nSubstring = nCharacters % inputString.length;
  const substring = inputString.substring(0, nSubstring);

  let quantity = count(inputString, letter);
  quantity *= fullRepeats;
  return quantity + count(substring, letter);
}

function count(inputString, letter) {
  return (inputString.match(new RegExp(letter, 'g')) || []).length;
}
