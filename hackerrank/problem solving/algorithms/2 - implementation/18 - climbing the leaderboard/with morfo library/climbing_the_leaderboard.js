// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

import { println, readLn, skipInputLn } from 'morfo';

skipInputLn();
const ranked = removeDuplicates(readLn(Number));
skipInputLn();
const player = readLn(Number);
println(climbingLeaderboard(ranked, player));

// n: length of arr
// k: length of distinct numbers in arr
// k <= n
// T: O(n)
// S: O(k) extra space
function removeDuplicates(numbers) {
  return [...new Set(numbers)];
}

// n1: length of player, output
// n2: length of ranked
// T: O(n1 + n2)
// S: O(1) extra space
function climbingLeaderboard(ranked, player) {
  let i = ranked.length - 1;
  return player.values().map((score) => {
    while (i >= 0 && score >= ranked[i]) i--;
    return i + 2;
  });
}
