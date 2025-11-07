// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

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

////////////////////////////////////////////////

function main() {
  const maxJump: number = readNumbers()[1];
  const hurdles: number[] = readNumbers();
  console.log(hurdleRace(hurdles, maxJump));
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

function hurdleRace(hurdles: number[], maxJump: number): number {
  return Math.max(0, Math.max(...hurdles) - maxJump);
}
