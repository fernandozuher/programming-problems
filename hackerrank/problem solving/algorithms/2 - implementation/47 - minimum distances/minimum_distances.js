// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

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
  console.log(minDistance(arr));
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function minDistance(arr) {
  const lastSeen = {};
  let minDist = -1;

  for (let i = 0; i < arr.length; i++) {
    const x = arr[i];

    if (lastSeen.hasOwnProperty(x)) {
      const dist = i - lastSeen[x];
      if (minDist === -1 || dist < minDist) {
        minDist = dist;
        if (minDist === 1) return 1;
      }
    }
    lastSeen[x] = i;
  }

  return minDist;
}
