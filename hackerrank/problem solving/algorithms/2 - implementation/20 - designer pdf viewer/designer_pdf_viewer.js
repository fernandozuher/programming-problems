// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function (inputStdin) {
  inputString += inputStdin;
});

process.stdin.on('end', function () {
  inputLines = inputString.split('\n');
  inputString = '';
  main();
});

//////////////////////////////////////////////////

function main() {
  const lettersHeights = readNumbers();
  const word = readLine();
  console.log(designerPdfViewer(lettersHeights, word));
}

function readLine() {
  return inputLines[currentLine++];
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function designerPdfViewer(lettersHeights, word) {
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
