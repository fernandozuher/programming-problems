// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

import { println, readLn, skipInputLn } from 'morfo';

function main() {
  skipInputLn();
  const ranked: number[] = removeDuplicates(readLn(Number));
  skipInputLn();
  const player: number[] = readLn(Number);
  println(climbingLeaderboard(ranked, player));
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

main();
