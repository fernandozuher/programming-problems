// Source: https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

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
    const INPUT: Array<any> = readInput();
    const OBJ: CircularArrayRotation = new CircularArrayRotation(INPUT);
    OBJ.printRotatedArrayElementsAccordingToQueries();
}

    function readInput(): Array<any> {
        const [ARRAY_SIZE, ROTATION_COUNT, QUERIES_SIZE]: Array<number> = readLineAsNumericArray();
        const ARRAY: Array<number> = readLineAsNumericArray();
        const QUERIES: Array<number> = readQueries(QUERIES_SIZE);
        const INPUT: Array<any> = [ARRAY, ARRAY_SIZE, ROTATION_COUNT, QUERIES, QUERIES_SIZE];
        return INPUT;
    }

        function readLineAsNumericArray(): Array<number> {
            const ARRAY: Array<number> = readLine().split(" ").map(Number);
            return ARRAY;
        }

        function readQueries(size: number): Array<number> {
            const ARRAY: Array<number> = new Array(size).fill(0).map(element => +readLine());
            return ARRAY;
        }

    class CircularArrayRotation {
        private _array: Array<number>;
        private _arraySize: number;
        private _rotationCount: number;
        private _queries: Array<number>;
        private _querySize: number;

        constructor(input: Array<any>) {
            this._array = input[0];
            this._arraySize = input[1];
            this._rotationCount = input[2];
            this._queries = input[3];
            this._querySize = input[4];

            this._reduceInputRotations();
            this._rotateInputArray();
        }
        
            private _reduceInputRotations() {
                if (this._arraySize > 1)
                    this._rotationCount = this._rotationCount >= this._arraySize ? this._rotationCount % this._arraySize : this._rotationCount;
                else
                    this._rotationCount = 0;
            }

            private _rotateInputArray() {
                const FIRST_PART_NEW_ARRAY: Array<number> = this._array.slice(this._arraySize - this._rotationCount, this._arraySize);
                const SECOND_PART_NEW_ARRAY: Array<number> = this._array.slice(0, this._arraySize - this._rotationCount);
                const NEW_ARRAY: Array<number> = [...FIRST_PART_NEW_ARRAY, ...SECOND_PART_NEW_ARRAY];

                this._array = NEW_ARRAY;
            }

        printRotatedArrayElementsAccordingToQueries() {
            this._queries.forEach(query => console.log(this._array[query]));
        }
    }
