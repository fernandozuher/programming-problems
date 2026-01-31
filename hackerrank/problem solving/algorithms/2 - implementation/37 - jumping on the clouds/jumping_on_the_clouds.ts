// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

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
  readLine();
  console.log(minJumps(readNumbers()));
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

// n: length of array clouds
// T: O(n)
// S: O(1) extra space
function minJumps(clouds: number[]) {
  let jumps = 0;
  for (let i = 0, n = clouds.length - 1; i < n; i += skip(i, clouds), jumps++);
  return jumps;
}

function skip(idx: number, clouds: number[]): number {
  return isNextSecondCloudCumulus(idx, clouds) ? 2 : 1;
}

function isNextSecondCloudCumulus(idx: number, clouds: number[]): boolean {
  return idx + 2 < clouds.length && clouds[idx + 2] === 0;
}
