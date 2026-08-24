// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

import { idiv, read } from 'morfo';

const [n, page] = read(Number, Number);
console.log(pageCount(n, page));

// T: O(1)
// S: O(1) extra space
function pageCount(n, page) {
  const fromFront = idiv(page, 2);
  const fromBack = idiv(n, 2) - fromFront;
  return Math.min(fromFront, fromBack);
}
