// Source: https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

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
    const INPUT_STRING: string = readLine();
    const N_CHARACTERS: number = +readLine();

    const OBJ: RepeatedString = new RepeatedString(INPUT_STRING, N_CHARACTERS);
    const QUANTITY_OF_A: number = OBJ.getQuantityOfA();
    console.log(QUANTITY_OF_A);
}

    class RepeatedString {
        private _inputString: string;
        private _nCharacters: number;
        private _quantityOfA: number;

        constructor(inputString: string, nCharacters: number) {
            this._inputString = inputString;
            this._nCharacters = nCharacters;
            this._quantityOfA = 0;

            this._findQuantityOfAInRepeatedString();
        }

            private _findQuantityOfAInRepeatedString() {
                this._quantityOfA = this._findQuantityOfAInString(this._inputString);
                this._quantityOfA *= this._findQuantityOfRepeatedEntireString();
                this._quantityOfA += this._findQuantityOfRemainingA();
            }

                private _findQuantityOfAInString(inputString: string): number {
                    let quantityOfA: number = 0;

                    for (let character of inputString)
                        if (character === 'a')
                            quantityOfA++;

                    return quantityOfA;
                }

                private _findQuantityOfRepeatedEntireString(): number {
                    const N_STRINGS: number = Math.trunc(this._nCharacters / this._inputString.length);
                    return N_STRINGS;
                }

                private _findQuantityOfRemainingA(): number {
                    const N_REMAINING_CHARACTERS_OF_STRING: number = this._nCharacters % this._inputString.length;

                    if (N_REMAINING_CHARACTERS_OF_STRING == 0)
                        return 0;

                    const SUB_STRING: string = this._inputString.substring(0, N_REMAINING_CHARACTERS_OF_STRING);
                    return this._findQuantityOfAInString(SUB_STRING);
                }

        public getQuantityOfA(): number {
            return this._quantityOfA;
        }
    }
