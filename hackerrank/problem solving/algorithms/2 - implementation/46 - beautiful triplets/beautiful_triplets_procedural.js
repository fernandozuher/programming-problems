// Source: https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

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
    const [SIZE, BEAUTIFUL_DIFFERENCE] = readAnArray();
    const ARRAY = readAnArray();

    const N_BEAUTIFUL_TRIPLETS = findBeautifulTriplets(ARRAY, BEAUTIFUL_DIFFERENCE);
    console.log(N_BEAUTIFUL_TRIPLETS);
}

    function readAnArray() {
        const ARRAY = readLine().split(" ").map(Number);
        return ARRAY;
    }

    function findBeautifulTriplets(array, beautifulDifference) {
        let nBeautifulTriplets = 0;

        if (array.length > 2)
            for (let i = 0; i < array.length-2; i++)
                for (let j = i + 1; j < array.length-1; j++) {
                    const FIRST_DIFFERENCE = array[j] - array[i];

                    if (FIRST_DIFFERENCE < beautifulDifference)
                        continue;
                    else if (FIRST_DIFFERENCE > beautifulDifference)
                        break;

                    for (let k = j + 1; k < array.length; k++) {
                        const SECOND_DIFFERENCE = array[k] - array[j];

                        if (SECOND_DIFFERENCE == beautifulDifference)
                            nBeautifulTriplets++;
                        else if (SECOND_DIFFERENCE > beautifulDifference)
                            break;
                    }
                }

        return nBeautifulTriplets;
    }
