// Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

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
    const _: number = +readLine();
    const CLOUD_ARRAY: Array<number> = readAnArray();
    const MINIMUM_NUMBER_OF_JUMPS: number = calculateMinimumNumberOfJumps(CLOUD_ARRAY);
    console.log(MINIMUM_NUMBER_OF_JUMPS);
}

    function readAnArray(): Array<number> {
        const ARRAY: Array<number> = readLine().split(" ").map(Number);
        return ARRAY;
    }

    function calculateMinimumNumberOfJumps(array: Array<number>): number {
        let jumps: number = 0;

        for (let i = 0, size = array.length - 1; i < size; ) {
            i = getIndexOfNextJump(i, array);
            jumps++;
        }

        return jumps;
    }

        function getIndexOfNextJump(index: number, array: Array<number>): number {
            if (isNextSecondIndexInsideRange(index + 2, array.length))
                index += isNextSecondCloudCumulus(array[index + 2]) ? 2 : 1;
            else
                index++;
            return index;
        }

            function isNextSecondIndexInsideRange(index: number, size: number): boolean {
                return index < size;
            }

            function isNextSecondCloudCumulus(typeOfCloud: number): boolean {
                return typeOfCloud === 0;
            }
