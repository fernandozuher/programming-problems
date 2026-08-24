// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

import { max, read, readLn, skipInput } from 'morfo';

skipInput();
const maxJump = read(Number);
const hurdles = readLn(Number);
console.log(hurdleRace(hurdles, maxJump));

// n: length of hurdles
// T: O(n)
// S: O(1) extra space
function hurdleRace(hurdles, maxJump) {
  return Math.max(0, max(hurdles) - maxJump);
}
