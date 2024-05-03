// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

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

function main() {
    let [, beautifulDifference]: number[] = readIntArray();
    let array: number[] = readIntArray();
    console.log(findBeautifulTriplets(array, beautifulDifference));
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    function findBeautifulTriplets(array: number[], beautifulDifference: number): number {
        let nBeautifulTriplets = 0;

        if (array.length > 2)
            for (let i = 0; i < array.length-2; ++i)
                for (let j = i + 1; j < array.length-1; ++j) {
                    let firstDifference = array[j] - array[i];

                    if (firstDifference < beautifulDifference)
                        continue;
                    else if (firstDifference > beautifulDifference)
                        break;

                    for (let k = j + 1; k < array.length; ++k) {
                        let secondDifference = array[k] - array[j];

                        if (secondDifference === beautifulDifference)
                            ++nBeautifulTriplets;
                        else if (secondDifference > beautifulDifference)
                            break;
                    }
                }

        return nBeautifulTriplets;
    }
