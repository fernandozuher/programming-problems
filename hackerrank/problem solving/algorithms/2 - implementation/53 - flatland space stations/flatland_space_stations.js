// https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

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
  const [nCities, _] = readNumbers();
  const lastCity = nCities - 1;
  let stations = readNumbers().sort((a, b) => a - b);
  console.log(maxDistanceFromSpaceStation(lastCity, stations));
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

// n: length of array stations
// T: O(n)
// S: O(1) extra space
function maxDistanceFromSpaceStation(lastCity, stations) {
  let maxDist = stations[0];

  for (let i = 1; i < stations.length; i++) {
    const gap = Math.trunc((stations[i] - stations[i - 1]) / 2);
    maxDist = Math.max(maxDist, gap);
  }

  return Math.max(maxDist, lastCity - stations.at(-1));
}
