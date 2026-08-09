// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

import { read } from 'morfo';

const n = read(Number);
for (let i = 0; i < n; i++)
  console.log(minCostOfBuyingGifts(readTestCase()).toString());

function readTestCase() {
  const nBlackGifts = read(BigInt);
  const nWhiteGifts = read(BigInt);
  const blackGiftCost = read(BigInt);
  const whiteGiftCost = read(BigInt);
  const costToConvertBetweenGifts = read(BigInt);

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
