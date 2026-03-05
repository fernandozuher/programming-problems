// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

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
  readLine();
  console.log(pickingNumbers(counter()));
}

// n: length of initial input array of numbers
// T: O(n)
// S: O(n) extra space
function counter(): Map<number, number> {
  const arr: number[] = readLine().split(' ').map(Number);
  const freqMap = new Map<number, number>();
  for (const num of arr) {
    freqMap.set(num, (freqMap.get(num) || 0) + 1);
  }
  return freqMap;
}

// k: length of freqMap
// 1 <= k <= 99
// T: O(k) = O(99) = O(1)
// S: O(1) extra space
function pickingNumbers(freqMap: Map<number, number>): number {
  let maxLen = 0;
  for (const [num, _] of freqMap) {
    const current: number = freqMap.get(num) + (freqMap.get(num + 1) || 0);
    maxLen = Math.max(maxLen, current);
  }
  return maxLen;
}
