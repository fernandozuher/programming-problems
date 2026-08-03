// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

function main() {
  const lettersHeights: number[] = readNums();
  const word: string = readLine();
  console.log(designerPdfViewer(lettersHeights, word));
}

function readNums(): number[] {
  return readLine().split(' ').map(Number);
}

// n: length word, <= 10
// T: O(10) = O(1)
// S: O(1) extra space
function designerPdfViewer(lettersHeights: number[], word: string): number {
  let maxHeight = 0;
  for (const ch of word) maxHeight = Math.max(maxHeight, lettersHeights[ch.charCodeAt(0) - 'a'.charCodeAt(0)]);
  return maxHeight * word.length;
}

//////////////////////////////////////////////////

import readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
const inputLines: string[] = [];
rl.on('line', (line: string) => inputLines.push(line));
rl.on('close', main);

function readLine(): string {
  return inputLines.shift()!;
}
