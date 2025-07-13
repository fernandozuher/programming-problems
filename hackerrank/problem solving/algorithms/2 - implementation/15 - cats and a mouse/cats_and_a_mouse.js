// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true&is_full_screen=true

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

////////////////////////////////////////////////

function main() {
  const n = +readLine();
  Array.from({ length: n }, () => findNearestCatOrNot(readNumbers())).forEach(
    (x) => console.log(x),
  );
}

function readLine() {
  return inputLines[currentLine++];
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function findNearestCatOrNot(positions) {
  const [catA, catB, mouse] = positions;
  const catAFromMouse = Math.abs(catA - mouse);
  const catBFromMouse = Math.abs(catB - mouse);

  if (catAFromMouse < catBFromMouse) return 'Cat A';
  if (catAFromMouse > catBFromMouse) return 'Cat B';
  return 'Mouse C';
}
