// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

function main() {
  readLine();
  const ranked: number[] = removeDuplicates(readNums());
  readLine();
  const player: number[] = readNums();
  for (const x of climbingLeaderboard(ranked, player)) console.log(x);
}

function readNums(): number[] {
  return readLine().split(' ').map(Number);
}

// n: length of arr
// k: length of distinct numbers in arr
// k <= n
// T: O(n)
// S: O(k) extra space
function removeDuplicates(numbers: number[]): number[] {
  return [...new Set(numbers)];
}

// n1: length of player, output
// n2: length of ranked
// T: O(n1 + n2)
// S: O(n1) extra space
function climbingLeaderboard(ranked: number[], player: number[]): number[] {
  let i: number = ranked.length - 1;
  return player.map((score) => {
    while (i >= 0 && score >= ranked[i]) i--;
    return i + 2;
  });
}

//////////////////////////////////////////////////

import readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
const inputLines: string[] = [];
rl.on('line', (line: string) => inputLines.push(line));
rl.on('close', main);

function readLine(): string {
  return inputLines.shift()!;
}
