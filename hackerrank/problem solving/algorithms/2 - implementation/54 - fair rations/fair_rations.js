// https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true

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
  const peopleLoafCounts = readNumbers();
  const minLoaves = minLoavesToSatisfyRules(peopleLoafCounts);
  console.log(minLoaves === -1 ? 'NO' : minLoaves);
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function minLoavesToSatisfyRules(peopleLoafCounts) {
  let loavesGiven = 0;
  let counts = peopleLoafCounts[0];

  for (let i = 1; i < peopleLoafCounts.length; i++)
    if (isOdd(counts)) {
      loavesGiven += 2;
      counts = peopleLoafCounts[i] + 1;
    } else counts = peopleLoafCounts[i];

  return isOdd(counts) ? -1 : loavesGiven;
}

function isOdd(n) {
  return (n & 1) === 1;
}
