// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

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
  const chocolateSquares = readNumbers();
  const dayMonth = readNumbers();
  console.log(birthday(chocolateSquares, dayMonth));
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function birthday(chocolateSquares, dayMonth) {
  const [day, month] = dayMonth;
  if (month > chocolateSquares.length) return 0;

  let sum = chocolateSquares.slice(0, month).reduce((a, b) => a + b, 0);
  let waysBarCanBeDivided = Number(sum === day);

  for (let i = month; i < chocolateSquares.length; i++) {
    sum += chocolateSquares[i] - chocolateSquares[i - month];
    if (sum === day) waysBarCanBeDivided++;
  }

  return waysBarCanBeDivided;
}
