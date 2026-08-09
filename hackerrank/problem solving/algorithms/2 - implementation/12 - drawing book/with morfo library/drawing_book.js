// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

import { read } from 'morfo';

function main() {
  const n = read(Number);
  const page = read(Number);
  console.log(pageCount(n, page));
}

// T: O(1)
// S: O(1) extra space
function pageCount(n, page) {
  const fromFront = Math.trunc(page / 2);
  const fromBack = Math.trunc(n / 2) - fromFront;
  return Math.min(fromFront, fromBack);
}

main();
