// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

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

////////////////////////////////////////////////

function main() {
  readLine();
  const steps: string = readLine();
  console.log(countingValleys(steps));
}

function readLine(): string {
  return inputLines[currentLine++];
}

function countingValleys(steps: string): number {
  let valleys = 0;
  let currentAltitude = 0;

  for (const step of steps) {
    const wasBelowSeaLevel: boolean = currentAltitude < 0;
    currentAltitude += step === 'D' ? -1 : 1;
    const isInSeaLevelFromValley: boolean =
      wasBelowSeaLevel && currentAltitude === 0;
    if (isInSeaLevelFromValley) valleys++;
  }

  return valleys;
}
