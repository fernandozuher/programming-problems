// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function (inputStdin: string): void {
  inputString += inputStdin;
});

process.stdin.on('end', function (): void {
  inputLines = inputString.split('\n');
  inputString = '';
  main();
});

function readLine(): string {
  return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
  const lettersHeights: number[] = readNumbers();
  const word: string = readLine();
  console.log(designerPdfViewer(lettersHeights, word));
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

// n_w: length of string word, no more than 10 letters
// T = O(10) = O(1)
// S = O(1) extra space
function designerPdfViewer(lettersHeights: number[], word: string): number {
  let maxHeight = 0;
  for (const ch of word) {
    const height = lettersHeights[ch.charCodeAt(0) - 'a'.charCodeAt(0)];
    maxHeight = Math.max(maxHeight, height);
  }
  return maxHeight * word.length;
}
