// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

import { read } from 'morfo';

function main() {
  const n = read(Number);
  const utopianTree = generateHeightsUtopianTree();
  for (let i = 0; i < n; i++) {
    const cycles = read(Number);
    console.log(utopianTree[cycles]);
  }
}

// k: length of output = 61
// T: O(k) = O(61) = O(1)
// S: O(61) = O(1) extra space
function generateHeightsUtopianTree() {
  const maxCycles = 60;
  const heights = new Array(maxCycles + 1);

  for (let cycle = 0, n = maxCycles + 1, height = 0; cycle < n; cycle++) {
    height += isCycleHappeningDuringSpring(cycle) ? height : 1;
    heights[cycle] = height;
  }

  return heights;
}

function isCycleHappeningDuringSpring(cycle) {
  return (cycle & 1) === 1;
}

main();
