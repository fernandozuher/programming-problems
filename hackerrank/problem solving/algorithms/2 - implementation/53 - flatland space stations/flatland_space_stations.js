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
  let stations = readNumbers().sort((a, b) => a - b);
  console.log(maxDistanceFromSpaceStation(nCities, stations));
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function maxDistanceFromSpaceStation(nCities, stations) {
  let maxDist = stations[0];

  for (let i = 1; i < stations.length; i++) {
    const gap = Math.trunc((stations[i] - stations[i - 1]) / 2);
    maxDist = Math.max(maxDist, gap);
  }

  const lastCity = nCities - 1;
  return Math.max(maxDist, lastCity - stations[stations.length - 1]);
}
