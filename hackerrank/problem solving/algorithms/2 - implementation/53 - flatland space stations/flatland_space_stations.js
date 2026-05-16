// https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

function main() {
  const [nCities, _] = readNumbers();
  const lastCity = nCities - 1;
  let stations = readNumbers().sort((a, b) => a - b);
  console.log(maxDistanceFromSpaceStation(lastCity, stations));
}

function readNumbers() {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length of stations
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

////////////////////////////////////////////////

const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines = [];
rl.on('line', (line) => inputLines.push(line));
rl.on('close', main);

function readLine() {
  return inputLines.shift();
}
