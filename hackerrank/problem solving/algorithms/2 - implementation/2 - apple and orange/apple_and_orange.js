// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

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

function main() {
    let input = readInput();
    countApplesAndOranges(input);
}
    
    function readInput() {
        let [startingSam, endingSam] = readIntArray();
        let [appleTreeLocation, orangeTreeLocation] = readIntArray();

        // Discard sizes of arrays
        readLine();

        let applesDistanceFromTree = readIntArray();
        let orangesDistanceFromTree = readIntArray();

        return new AppleAndOrange(startingSam, endingSam,
                                  appleTreeLocation, orangeTreeLocation,
                                  applesDistanceFromTree, orangesDistanceFromTree);
    }

        function readIntArray() {
            return readLine().split(' ').map(Number);
        }

    function countApplesAndOranges(input) {
        let applesOnHouse = countFruitsOnHouse(input, 'apple');
        let orangesOnHouse = countFruitsOnHouse(input, 'orange');
        console.log(`${applesOnHouse}\n${orangesOnHouse}`);
    }

        function countFruitsOnHouse(input, fruit) {
            let filteredInput = filterInput(input, fruit);
            let treeLocation = filteredInput[0];
            let fruits = filteredInput[1];

            return fruits.filter(partialLocation => {
                let location = treeLocation + partialLocation;
                return location >= input.startingSam && location <= input.endingSam;
            }).length;
        }

            function filterInput(input, fruit) {
                const DATA = 2;
                let filteredInput = Array(DATA).fill(0);

                if (fruit === 'apple') {
                    filteredInput[0] = input.appleTreeLocation;
                    filteredInput[1] = input.applesDistanceFromTree;
                } else {
                    filteredInput[0] = input.orangeTreeLocation;
                    filteredInput[1] = input.orangesDistanceFromTree;
                }

                return filteredInput;
            }

    class AppleAndOrange {
        constructor(startingSam, endingSam, appleTreeLocation, orangeTreeLocation, applesDistanceFromTree, orangesDistanceFromTree) {
            this.startingSam = startingSam;
            this.endingSam = endingSam;
            this.appleTreeLocation = appleTreeLocation;
            this.orangeTreeLocation = orangeTreeLocation;
            this.applesDistanceFromTree = applesDistanceFromTree;
            this.orangesDistanceFromTree = orangesDistanceFromTree;
        }
    }
