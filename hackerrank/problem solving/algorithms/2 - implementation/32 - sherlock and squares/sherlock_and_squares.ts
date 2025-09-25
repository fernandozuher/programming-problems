// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

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
  const n = +readLine();
  for (let i = 0; i < n; i++) {
    const [a, b]: number[] = readLine().split(' ').map(Number);
    console.log(squares(a, b));
  }
}

function squares(startNum: number, endNum: number): number {
  const minSquare: number = Math.ceil(Math.sqrt(startNum));
  const maxSquare: number = Math.floor(Math.sqrt(endNum));
  return maxSquare - minSquare + 1;
}
