// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

function main() {
  const lettersHeights = readNumbers();
  const word = readLine();
  console.log(designerPdfViewer(lettersHeights, word));
}

function readNumbers() {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length word, <= 10
// T: O(10) = O(1)
// S: O(1) extra space
function designerPdfViewer(lettersHeights, word) {
  let maxHeight = 0;
  for (const ch of word) maxHeight = Math.max(maxHeight, lettersHeights[ch.charCodeAt(0) - 'a'.charCodeAt(0)]);
  return maxHeight * word.length;
}

////////////////////////////////////////////////

const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines = [];
rl.on('line', (line) => inputLines.push(line));
rl.on('close', main);

function readLine() {
  return inputLines.shift();
}
