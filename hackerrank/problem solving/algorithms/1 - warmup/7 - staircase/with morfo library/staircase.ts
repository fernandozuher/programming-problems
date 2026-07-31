// https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

import { read } from 'morfo';

const n: number = read(Number);
staircase(n);

// T: O(n^2)
// S: O(n) extra space
function staircase(n: number) {
  for (let i = 1; i <= n; i++) {
    const spaces = ' '.repeat(n - i);
    const hashes = '#'.repeat(i);
    console.log(spaces + hashes);
  }
}
