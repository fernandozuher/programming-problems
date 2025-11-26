// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

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
  const positionsAndVelocities: number[] = readNumbers();
  console.log(kangaroo(positionsAndVelocities) ? 'YES' : 'NO');
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

function kangaroo(positionsAndVelocities: number[]): boolean {
  const [x1, v1, x2, v2]: number[] = [...positionsAndVelocities];

  if (v1 === v2) return x1 === x2;

  const distanceDiff = x2 - x1;
  const velocityDiff = v1 - v2;
  return distanceDiff * velocityDiff >= 0 && distanceDiff % velocityDiff === 0;
}
