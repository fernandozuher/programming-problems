// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

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
  const [_, t]: number[] = readNumbers();
  const widths = readNumbers();
  for (let i = 0; i < t; i++)
    console.log(minWidthInSegment(widths, readNumbers()));
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

function minWidthInSegment(
  widths: number[],
  segment: number[],
): number {
  return Math.min(...widths.slice(segment[0], segment[1] + 1));
}
