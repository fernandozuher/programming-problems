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
  for (let i = 0; i < n; i++)
    console.log(minCostOfBuyingGifts(readTestCase()).toString());
}

function readTestCase(): Gifts {
  const arr: bigint[] = readNumbers();
  for (const x of readNumbers()) arr.push(x);
  return {
    nBlackGifts: arr[0],
    nWhiteGifts: arr[1],
    blackGiftCost: arr[2],
    whiteGiftCost: arr[3],
    costToConvertBetweenGifts: arr[4],
  };
}

function readNumbers(): bigint[] {
  return readLine().split(' ').map(BigInt);
}

// T: O(1)
// S: O(1) extra space
function minCostOfBuyingGifts(x: Gifts): bigint {
  const blackCost: bigint =
    x.blackGiftCost < x.whiteGiftCost + x.costToConvertBetweenGifts
      ? x.blackGiftCost
      : x.whiteGiftCost + x.costToConvertBetweenGifts;

  const whiteCost: bigint =
    x.whiteGiftCost < x.blackGiftCost + x.costToConvertBetweenGifts
      ? x.whiteGiftCost
      : x.blackGiftCost + x.costToConvertBetweenGifts;

  return x.nBlackGifts * blackCost + x.nWhiteGifts * whiteCost;
}
