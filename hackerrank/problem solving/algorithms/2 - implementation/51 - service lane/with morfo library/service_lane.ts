// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

import { min, readLn } from 'morfo';

const t: number = readLn(Number)[1];
const widths: number[] = readLn(Number);
for (let i = 0; i < t; i++)
  console.log(minWidthInSegment(widths, readLn(Number)));

// n: length of widths
// T: O(n)
// S: O(1) extra space
function minWidthInSegment(widths: number[], segment: number[]): number {
  const [start, finish]: number[] = segment;
  return min(widths.slice(start, finish! + 1));
}
