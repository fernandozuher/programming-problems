// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

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

interface Gifts {
  nBlackGifts: bigint;
  nWhiteGifts: bigint;
  blackGiftCost: bigint;
  whiteGiftCost: bigint;
  costToConvertBetweenGifts: bigint;
}

function main() {
  const n: number = +readLine();
  for (let i = 0; i < n; i++) {
    const testCase = readTestCase();
    console.log(minCostOfBuyingGifts(testCase).toString());
  }
}

function readTestCase(): Gifts {
  const array = readNumbers();
  array.push(...readNumbers());
  const [
    nBlackGifts,
    nWhiteGifts,
    blackGiftCost,
    whiteGiftCost,
    costToConvertBetweenGifts,
  ]: bigint[] = array;
  return {
    nBlackGifts,
    nWhiteGifts,
    blackGiftCost,
    whiteGiftCost,
    costToConvertBetweenGifts,
  };
}

function readNumbers(): bigint[] {
  return readLine().split(' ').map(BigInt);
}

function minCostOfBuyingGifts(gifts: Gifts): bigint {
  const blackCost: bigint =
    gifts.blackGiftCost < gifts.whiteGiftCost + gifts.costToConvertBetweenGifts
      ? gifts.blackGiftCost
      : gifts.whiteGiftCost + gifts.costToConvertBetweenGifts;

  const whiteCost: bigint =
    gifts.whiteGiftCost < gifts.blackGiftCost + gifts.costToConvertBetweenGifts
      ? gifts.whiteGiftCost
      : gifts.blackGiftCost + gifts.costToConvertBetweenGifts;

  return gifts.nBlackGifts * blackCost + gifts.nWhiteGifts * whiteCost;
}
