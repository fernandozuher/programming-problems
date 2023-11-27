

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
        let [startingSam, endingSam] = readLine().split(' ').map(Number);
        let [appleTreeLocation, orangeTreeLocation] = readLine().split(' ').map(Number);

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
        const applesOnHouse = countFruitsOnHouse(input, 'apple');
        const orangesOnHouse = countFruitsOnHouse(input, 'orange');
        console.log(`${applesOnHouse}\n${orangesOnHouse}`);
    }

        function countFruitsOnHouse(input, fruit) {
            let filteredInput = filterInput(input, fruit);
            let treeLocation = filteredInput[0];
            let fruits = filteredInput[1];

            return fruits.filter(partialLocation => {
                const location = treeLocation + partialLocation;
                return location >= s && location <= t;
            }).length;
        }

            function filterInput(input, fruit) {
                let data = 2;
                let filteredInput = Array(data).fill(0);

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
