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
  const socksToCounts: Map<number, number> = counter();
  console.log(sockMerchant(socksToCounts));
}

// n: length of user input
// k: length of distinct numbers in user input
// T: O(n)
// S: O(n) extra space
function counter(): Map<number, number> {
  const freqMap = new Map<number, number>();
  readLine()
    .split(' ')
    .forEach((s) => {
      const x = Number(s);
      freqMap.set(x, (freqMap.get(x) || 0) + 1);
    });
  return freqMap;
}

// n: length of initial user input
// k: length of entries in socksToCounts
// k <= n
// T: O(k)
// S: O(1) extra space
function sockMerchant(socksToCounts: Map<number, number>): number {
  let pairs = 0;
  socksToCounts.forEach((x) => {
    pairs += Math.trunc(x / 2);
  });
  return pairs;
}
