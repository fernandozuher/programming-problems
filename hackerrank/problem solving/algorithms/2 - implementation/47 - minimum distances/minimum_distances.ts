// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

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

//////////////////////////////////////////////////

const NO_INDEX = -1;

function main() {
    +readLine();
    let array: number[] = readIntArray();
    console.log(findMinimumDistance(array));
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    function findMinimumDistance(array: number[]) {
        let minimumDistance: number = Number.MAX_SAFE_INTEGER;
        let first_indexes_of_elements: {[key: number]: number[]} = {};

        for (let i = 0, element; i < array.length; ++i) {
            element = array[i];
        
            if (first_indexes_of_elements.hasOwnProperty(element)) {
                let [firstIndex, secondIndex]: number[] = first_indexes_of_elements[element]

                if (secondIndex === NO_INDEX) {
                    first_indexes_of_elements[element][1] = secondIndex = i;
                    let minimum_distance_OF_current_element: number = secondIndex - firstIndex;
                    minimumDistance = Math.min(minimumDistance, minimum_distance_OF_current_element);
                }
            } else
                first_indexes_of_elements[element] = [i, NO_INDEX];
        }

        return minimumDistance !== Number.MAX_SAFE_INTEGER ? minimumDistance : NO_INDEX;
    }
