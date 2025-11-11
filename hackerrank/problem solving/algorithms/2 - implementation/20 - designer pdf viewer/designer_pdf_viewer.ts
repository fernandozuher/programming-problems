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

function designerPdfViewer(lettersHeights: number[], word: string): number {
  const maxHeight = [...word].reduce(
    (maxHeight, letter) =>
      Math.max(
        maxHeight,
        lettersHeights[letter.charCodeAt(0) - 'a'.charCodeAt(0)],
      ),
    0,
  );
  return maxHeight * word.length;
}
