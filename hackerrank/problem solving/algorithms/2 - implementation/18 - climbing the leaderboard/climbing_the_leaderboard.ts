// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

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
  const ranked: number[] = removeDuplicates(readNumbers());
  readLine();
  const player: number[] = readNumbers();
  for (const x of climbingLeaderboard(ranked, player)) console.log(x);
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

function removeDuplicates(numbers: number[]): number[] {
  return [...new Set(numbers)];
}

// n: length of array player and returned output array
// m: length of array ranked
// T: O(n + m)
// S: O(n) extra space
function climbingLeaderboard(ranked: number[], player: number[]): number[] {
  let i: number = ranked.length - 1;
  return player.map((score) => {
    while (i >= 0 && score >= ranked[i]) i--;
    return i + 2;
  });
}
