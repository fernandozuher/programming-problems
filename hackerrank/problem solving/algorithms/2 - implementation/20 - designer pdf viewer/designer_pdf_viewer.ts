// Source: https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

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
    const inputLine1: number[] = readLineAsNumberArray();
    const inputLine2: string = readLineAsString();

    const result = new Result(inputLine1, inputLine2);
}

    function readLineAsNumberArray(): number[] {
        const inputLine = readLine().split(" ").map(Number);
        return inputLine;
    }

    function readLineAsString(): string {
        return readLine();
    }

    class Result {
        private _lettersHeights: number[];
        private _word: string;
        private _area: number;

        constructor(lettersHeights: number[], word: string) {
            this._lettersHeights = [...lettersHeights];
            this._word = word;
            this._area = 0;

            this._designerPdfViewer();
            this.printResult();
        }

            private _designerPdfViewer() {
                let maxHeight = 0;

                for (const letter of this._word) {
                    const letterIndex: number = letter.charCodeAt(0) - "a".charCodeAt(0);
                    const letterHeight: number = this._lettersHeights[letterIndex];
                    
                    if (maxHeight < letterHeight)
                        maxHeight = letterHeight;
                }

                this._area = maxHeight * this._word.length;
            }

            public printResult() {
                console.log(this._area);
            }
    }
