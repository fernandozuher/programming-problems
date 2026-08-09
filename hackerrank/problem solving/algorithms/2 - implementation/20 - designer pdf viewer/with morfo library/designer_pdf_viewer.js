// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

import { read } from 'morfo';

function main() {
  const lettersHeights = read(26, Number);
  const word = read(String);
  console.log(designerPdfViewer(lettersHeights, word));
}

// n: length word, <= 10
// T: O(10) = O(1)
// S: O(1) extra space
function designerPdfViewer(lettersHeights, word) {
  let maxHeight = 0;
  for (const ch of word) maxHeight = Math.max(maxHeight, lettersHeights[ch.charCodeAt(0) - 'a'.charCodeAt(0)]);
  return maxHeight * word.length;
}

main();
