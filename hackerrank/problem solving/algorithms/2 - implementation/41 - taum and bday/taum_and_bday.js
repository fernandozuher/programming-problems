// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

'use strict';

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
    let n = +readLine();
    let output = new Array(n).fill(BigInt(0)).map(_ =>{
        let obj = new TaumAndBday(readTestCase());
        obj.calculateMinimumCostOfBuyingGifts();
        return obj.minimumCostOfBuyingGifts();
    });

    output.forEach(x => console.log(x.toString()));
}

    function readTestCase() {
        let array = readIntArray();
        array.push(...readIntArray());
        const [nBlackGifts, nWhiteGifts, blackGiftCost, whiteGiftCost, costToConvertBetweenGifts] = array;
        return {nBlackGifts, nWhiteGifts, blackGiftCost, whiteGiftCost, costToConvertBetweenGifts};
    }

        function readIntArray() {
            return readLine().split(' ').map(BigInt);
        }

    class TaumAndBday {
        #gifts;
        #costToConvertFromBlackToWhite;
        #costToConvertFromWhiteToBlack;
        #minimumCostOfBuyingGifts;

        constructor(gifts) {
            this.#gifts = gifts;
            this.#costToConvertFromBlackToWhite = this.#gifts.blackGiftCost + this.#gifts.costToConvertBetweenGifts;
            this.#costToConvertFromWhiteToBlack = this.#gifts.whiteGiftCost + this.#gifts.costToConvertBetweenGifts;
        }

        calculateMinimumCostOfBuyingGifts() {
            this.#minimumCostOfBuyingGifts = this.#areOriginalCostsCheaperOrEqualThanConversionBetweenGifts() ?
                this.#calculateMinimumStandardCost() : this.#calculateMinimumCostInConvertingGifts();
        }

            #areOriginalCostsCheaperOrEqualThanConversionBetweenGifts() {
                return this.#gifts.whiteGiftCost <= this.#costToConvertFromBlackToWhite
                    && this.#gifts.blackGiftCost <= this.#costToConvertFromWhiteToBlack;
            }

            #calculateMinimumStandardCost() {
                return this.#gifts.nBlackGifts * this.#gifts.blackGiftCost + this.#gifts.nWhiteGifts * this.#gifts.whiteGiftCost;
            }

            #calculateMinimumCostInConvertingGifts() {
                let totalGifts = this.#gifts.nBlackGifts + this.#gifts.nWhiteGifts;
                if (this.#gifts.whiteGiftCost > this.#costToConvertFromBlackToWhite)
                    return totalGifts * this.#gifts.blackGiftCost + this.#gifts.nWhiteGifts * this.#gifts.costToConvertBetweenGifts;
                return totalGifts * this.#gifts.whiteGiftCost + this.#gifts.nBlackGifts * this.#gifts.costToConvertBetweenGifts;
            }
    
        minimumCostOfBuyingGifts() {
            return this.#minimumCostOfBuyingGifts;
        }
    }
