// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

import { skipInputLn, readLn, println } from 'morfo';

skipInputLn();
const arr = readLn(Number);
println(sequenceEquation(arr));

// n: length of arr
// T: O(n)
// S: O(n) extra space
function* sequenceEquation(arr) {
  const valuesToIndex = Array(arr.length).fill(0);
  let i = 0;
  for (const val of arr) valuesToIndex[val - 1] = i++;
  for (const val of valuesToIndex) yield valuesToIndex[val] + 1;
}
