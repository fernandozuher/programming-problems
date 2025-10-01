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
  console.log(minimumNumberOfJumps(readNumbers()));
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

function minimumNumberOfJumps(clouds: number[]) {
  let jumps = 0;
  for (let i = 0, n = clouds.length - 1; i < n; i += nextJump(i, clouds))
    jumps++;
  return jumps;
}

function nextJump(index: number, clouds: number[]): number {
  let isNextSecondCloudCumulus = false;
  if (index + 2 < clouds.length)
    isNextSecondCloudCumulus = clouds[index + 2] === 0;
  return isNextSecondCloudCumulus ? 2 : 1;
}
