// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

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
  const sockCounts: Map<number, number> = counter();
  console.log(sockMerchant(sockCounts));
}

function counter(): Map<number, number> {
  const counter = new Map<number, number>();
  readLine()
    .split(' ')
    .forEach((s) => {
      const x = Number(s);
      counter.set(x, (counter.get(x) || 0) + 1);
    });
  return counter;
}

// n: quantity of entries in sockCounts
// T: O(n)
// S: O(1) extra space
function sockMerchant(sockCounts: Map<number, number>): number {
  let pairs = 0;
  sockCounts.forEach((count) => {
    pairs += Math.trunc(count / 2);
  });
  return pairs;
}
