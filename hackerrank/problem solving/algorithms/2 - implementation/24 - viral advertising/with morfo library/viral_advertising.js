// https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

import { idiv, read } from 'morfo';

const days = read(Number);
console.log(viralAdvertising(days));

// n: days
// T: O(n)
// S: O(1) extra space
function viralAdvertising(days) {
  let acc = 0;
  for (let shared = 5; days > 0; days--) {
    const liked = idiv(shared, 2);
    shared = liked * 3;
    acc += liked;
  }
  return acc;
}
