// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

'use strict';

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

interface gifts {
    nBlackGifts: bigint,
    nWhiteGifts: bigint,
    blackGiftCost: bigint,
    whiteGiftCost: bigint,
    costToConvertBetweenGifts: bigint
};

function main() {
    let n: number = +readLine();
    let output: bigint[] = new Array(n).fill(BigInt(0)).map(_ => {
        let obj = new TaumAndBday(readTestCase());
        obj.calculateMinimumCostOfBuyingGifts();
        return obj.minimumCostOfBuyingGifts();
    });

    output.forEach(x => console.log(x.toString()));
}

    function readTestCase(): gifts {
        let array = readIntArray();
        array.push(...readIntArray());
        const [nBlackGifts, nWhiteGifts, blackGiftCost, whiteGiftCost, costToConvertBetweenGifts]: bigint[] = array;
        return {nBlackGifts, nWhiteGifts, blackGiftCost, whiteGiftCost, costToConvertBetweenGifts};
    }
    
        function readIntArray(): bigint[] {
            return readLine().split(' ').map(BigInt);
        }

    class TaumAndBday {
        private gifts_data: gifts;
        private costToConvertFromBlackToWhite: bigint;
        private costToConvertFromWhiteToBlack: bigint;
        private minCostOfBuyingGifts: bigint;
    
        constructor(x: gifts) {
            this.gifts_data = x;
            this.costToConvertFromBlackToWhite = this.gifts_data.blackGiftCost + this.gifts_data.costToConvertBetweenGifts;
            this.costToConvertFromWhiteToBlack = this.gifts_data.whiteGiftCost + this.gifts_data.costToConvertBetweenGifts;
        }
    
        calculateMinimumCostOfBuyingGifts() {
            this.minCostOfBuyingGifts = this.areOriginalCostsCheaperOrEqualThanConversionBetweenGifts() ?
                this.calculateMinimumStandardCost() : this.calculateMinimumCostInConvertingGifts();
        }
    
            areOriginalCostsCheaperOrEqualThanConversionBetweenGifts(): boolean {
                return this.gifts_data.whiteGiftCost <= this.costToConvertFromBlackToWhite
                    && this.gifts_data.blackGiftCost <= this.costToConvertFromWhiteToBlack;
            }
        
            calculateMinimumStandardCost(): bigint {
                return this.gifts_data.nBlackGifts * this.gifts_data.blackGiftCost + this.gifts_data.nWhiteGifts * this.gifts_data.whiteGiftCost;
            }
        
            calculateMinimumCostInConvertingGifts(): bigint {
                let totalGifts: bigint = this.gifts_data.nBlackGifts + this.gifts_data.nWhiteGifts;
                if (this.gifts_data.whiteGiftCost > this.costToConvertFromBlackToWhite)
                    return totalGifts * this.gifts_data.blackGiftCost + this.gifts_data.nWhiteGifts * this.gifts_data.costToConvertBetweenGifts;
                return totalGifts * this.gifts_data.whiteGiftCost + this.gifts_data.nBlackGifts * this.gifts_data.costToConvertBetweenGifts;
            }
    
        minimumCostOfBuyingGifts(): bigint {
            return this.minCostOfBuyingGifts;
        }
    }
