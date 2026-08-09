// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

import { readLn } from 'morfo';

function main() {
  const t = readLn(Number)[1];
  const widths = readLn(Number);
  for (let i = 0; i < t; i++)
    console.log(minWidthInSegment(widths, readLn(Number)));
}

// n: length of widths
// T: O(n)
// S: O(1) extra space
function minWidthInSegment(widths, segment) {
  const [start, finish] = segment;
  let minEl = widths[start];
  for (let i = start; i <= finish; ++i) minEl = Math.min(minEl, widths[i]);
  return minEl;
}

main();
