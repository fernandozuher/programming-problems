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

//////////////////////////////////////////////////

function main() {
    let input = readInput();
    countApplesAndOranges(input);
}

    function readInput() {
        let input = new AppleAndOrange();
        [input.startingSam, input.endingSam] = readIntArray();
        [input.appleTreeLocation, input.orangeTreeLocation] = readIntArray();
        readLine(); // Discard sizes of arrays
        input.applesDistanceFromTree = readIntArray();
        input.orangesDistanceFromTree = readIntArray();
        return input;
    }

        class AppleAndOrange {
            startingSam = 0;
            endingSam = 0;
            appleTreeLocation = 0;
            orangeTreeLocation = 0;
            applesDistanceFromTree = [];
            orangesDistanceFromTree = [];
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
            let [treeLocation, fruits] = filterInput(input, fruit);
            return fruits.filter(partialLocation => {
                let location = treeLocation + partialLocation;
                return location >= input.startingSam && location <= input.endingSam;
            }).length;
        }

            function filterInput(input, fruit) {
                return fruit === 'apple' ?
                    [input.appleTreeLocation, input.applesDistanceFromTree]
                    : [input.orangeTreeLocation, input.orangesDistanceFromTree];
            }
