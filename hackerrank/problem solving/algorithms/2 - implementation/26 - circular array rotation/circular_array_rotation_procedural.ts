// Source: https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

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
    let input: any[] = readInput();
    input = reduceInputRotations(input);
    input = rotateInputArray(input);
    printRotatedArrayElementsAccordingToQueries(input);
}

    function readInput(): any[] {
        const [ARRAY_SIZE, ROTATION_COUNT, QUERIES_SIZE]: number[] = readLineAsNumericArray();
        const ARRAY: number[] = readLineAsNumericArray();
        const QUERIES: number[] = readQueries(QUERIES_SIZE);
        const INPUT: any[] = [ARRAY, ARRAY_SIZE, ROTATION_COUNT, QUERIES, QUERIES_SIZE];
        return INPUT;
    }

        function readLineAsNumericArray(): number[] {
            const ARRAY: number[] = readLine().split(" ").map(Number);
            return ARRAY;
        }

        function readQueries(size: number): number[] {
            const ARRAY: number[] = new Array(size).fill(0);
            ARRAY.forEach((_, i) => {
                ARRAY[i] = +readLine();
            });
            return ARRAY;
        }

    function reduceInputRotations(input: any[]): number[] {
        const ARRAY_SIZE: number = input[1];
        let rotationCount: number = input[2];

        if (ARRAY_SIZE > 1)
            input[2] = rotationCount = rotationCount >= ARRAY_SIZE ? rotationCount % ARRAY_SIZE : rotationCount;
        else
            input[2] = rotationCount = 0;

        return input;
    }

    function rotateInputArray(input: any[]): any[] {
        const ARRAY: number[] = input[0];
        const ARRAY_SIZE: number = input[1];
        const ROTATION_COUNT: number = input[2];

        const FIRST_PART_NEW_ARRAY: number[] = ARRAY.slice(ARRAY_SIZE - ROTATION_COUNT, ARRAY_SIZE);
        const SECOND_PART_NEW_ARRAY: number[] = ARRAY.slice(0, ARRAY_SIZE - ROTATION_COUNT);
        const NEW_ARRAY: number[] = [...FIRST_PART_NEW_ARRAY, ...SECOND_PART_NEW_ARRAY];

        input[0] = NEW_ARRAY;
        return input;
    }

    function printRotatedArrayElementsAccordingToQueries(input: any[]) {
        const ARRAY: number[] = input[0];
        const QUERIES: number[] = input[3];
        QUERIES.forEach(query => console.log(ARRAY[query]));
    }
