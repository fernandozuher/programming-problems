// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

function main() {
  const n = +readLine();
  for (let i = 0; i < n; i++)
    console.log(minCostOfBuyingGifts(readTestCase()).toString());
}

function readTestCase() {
  const arr = readNumbers();
  arr.push(...readNumbers());
  const [
    nBlackGifts,
    nWhiteGifts,
    blackGiftCost,
    whiteGiftCost,
    costToConvertBetweenGifts,
  ] = arr;

  return {
    nBlackGifts,
    nWhiteGifts,
    blackGiftCost,
    whiteGiftCost,
    costToConvertBetweenGifts,
  };
}

function readNumbers() {
  return readLine().split(' ').map(BigInt);
}

// T: O(1)
// S: O(1) extra space
function minCostOfBuyingGifts(x) {
  const blackCost =
    x.blackGiftCost < x.whiteGiftCost + x.costToConvertBetweenGifts
      ? x.blackGiftCost
      : x.whiteGiftCost + x.costToConvertBetweenGifts;

  const whiteCost =
    x.whiteGiftCost < x.blackGiftCost + x.costToConvertBetweenGifts
      ? x.whiteGiftCost
      : x.blackGiftCost + x.costToConvertBetweenGifts;

  return x.nBlackGifts * blackCost + x.nWhiteGifts * whiteCost;
}

////////////////////////////////////////////////

const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines = [];
rl.on('line', (line) => inputLines.push(line));
rl.on('close', main);

function readLine() {
  return inputLines.shift();
}
