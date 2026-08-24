// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

import { read } from 'morfo';

interface Gifts {
  nBlackGifts: bigint;
  nWhiteGifts: bigint;
  blackGiftCost: bigint;
  whiteGiftCost: bigint;
  costToConvertBetweenGifts: bigint;
}

const n: number = read(Number);
for (let i = 0; i < n; i++)
  console.log(minCostOfBuyingGifts(readTestCase()).toString());

function readTestCase(): Gifts {
  const [
    nBlackGifts,
    nWhiteGifts,
    blackGiftCost,
    whiteGiftCost,
    costToConvertBetweenGifts,
  ]: [bigint, bigint, bigint, bigint, bigint] = read(
    BigInt,
    BigInt,
    BigInt,
    BigInt,
    BigInt,
  );

  return {
    nBlackGifts,
    nWhiteGifts,
    blackGiftCost,
    whiteGiftCost,
    costToConvertBetweenGifts,
  };
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
