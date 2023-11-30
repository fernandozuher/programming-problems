// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

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
    let input: AppleAndOrange = readInput();
    countApplesAndOranges(input);
}
    
    function readInput(): AppleAndOrange {
        let [startingSam, endingSam]: number[] = readIntArray();
        let [appleTreeLocation, orangeTreeLocation]: number[] = readIntArray();

        // Discard sizes of arrays
        readLine();

        let applesDistanceFromTree: number[] = readIntArray();
        let orangesDistanceFromTree: number[] = readIntArray();

        return new AppleAndOrange(startingSam, endingSam,
                                  appleTreeLocation, orangeTreeLocation,
                                  applesDistanceFromTree, orangesDistanceFromTree);
    }

        function readIntArray(): number[] {
            return readLine().split(' ').map(Number);
        }

    function countApplesAndOranges(input: AppleAndOrange) {
        let applesOnHouse: number = countFruitsOnHouse(input, 'apple');
        let orangesOnHouse: number = countFruitsOnHouse(input, 'orange');
        console.log(`${applesOnHouse}\n${orangesOnHouse}`);
    }

        function countFruitsOnHouse(input: AppleAndOrange, fruit: string) {
            let filteredInput: number[][] = filterInput(input, fruit);
            let treeLocation: number = filteredInput[0][0];
            let fruits: number[] = filteredInput[1];

            return fruits.filter(partialLocation => {
                let location: number = treeLocation + partialLocation;
                return location >= input.startingSam && location <= input.endingSam;
            }).length;
        }

            function filterInput(input: AppleAndOrange, fruit: string) {
                const DATA: number = 2;
                let filteredInput: number[][] = Array(DATA).fill([]);

                if (fruit === 'apple') {
                    filteredInput[0].push(input.appleTreeLocation);
                    filteredInput[1] = input.applesDistanceFromTree;
                } else {
                    filteredInput[0].push(input.orangeTreeLocation);
                    filteredInput[1] = input.orangesDistanceFromTree;
                }

                return filteredInput;
            }

    class AppleAndOrange {
        public startingSam: number;
        public endingSam: number;
        public appleTreeLocation: number;
        public orangeTreeLocation: number;
        public applesDistanceFromTree: number[];
        public orangesDistanceFromTree: number[];

        public constructor(startingSam: number, endingSam: number, appleTreeLocation: number,
            orangeTreeLocation: number, applesDistanceFromTree: number[],
            orangesDistanceFromTree: number[]) {
            this.startingSam = startingSam;
            this.endingSam = endingSam;
            this.appleTreeLocation = appleTreeLocation;
            this.orangeTreeLocation = orangeTreeLocation;
            this.applesDistanceFromTree = applesDistanceFromTree;
            this.orangesDistanceFromTree = orangesDistanceFromTree;
        }
    }
