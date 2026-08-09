// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

import { read } from 'morfo';

const n = read(Number);
const nRotation = read(Number);
const nQueries = read(Number);
const arr = read(n, Number);
for (const q of queries(arr, nRotation, nQueries)) console.log(q);

// T: O(nQueries)
// S: O(1) extra space
function* queries(arr, nRotation, nQueries) {
  const offset = nRotation % arr.length;
  for (let i = 0; i < nQueries; i++) {
    const query = read(Number);
    yield arr.at(query - offset);
  }
}
