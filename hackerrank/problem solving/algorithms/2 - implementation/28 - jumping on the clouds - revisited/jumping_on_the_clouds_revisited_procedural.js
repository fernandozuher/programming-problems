// Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

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
    let array = readAnArray();
    const _SIZE_ARRAY = array[0];
    const JUMP_LENGTH = array[1];
    array = readAnArray();

    const ENERGY = jumpingOnClouds(array, JUMP_LENGTH);
    console.log(ENERGY);
}

    function readAnArray() {
        const ARRAY = readLine().split(" ").map(Number);
        return ARRAY;
    }

    function jumpingOnClouds(array, jumpLength) {
        let energy = 100;

        for (let cloudIndex = 0; true; ) {
            energy -= spentEnergyAccordingToTypeOfCloud(array[cloudIndex]);
            cloudIndex = generateNewCloudIndex(cloudIndex, array.length, jumpLength);
            if (isCloudIndexBackToFirstCloud(cloudIndex)) {
                break;
            }
        }

        return energy;
    }

        function spentEnergyAccordingToTypeOfCloud(cloudType) {
            return cloudType == 0 ? 1 : 3;
        }

        function generateNewCloudIndex(cloudIndex, sizeArray, jumpLength) {
            return (cloudIndex + jumpLength) % sizeArray;
        }

        function isCloudIndexBackToFirstCloud(cloudIndex) {
            return cloudIndex == 0;
        }
