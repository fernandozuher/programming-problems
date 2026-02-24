// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

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
  const birdsToCounts = readInput();
  console.log(findMostSpottedBird(birdsToCounts));
}

// n: length of input
// T: O(n)
// S: O(n) extra space
function readInput() {
  readLine();
  const freqMap = new Map();

  readLine()
    .split(' ')
    .forEach((x) => {
      x = +x;
      freqMap.set(x, (freqMap.get(x) ?? 0) + 1);
    });

  return freqMap;
}

// n: length of birdsToCounts
// T: O(n)
// S: O(1) extra space
function findMostSpottedBird(birdsToCounts) {
  let resID = 0,
    resCount = 0;

  for (const [id, count] of birdsToCounts)
    if (count > resCount || (count === resCount && id < resID)) {
      resID = id;
      resCount = count;
    }

  return resID;
}
