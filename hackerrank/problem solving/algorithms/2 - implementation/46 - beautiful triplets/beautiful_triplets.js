// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine() {
    return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
    let [, beautifulDifference] = readIntArray();
    let array = readIntArray();
    console.log(findBeautifulTriplets(array, beautifulDifference));
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    function findBeautifulTriplets(array, beautifulDifference) {
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
