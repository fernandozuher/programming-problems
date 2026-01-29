// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

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
  arr.sort((a, b) => a - b);
  for (const x of cutTheSticks(arr)) console.log(x);
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

// n: length of arr
// k: number of distinct values in arr
// T: O(n)
//    Sorting arr before calling this function is O(n log n)
// S: O(k), but O(n) in the worst case extra space
//    Sorting arr before calling this function is O(n) extra space
function cutTheSticks(arr: number[]): number[] {
  const res: number[] = [];
  let slow = 0;
  const n: number = arr.length;

  for (let fast = 0; fast < n; fast++) {
    if (arr[slow] === arr[fast]) continue;
    res.push(n - slow);
    slow = fast;
  }

  res.push(n - slow);
  return res;
}
