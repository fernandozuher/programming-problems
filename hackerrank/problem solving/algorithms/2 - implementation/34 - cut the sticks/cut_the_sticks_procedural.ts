// Source: https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

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
    const _SIZE: number = +readLine();
    const ARRAY: Array<number> = readAnArray();
    ARRAY.sort((a, b) => a - b);

    const RESULT: Array<number> = cutTheSticks(ARRAY);
    printArray(RESULT);
}

    function readAnArray(): Array<number> {
        return readLine().split(" ").map(Number);
    }

    function cutTheSticks(array: Array<number>): Array<number> {
        const SIZE: number = array.length;
        const REMAINING_STICKS_OF_EACH_ITERATION: Array<number> = initializeResult(SIZE);

        for (let i: number = 0; i < SIZE; ) {
            const SHORTEST_STICK_LENGTH: number = array[i];

            i = findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(i, array);
            const CURRENT_ITERATION_SIZE: number = SIZE - i;
            if (i === SIZE)
                break;

            REMAINING_STICKS_OF_EACH_ITERATION.push(CURRENT_ITERATION_SIZE);
            decreaseSticksLengthsHigherThanCurrentShortestStickLength(i, array, SHORTEST_STICK_LENGTH);
        }

        return REMAINING_STICKS_OF_EACH_ITERATION;
    }

        function initializeResult(size: number) {
            const REMAINING_STICKS_OF_EACH_ITERATION: Array<number> = [size];
            return REMAINING_STICKS_OF_EACH_ITERATION;
        }

        function findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(index: number, array: Array<number>): number {
            const SIZE: number = array.length;
            const SHORTEST_STICK_LENGTH: number = array[index];
            while (index < SIZE && array[index] === SHORTEST_STICK_LENGTH)
                index++;
            return index;
        }

        function decreaseSticksLengthsHigherThanCurrentShortestStickLength(index: number, array: Array<number>, shortestStickLength: number) {
            for (let i = index, size = array.length; i < size; i++)
                array[i] -= shortestStickLength;
        }

    function printArray(array: Array<number>) {
        array.forEach((element, _) => console.log(element));
    }
