// https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

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
  const n: number = +readLine();
  const matrix: string[][] = readMatrix(n);
  changeMatrixToCavityMap(matrix);
  for (const x of matrix)
    console.log(x.join(''));
}

function readMatrix(n: number): string[][] {
  return Array(n)
    .fill('0')
    .map((_) => readLine().split(''));
}

function changeMatrixToCavityMap(matrix: string[][]) {
  for (let i = 1, n = matrix.length - 1; i < n; i++)
    for (let j = 1; j < n; j++)
      if (isCellCavity(matrix, i, j)) matrix[i][j] = 'X';
}

function isCellCavity(matrix: string[][], i: number, j: number): boolean {
  return (
    matrix[i - 1][j] < matrix[i][j] &&
    matrix[i][j - 1] < matrix[i][j] &&
    matrix[i + 1][j] < matrix[i][j] &&
    matrix[i][j + 1] < matrix[i][j]
  );
}
