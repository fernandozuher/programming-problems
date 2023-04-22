// Source: https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

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
    const _: number = +readLine();
    const ARRAY: Array<number> = readAnArray();

    const OBJ: EqualizeTheArray = new EqualizeTheArray(ARRAY);
    const MINIMUM_NUMBER_OF_DELETIONS_REQUIRED: number = OBJ.getMinimumNumberOfDeletionsRequired();
    console.log(MINIMUM_NUMBER_OF_DELETIONS_REQUIRED);
}

    function readAnArray(): Array<number>  {
        const ARRAY: Array<number> = readLine().split(" ").map(Number);
        return ARRAY;
    }

    class EqualizeTheArray {
        private _array: Array<number>;
        private _minimumNumberOfDeletionsRequired: number;

        constructor(array: Array<number>) {
            array.sort((a, b) => a - b);
            this._array = array;
            this._equalizeArray();
        }
                
            private _equalizeArray() {
                const MAXIMUM_QUANTITY_OF_EQUAL_ELEMENT: number = this._findMaximumQuantityOfEqualElement();
                this._minimumNumberOfDeletionsRequired = this._array.length - MAXIMUM_QUANTITY_OF_EQUAL_ELEMENT;
            }

                private _findMaximumQuantityOfEqualElement(): number {
                    let maximumQuantityOfEqualElement: number = 1;

                    for (let i = 1, temporaryQuantityEqualElement = 1, size = this._array.length; i < size; i++) {

                        if (this._areConsecutiveElementesEqual(this._array[i - 1], this._array[i])) {
                            temporaryQuantityEqualElement++;
                            maximumQuantityOfEqualElement = Math.max(temporaryQuantityEqualElement, maximumQuantityOfEqualElement);
                        }
                        else
                            temporaryQuantityEqualElement = 1;
                    }

                    return maximumQuantityOfEqualElement;
                }

                    private _areConsecutiveElementesEqual(element1: number, element2: number): boolean {
                        return element1 === element2;
                    }

        public getMinimumNumberOfDeletionsRequired() {
            return this._minimumNumberOfDeletionsRequired;
        }
    }
