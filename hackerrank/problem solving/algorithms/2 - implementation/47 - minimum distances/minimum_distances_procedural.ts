// Source: https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

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
    const ARRAY: Array<number> = readANumericArray();
    console.log(findMinimumDistance(ARRAY));
}

    function readANumericArray(): Array<number> {
        return readLine().split(" ").map(Number);
    }

    function findMinimumDistance(array: Array<number>): number {
        let minimumDistance: number = Number.MAX_SAFE_INTEGER;
        const ELEMENTS: {[key: number]: Array<number>} = {};

        for (let i = 0, element; i < array.length; i++) {
            element = array[i];
        
            if (ELEMENTS.hasOwnProperty(element)) {
                let [firstIndex, secondIndex]: Array<number> = ELEMENTS[element];

                if (secondIndex == -1) {
                    ELEMENTS[element][1] = secondIndex = i;
                    const MINIMUM_DISTANCE_OF_CURRENT_ELEMENT: number = secondIndex - firstIndex;
                    minimumDistance = Math.min(minimumDistance, MINIMUM_DISTANCE_OF_CURRENT_ELEMENT);
                }
            } else
                ELEMENTS[element] = [i, -1];
        }

        return minimumDistance != Number.MAX_SAFE_INTEGER ? minimumDistance : -1;
    }
