// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

import { max, read } from 'morfo';

const lettersHeights = read(26, Number);
const word = read(String);
console.log(designerPdfViewer(lettersHeights, word));

// n: length word, <= 10
// T: O(10) = O(1)
// S: O(1) extra space
function designerPdfViewer(lettersHeights, word) {
  const maxHeight = max(
    Array.from(
      word,
      (ch) => lettersHeights[ch.charCodeAt(0) - 'a'.charCodeAt(0)],
    ),
  );
  return maxHeight * word.length;
}
