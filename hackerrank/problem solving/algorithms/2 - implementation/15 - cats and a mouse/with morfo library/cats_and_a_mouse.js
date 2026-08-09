// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true&is_full_screen=true

import { read, readLn } from 'morfo';

const n = read(Number);
for (let i = 0; i < n; i++) console.log(findNearestCatOrNot(readLn(Number)));

// T: O(1)
// S: O(1) extra space
function findNearestCatOrNot(positions) {
  const [catA, catB, mouse] = positions;
  const catAFromMouse = Math.abs(catA - mouse);
  const catBFromMouse = Math.abs(catB - mouse);

  if (catAFromMouse < catBFromMouse) return 'Cat A';
  if (catAFromMouse > catBFromMouse) return 'Cat B';
  return 'Mouse C';
}
