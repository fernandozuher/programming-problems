// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

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
  console.log(minDeletionsToEqualize(readNumbers()));
}

function readNumbers(): number[] {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length of arr, 1 <= n <= 100
// k: number of distinct elements in arr
// k <= n
// T: O(n) = O(100) = O(1)
// S: O(k) = O(n) = O(100) = O(1) extra space
function minDeletionsToEqualize(arr: number[]): number {
  let maxCount = 0;
  const freqMap = counter(arr);
  for (const key in freqMap) maxCount = Math.max(maxCount, freqMap[key]);
  return arr.length - maxCount;
}

function counter(arr: number[]): Record<number, number> {
  let freqMap: Record<number, number> = {};
  arr.forEach((x) => {
    freqMap[x] = (freqMap[x] ?? 0) + 1;
  });
  return freqMap;
}
