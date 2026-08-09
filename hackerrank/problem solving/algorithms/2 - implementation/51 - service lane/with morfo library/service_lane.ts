// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

import { readLn } from 'morfo';

function main() {
  const t: number = readLn(Number)[1];
  const widths: number[] = readLn(Number);
  for (let i = 0; i < t; i++)
    console.log(minWidthInSegment(widths, readLn(Number)));
}

// n: length of widths
// T: O(n)
// S: O(1) extra space
function minWidthInSegment(widths: number[], segment: number[]): number {
  const [start, finish]: number[] = segment;
  let minEl: number = widths[start];
  for (let i = start; i <= finish; ++i) minEl = Math.min(minEl, widths[i]);
  return minEl;
}

main();
