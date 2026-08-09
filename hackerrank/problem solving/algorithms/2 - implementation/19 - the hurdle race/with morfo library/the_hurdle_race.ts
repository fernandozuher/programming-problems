// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

import { read, readLn, skipInput } from 'morfo';

function main() {
  skipInput();
  const maxJump: number = read(Number);
  const hurdles: number[] = readLn(Number);
  console.log(hurdleRace(hurdles, maxJump));
}

// n: length of hurdles
// T: O(n)
// S: O(1) extra space
function hurdleRace(hurdles: number[], maxJump: number): number {
  return Math.max(0, Math.max(...hurdles) - maxJump);
}

main();
