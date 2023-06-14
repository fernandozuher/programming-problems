// Source: https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

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
    const [SIZE, BEAUTIFUL_DIFFERENCE]: Array<number> = readAnArray();
    const ARRAY: Array<number> = readAnArray();

    const N_BEAUTIFUL_TRIPLETS: number = findBeautifulTriplets(ARRAY, BEAUTIFUL_DIFFERENCE);
    console.log(N_BEAUTIFUL_TRIPLETS);
}

    function readAnArray(): Array<number> {
        const ARRAY: Array<number> = readLine().split(" ").map(Number);
        return ARRAY;
    }

    function findBeautifulTriplets(array: Array<number>, beautifulDifference: number): number {
        let nBeautifulTriplets: number = 0;

        if (array.length > 2)
            for (let i = 0; i < array.length-2; i++)
                for (let j = i + 1; j < array.length-1; j++) {
                    const FIRST_DIFFERENCE: number = array[j] - array[i];

                    if (FIRST_DIFFERENCE < beautifulDifference)
                        continue;
                    else if (FIRST_DIFFERENCE > beautifulDifference)
                        break;

                    for (let k = j + 1; k < array.length; k++) {
                        const SECOND_DIFFERENCE: number = array[k] - array[j];

                        if (SECOND_DIFFERENCE == beautifulDifference)
                            nBeautifulTriplets++;
                        else if (SECOND_DIFFERENCE > beautifulDifference)
                            break;
                    }
                }

        return nBeautifulTriplets;
    }
