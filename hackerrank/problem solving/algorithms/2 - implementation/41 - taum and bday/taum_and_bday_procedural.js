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
        OUTPUT[i] = calculateMinimumCostOfBuyingGifts(INPUT);
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

    function calculateMinimumCostOfBuyingGifts(input) {
        if (areOriginalCostsCheaperOrEqualThanConvertionBetweenGifts(input))
            return calculateMinimumStandardCost(input);
        return calculateMinimumCostInConvertingGifts(input);
    }

        function areOriginalCostsCheaperOrEqualThanConvertionBetweenGifts(input) {
            const [_, _2, BLACK_GIFT_COST, WHITE_GIFT_COST, COST_TO_CONVERT_BETWEEN_GIFTS] = input;
            const COST_TO_CONVERT_FROM_BLACK_TO_WHITE = BLACK_GIFT_COST + COST_TO_CONVERT_BETWEEN_GIFTS;
            const COST_TO_CONVERT_FROM_WHITE_TO_BLACK = WHITE_GIFT_COST + COST_TO_CONVERT_BETWEEN_GIFTS;
            return WHITE_GIFT_COST <= COST_TO_CONVERT_FROM_BLACK_TO_WHITE && BLACK_GIFT_COST <= COST_TO_CONVERT_FROM_WHITE_TO_BLACK;
        }

        function calculateMinimumStandardCost(input) {
            const [N_BLACK_GIFTS, N_WHITE_GIFTS, BLACK_GIFT_COST, WHITE_GIFT_COST, _] = input;
            return BigInt(N_BLACK_GIFTS * BLACK_GIFT_COST + N_WHITE_GIFTS * WHITE_GIFT_COST);
        }

        function calculateMinimumCostInConvertingGifts(input) {
            const [N_BLACK_GIFTS, N_WHITE_GIFTS, BLACK_GIFT_COST, WHITE_GIFT_COST, COST_TO_CONVERT_BETWEEN_GIFTS] = input;

            const COST_TO_CONVERT_FROM_BLACK_TO_WHITE = BLACK_GIFT_COST + COST_TO_CONVERT_BETWEEN_GIFTS;
            const TOTAL_GIFTS = N_BLACK_GIFTS + N_WHITE_GIFTS;
            let minimumCostOfBuyingGifts;

            if (WHITE_GIFT_COST > COST_TO_CONVERT_FROM_BLACK_TO_WHITE)
                minimumCostOfBuyingGifts = BigInt(TOTAL_GIFTS * BLACK_GIFT_COST + N_WHITE_GIFTS * COST_TO_CONVERT_BETWEEN_GIFTS);
            else
                minimumCostOfBuyingGifts = BigInt(TOTAL_GIFTS * WHITE_GIFT_COST + N_BLACK_GIFTS * COST_TO_CONVERT_BETWEEN_GIFTS);

            return minimumCostOfBuyingGifts;
        }

    function printArray(array) {
        array.forEach(element => console.log(element.toString()));
    }
