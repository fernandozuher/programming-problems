// Source: https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');
    main();
});

function readLine() {
    return inputString[currentLine++];
}

function main() {
    const N_TEST_CASES = +readLine();
    const OUTPUT = new Array(N_TEST_CASES).fill(BigInt(0));

    for (let i = 0; i < N_TEST_CASES; i++) {
        const INPUT = readATestCase();
        const OBJ = new TaumAndBday(INPUT);
        OUTPUT[i] = OBJ.getMinimumCostOfBuyingGifts();
    }

    printArray(OUTPUT);
}

    function readATestCase() {
        const [N_BLACK_GIFTS, N_WHITE_GIFTS] = readAnIntArray();
        const [BLACK_GIFT_COST, WHITE_GIFT_COST, COST_TO_CONVERT_BETWEEN_GIFTS] = readAnIntArray();
        return [N_BLACK_GIFTS, N_WHITE_GIFTS, BLACK_GIFT_COST, WHITE_GIFT_COST, COST_TO_CONVERT_BETWEEN_GIFTS];
    }

        function readAnIntArray() {
            return readLine().split(" ").map(BigInt);
        }

    function printArray(array) {
        array.forEach(element => console.log(element.toString()));
    }

    class TaumAndBday {
        #nBlackGifts;
        #nWhiteGifts;
        #blackGiftCost;
        #whiteGiftCost;
        #costToConvertBetweenGifts;

        #costToConvertFromBlackToWhite;
        #costToConvertFromWhiteToBlack;

        #minimumCostOfBuyingGifts;

        constructor(input) {
            [this.#nBlackGifts, this.#nWhiteGifts, this.#blackGiftCost, this.#whiteGiftCost, this.#costToConvertBetweenGifts] = input;

            this.#costToConvertFromBlackToWhite = this.#blackGiftCost + this.#costToConvertBetweenGifts;
            this.#costToConvertFromWhiteToBlack = this.#whiteGiftCost + this.#costToConvertBetweenGifts;

            this.#minimumCostOfBuyingGifts = this.#calculateMinimumCostOfBuyingGifts();
        }

            #calculateMinimumCostOfBuyingGifts() {
                if (this.#areOriginalCostsCheaperOrEqualThanConvertionBetweenGifts())
                    return this.#calculateMinimumStandardCost();

                return this.#calculateMinimumCostInConvertingGifts();
            }

                #areOriginalCostsCheaperOrEqualThanConvertionBetweenGifts() {
                    return this.#whiteGiftCost <= this.#costToConvertFromBlackToWhite && this.#blackGiftCost <= this.#costToConvertFromWhiteToBlack;
                }

                #calculateMinimumStandardCost() {
                    return BigInt(this.#nBlackGifts * this.#blackGiftCost + this.#nWhiteGifts * this.#whiteGiftCost);
                }

                #calculateMinimumCostInConvertingGifts() {
                    const TOTAL_GIFTS = this.#nBlackGifts + this.#nWhiteGifts;

                    if (this.#whiteGiftCost > this.#costToConvertFromBlackToWhite)
                        return BigInt(TOTAL_GIFTS * this.#blackGiftCost + this.#nWhiteGifts * this.#costToConvertBetweenGifts);

                    return BigInt(TOTAL_GIFTS * this.#whiteGiftCost + this.#nBlackGifts * this.#costToConvertBetweenGifts);
                }

        getMinimumCostOfBuyingGifts() {
            return this.#minimumCostOfBuyingGifts;
        }
    }
