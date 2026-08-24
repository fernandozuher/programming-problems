// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

import { read } from 'morfo';

const [n, nRotation, nQueries]: [number, number, number] = read(
  Number,
  Number,
  Number,
);
const arr: number[] = read(n, Number);
for (const q of queries(arr, nRotation, nQueries)) console.log(q);

// T: O(nQueries)
// S: O(1) extra space
function* queries(
  arr: number[],
  nRotation: number,
  nQueries: number,
): Generator<number | undefined> {
  const offset: number = nRotation % arr.length;
  for (let i = 0; i < nQueries; i++) {
    const query = read(Number);
    yield arr.at(query - offset);
  }
}
