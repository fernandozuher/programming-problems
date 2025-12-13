// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function (inputStdin) {
  inputString += inputStdin;
});

process.stdin.on('end', function () {
  inputLines = inputString.split('\n');
  inputString = '';
  main();
});

function readLine() {
  return inputLines[currentLine++];
}

//////////////////////////////////////////////////

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
