// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

import { max, read, readLn, skipInput } from 'morfo';

skipInput();
const maxJump: number = read(Number);
const hurdles: number[] = readLn(Number);
console.log(hurdleRace(hurdles, maxJump));

// n: length of hurdles
// T: O(n)
// S: O(1) extra space
function hurdleRace(hurdles: number[], maxJump: number): number {
  return Math.max(0, max(hurdles) - maxJump);
}
