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
  const [_, nPoints]: number[] = readNumbers();
  const widths = readNumbers();
  for (let i = 0; i < nPoints; i++)
    console.log(maxAffordableWidthVehicleInRange(widths, readNumbers()));
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

function maxAffordableWidthVehicleInRange(
  widths: number[],
  point: number[],
): number {
  return Math.min(...widths.slice(point[0], point[1] + 1));
}
