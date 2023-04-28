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
        OUTPUT[i] = calculateMinimumCostOfBuyingGifts(INPUT);
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

    function calculateMinimumCostOfBuyingGifts(input: Array<bigint>): bigint {
        if (areOriginalCostsCheaperOrEqualThanConvertionBetweenGifts(input))
            return calculateMinimumStandardCost(input);
        return calculateMinimumCostInConvertingGifts(input);
    }

        function areOriginalCostsCheaperOrEqualThanConvertionBetweenGifts(input: Array<bigint>): boolean {
            const [_, _2, BLACK_GIFT_COST, WHITE_GIFT_COST, COST_TO_CONVERT_BETWEEN_GIFTS]: Array<bigint> = input;
            const COST_TO_CONVERT_FROM_BLACK_TO_WHITE: bigint = BLACK_GIFT_COST + COST_TO_CONVERT_BETWEEN_GIFTS;
            const COST_TO_CONVERT_FROM_WHITE_TO_BLACK: bigint = WHITE_GIFT_COST + COST_TO_CONVERT_BETWEEN_GIFTS;
            return WHITE_GIFT_COST <= COST_TO_CONVERT_FROM_BLACK_TO_WHITE && BLACK_GIFT_COST <= COST_TO_CONVERT_FROM_WHITE_TO_BLACK;
        }

        function calculateMinimumStandardCost(input: Array<bigint>): bigint {
            const [N_BLACK_GIFTS, N_WHITE_GIFTS, BLACK_GIFT_COST, WHITE_GIFT_COST, _]: Array<bigint> = input;
            return N_BLACK_GIFTS * BLACK_GIFT_COST + N_WHITE_GIFTS * WHITE_GIFT_COST;
        }

        function calculateMinimumCostInConvertingGifts(input: Array<bigint>): bigint {
            const [N_BLACK_GIFTS, N_WHITE_GIFTS, BLACK_GIFT_COST, WHITE_GIFT_COST, COST_TO_CONVERT_BETWEEN_GIFTS]: Array<bigint> = input;

            const COST_TO_CONVERT_FROM_BLACK_TO_WHITE: bigint = BLACK_GIFT_COST + COST_TO_CONVERT_BETWEEN_GIFTS;
            const TOTAL_GIFTS: bigint = N_BLACK_GIFTS + N_WHITE_GIFTS;
            let minimumCostOfBuyingGifts: bigint;

            if (WHITE_GIFT_COST > COST_TO_CONVERT_FROM_BLACK_TO_WHITE)
                minimumCostOfBuyingGifts = TOTAL_GIFTS * BLACK_GIFT_COST + N_WHITE_GIFTS * COST_TO_CONVERT_BETWEEN_GIFTS;
            else
                minimumCostOfBuyingGifts = TOTAL_GIFTS * WHITE_GIFT_COST + N_BLACK_GIFTS * COST_TO_CONVERT_BETWEEN_GIFTS;

            return minimumCostOfBuyingGifts;
        }

    function printArray(array: Array<bigint>) {
        array.forEach(element => console.log(element.toString()));
    }
