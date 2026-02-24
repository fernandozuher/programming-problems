// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

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
  const birdsToCounts: Map<number, number> = readInput();
  console.log(findMostSpottedBird(birdsToCounts));
}

// n: length of input
// T: O(n)
// S: O(n) extra space
function readInput(): Map<number, number> {
  readLine();
  const freqMap = new Map<number, number>();

  readLine()
    .split(' ')
    .forEach((x: any) => {
      x = +x;
      freqMap.set(x, (freqMap.get(x) ?? 0) + 1);
    });

  return freqMap;
}

// n: length of birdsToCounts
// T: O(n)
// S: O(1) extra space
function findMostSpottedBird(birdsToCounts: Map<number, number>): number {
  let resID = 0,
    resCount = 0;

  for (const [id, count] of birdsToCounts)
    if (count > resCount || (count === resCount && id < resID)) {
      resID = id;
      resCount = count;
    }

  return resID;
}
