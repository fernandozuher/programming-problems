// Source: https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function(inputStdin: string): void {
    inputString += inputStdin;
});

process.stdin.on('end', function(): void {
    inputLines = inputString.split('\n');
    inputString = '';

    main();
});

function readLine(): string {
    return inputLines[currentLine++];
}


function main() {
    const N_TEST_CASES: number = +readLine();
    const OUTPUT: Array<bigint> = new Array(N_TEST_CASES).fill(BigInt(0));

    for (let i = 0; i < N_TEST_CASES; i++) {
        const INPUT: Array<bigint> = readATestCase();
        const OBJ: TaumAndBday = new TaumAndBday(INPUT);
        OUTPUT[i] = OBJ.getMinimumCostOfBuyingGifts();
    }

    printArray(OUTPUT);
}

    function readATestCase(): Array<bigint> {
        const [N_BLACK_GIFTS, N_WHITE_GIFTS]: Array<bigint> = readAnIntArray();
        const [BLACK_GIFT_COST, WHITE_GIFT_COST, COST_TO_CONVERT_BETWEEN_GIFTS]: Array<bigint> = readAnIntArray();
        return [N_BLACK_GIFTS, N_WHITE_GIFTS, BLACK_GIFT_COST, WHITE_GIFT_COST, COST_TO_CONVERT_BETWEEN_GIFTS];
    }

        function readAnIntArray(): Array<bigint> {
            return readLine().split(" ").map(BigInt);
        }

    function printArray(array: Array<bigint>) {
        array.forEach(element => console.log(element.toString()));
    }

    class TaumAndBday {
        private _nBlackGifts: bigint;
        private _nWhiteGifts: bigint;
        private _blackGiftCost: bigint;
        private _whiteGiftCost: bigint;
        private _costToConvertBetweenGifts: bigint;

        private _costToConvertFromBlackToWhite: bigint;
        private _costToConvertFromWhiteToBlack: bigint;

        private _minimumCostOfBuyingGifts: bigint;

        constructor(input: Array<bigint>) {
            [this._nBlackGifts, this._nWhiteGifts, this._blackGiftCost, this._whiteGiftCost, this._costToConvertBetweenGifts] = input;

            this._costToConvertFromBlackToWhite = this._blackGiftCost + this._costToConvertBetweenGifts;
            this._costToConvertFromWhiteToBlack = this._whiteGiftCost + this._costToConvertBetweenGifts;

            this._minimumCostOfBuyingGifts = this._calculateMinimumCostOfBuyingGifts();
        }

            _calculateMinimumCostOfBuyingGifts(): bigint {
                if (this._areOriginalCostsCheaperOrEqualThanConvertionBetweenGifts())
                    return this._calculateMinimumStandardCost();

                return this._calculateMinimumCostInConvertingGifts();
            }

                _areOriginalCostsCheaperOrEqualThanConvertionBetweenGifts(): boolean {
                    return this._whiteGiftCost <= this._costToConvertFromBlackToWhite && this._blackGiftCost <= this._costToConvertFromWhiteToBlack;
                }

                _calculateMinimumStandardCost(): bigint {
                    return this._nBlackGifts * this._blackGiftCost + this._nWhiteGifts * this._whiteGiftCost;
                }

                _calculateMinimumCostInConvertingGifts(): bigint {
                    const TOTAL_GIFTS: bigint = this._nBlackGifts + this._nWhiteGifts;

                    if (this._whiteGiftCost > this._costToConvertFromBlackToWhite)
                        return TOTAL_GIFTS * this._blackGiftCost + this._nWhiteGifts * this._costToConvertBetweenGifts;

                    return TOTAL_GIFTS * this._whiteGiftCost + this._nBlackGifts * this._costToConvertBetweenGifts;
                }

        getMinimumCostOfBuyingGifts(): bigint {
            return this._minimumCostOfBuyingGifts;
        }
    }
