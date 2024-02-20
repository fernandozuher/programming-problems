// https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

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

//////////////////////////////////////////////////

function main() {
    let initialString: string = readLine();
    let finalString: string = readLine();
    let operations: number = +readLine();
    let obj = new AppendAndDelete(initialString, finalString, operations);
    console.log(obj.areOperationsSuitableToReplacement() ? "Yes" : "No");
}

    class AppendAndDelete {
        private initialString: string;
        private finalString: string;
        private operations: number;

        private commonPrefixSizeBetweenStrings: number;
        private areOperationsProperToReplacement: boolean;

        constructor(initialString: string, finalString: string, operations: number) {
            this.initialString = initialString;
            this.finalString = finalString;
            this.operations = operations;
            this.commonPrefixSizeBetweenStrings = 0;
            this.areOperationsProperToReplacement = false;
            this.appendAndDelete();
        }

            private appendAndDelete() {
                this.commonPrefixSizeBetweenStrings = this.findCommonPrefixSizeBetweenStrings();

                let sizeOfDifferentCharactersFromInitialString = this.initialString.length - this.commonPrefixSizeBetweenStrings;
                let sizeOfDifferentCharactersFromFinalString = this.finalString.length - this.commonPrefixSizeBetweenStrings;

                let minimalQuantityOfOperationsToReplaceString = sizeOfDifferentCharactersFromInitialString + sizeOfDifferentCharactersFromFinalString;
                
                this.operations -= minimalQuantityOfOperationsToReplaceString;
                this.areOperationsProperToReplacement = this.areOperationsSuitableToReplaceString();
            }

                private findCommonPrefixSizeBetweenStrings(): number {
                    let size = 0;
                    let n = Math.min(this.initialString.length, this.finalString.length);
                    while (n-- && this.initialString[size] === this.finalString[size])
                        ++size;
                    return size;
                }

                private areOperationsSuitableToReplaceString(): boolean {
                    if (this.operations < 0 ||
                        (this.areOperationsBiggerThanZeroAndOdd() && this.areNotOperationsEnoughToRemoveAndReplaceCommonPrefix()))
                        return false;
                    return true;
                }

                    private areOperationsBiggerThanZeroAndOdd(): boolean {
                        return this.operations > 0 && this.operations%2 === 1;
                    }

                    private areNotOperationsEnoughToRemoveAndReplaceCommonPrefix(): boolean {
                        return this.operations < this.commonPrefixSizeBetweenStrings*2;
                    }

        public areOperationsSuitableToReplacement(): boolean {
            return this.areOperationsProperToReplacement;
        }
    }
