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

function counter(): Map<number, number> {
  const arr: number[] = readLine().split(' ').map(Number);
  const frequency = new Map<number, number>();
  for (const num of arr) {
    frequency.set(num, (frequency.get(num) || 0) + 1);
  }
  return frequency;
}

// n: length of initial input array of numbers
// k: length of map frequency
// T:
//   Without constraining the input values:
//       In the worst case, length of map equals length of initial input array when there is no repeated element: k = n
//       O(n)
//   With input values limited to 1 through 99, as stated in the problem:
//       Max of 99 keys/values at map: O(99) = O(1)
// S: O(1) extra space
function pickingNumbers(frequency: Map<number, number>): number {
  let maxLen = 0;
  for (const [num, _] of frequency) {
    const current: number = frequency.get(num) + (frequency.get(num + 1) || 0);
    maxLen = Math.max(maxLen, current);
  }
  return maxLen;
}
