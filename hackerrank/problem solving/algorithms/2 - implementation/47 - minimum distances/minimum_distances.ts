// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

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
  const arr: number[] = readNumbers();
  console.log(minDistance(arr));
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

// n: length of array arr
// T: O(n)
// S: O(n) extra space
function minDistance(arr: number[]): number {
  const lastSeen: { [key: number]: number } = {};
  let minDist = -1;

  for (let i = 0; i < arr.length; i++) {
    const x = arr[i];

    if (lastSeen.hasOwnProperty(x)) {
      const dist = i - lastSeen[x];

      if (minDist === -1 || dist < minDist) {
        minDist = dist;
        if (minDist === 1) return 1;
      }
    }

    lastSeen[x] = i;
  }

  return minDist;
}
