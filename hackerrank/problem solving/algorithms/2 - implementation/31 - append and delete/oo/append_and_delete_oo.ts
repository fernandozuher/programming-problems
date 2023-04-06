// Source: https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

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
    const INITIAL_STRING: string = readLine();
    const FINAL_STRING: string = readLine();
    const NUMBER_OF_OPERATIONS: number = +readLine();

    const OBJ: AppendAndDelete = new AppendAndDelete(INITIAL_STRING, FINAL_STRING, NUMBER_OF_OPERATIONS);
    const RESPONSE: boolean = OBJ.getResponse();
    printOutput(RESPONSE);
}

    function printOutput(response: boolean) {
        console.log(response ? "Yes" : "No");
    }

    class AppendAndDelete {
        private _initialString: string;
        private _finalString: string;
        private _numberOfOperations: number;

        private _commonPrefixSizeBetweenStrings: number;
        private _areOperationsSuitableToReplacement: boolean;

        constructor(initialString: string, finalString: string, numberOfOperations: number) {
            this._initialString = initialString;
            this._finalString = finalString;
            this._numberOfOperations = numberOfOperations;

            this._appendAndDelete();
        }

            private _appendAndDelete() {
                this._commonPrefixSizeBetweenStrings = this._findCommonPrefixSizeBetweenStrings();

                const SIZE_OF_DIFFERENT_CHARACTERS_FROM_INITIAL_STRING: number = this._initialString.length - this._commonPrefixSizeBetweenStrings;
                const SIZE_OF_DIFFERENT_CHARACTERS_FROM_FINAL_STRING: number = this._finalString.length - this._commonPrefixSizeBetweenStrings;

                const MINIMAL_QUANTITY_OF_OPERATIONS_TO_REPLACE_STRING: number = SIZE_OF_DIFFERENT_CHARACTERS_FROM_INITIAL_STRING + SIZE_OF_DIFFERENT_CHARACTERS_FROM_FINAL_STRING;
                
                this._numberOfOperations -= MINIMAL_QUANTITY_OF_OPERATIONS_TO_REPLACE_STRING;
                this._areOperationsSuitableToReplacement = this._areOperationsSuitableToReplaceString();
            }

                private _findCommonPrefixSizeBetweenStrings(): number {
                    let size: number = 0;
                    while (size != this._initialString.length && size != this._finalString.length && this._initialString[size] === this._finalString[size])
                        size++;
                    return size;
                }

                private _areOperationsSuitableToReplaceString(): boolean {
                    if (this._numberOfOperations < 0 ||
                        (this._areOperationsBiggerThanZeroAndOdd() && this._areNotOperationsEnoughToRemoveAndReplaceCommonPrefix()))
                        return false;
                    return true;
                }

                    private _areOperationsBiggerThanZeroAndOdd(): boolean {
                        return this._numberOfOperations > 0 && this._numberOfOperations%2 === 1;
                    }

                    private _areNotOperationsEnoughToRemoveAndReplaceCommonPrefix(): boolean {
                        return this._numberOfOperations < this._commonPrefixSizeBetweenStrings*2;
                    }

        public getResponse(): boolean {
            return this._areOperationsSuitableToReplacement;
        }
    }
