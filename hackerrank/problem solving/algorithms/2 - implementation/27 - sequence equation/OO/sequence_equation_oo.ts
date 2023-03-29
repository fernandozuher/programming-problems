// Source: https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

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
    const SIZE: number = readANumber();
    const ARRAY: Array<number> = readAnArray();

    const OBJ = new SequenceEquation(ARRAY);
    OBJ.printPermutatedArray();
}

    function readANumber(): number {
        return +readLine();
    }

    function readAnArray(): Array<number> {
        const ARRAY: Array<number> = readLine().split(" ").map(Number);
        return ARRAY;
    }

    class SequenceEquation {
        private _inputArray: Array<number>;
        private _elementsPositionsArray: Array<number>;
        private _permutatedArray: Array<number>;

        public constructor(array: Array<number>) {
            this._inputArray = array;
            this._elementsPositionsArray = this._generateElementsPositionsArray();
            this._permutatedArray = this._generatePermutatedArray();
        }

            private _generateElementsPositionsArray(): Array<number> {
                const elementsPositionsArray: Array<number> = new Array(this._inputArray.length).fill(0);
                this._inputArray.forEach((element, i) => {
                    elementsPositionsArray[element-1] = i;
                });
                return elementsPositionsArray;
            }

            private _generatePermutatedArray(): Array<number> {
                const permutatedArray: Array<number> = new Array(this._elementsPositionsArray.length).fill(0);
                this._elementsPositionsArray.forEach((element, i) => {
                    permutatedArray[i] = this._elementsPositionsArray[element] + 1;
                });
                return permutatedArray;
            }

        public printPermutatedArray() {
            this._permutatedArray.forEach(element => console.log(element));
        }
    }
