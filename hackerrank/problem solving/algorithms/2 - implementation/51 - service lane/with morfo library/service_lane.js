// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

import { min, readLn } from 'morfo';

const t = readLn(Number)[1];
const widths = readLn(Number);
for (let i = 0; i < t; i++)
  console.log(minWidthInSegment(widths, readLn(Number)));

// n: length of widths
// T: O(n)
// S: O(1) extra space
function minWidthInSegment(widths, segment) {
  const [start, finish] = segment;
  return min(widths.slice(start, finish + 1));
}
