// https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

import { readLn } from 'morfo';

const [nCities, _] = readLn(Number);
const lastCity = nCities - 1;
let stations = readLn(Number).sort((a, b) => a - b);
console.log(maxDistanceFromSpaceStation(lastCity, stations));

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
