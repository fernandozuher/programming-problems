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
  for (let i = 0; i < n; i++) {
    const testCase = readTestCase();
    console.log(minCostOfBuyingGifts(testCase).toString());
  }
}

function readTestCase() {
  const array = readNumbers();
  array.push(...readNumbers());
  const [
    nBlackGifts,
    nWhiteGifts,
    blackGiftCost,
    whiteGiftCost,
    costToConvertBetweenGifts,
  ] = array;
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

function minCostOfBuyingGifts(gifts) {
  const blackCost =
    gifts.blackGiftCost < gifts.whiteGiftCost + gifts.costToConvertBetweenGifts
      ? gifts.blackGiftCost
      : gifts.whiteGiftCost + gifts.costToConvertBetweenGifts;

  const whiteCost =
    gifts.whiteGiftCost < gifts.blackGiftCost + gifts.costToConvertBetweenGifts
      ? gifts.whiteGiftCost
      : gifts.blackGiftCost + gifts.costToConvertBetweenGifts;

  return gifts.nBlackGifts * blackCost + gifts.nWhiteGifts * whiteCost;
}
