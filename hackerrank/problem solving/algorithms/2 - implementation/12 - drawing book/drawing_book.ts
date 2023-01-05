// Source: https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

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
    const pageQuantity: number[] = readLineAsNumberArray();
    const page: number[] = readLineAsNumberArray();

    const result = new Result(pageQuantity[0], page[0]);
}

    function readLineAsNumberArray() {
        const numbers: number[] = readLine().split(" ").map(Number);
        return numbers;
    }

    class Result {
        private _pageQuantity: number;
        private _page: number;
        private _turnOfPagesFromFront: number;
        private _turnOfPagesFromBack: number;
        private _minimumTurnOfPages: number;

        constructor(pageQuantity: number, page: number) {
            this._pageQuantity = pageQuantity;
            this._page = page;
            this._turnOfPagesFromFront = 0;
            this._turnOfPagesFromBack = 0;
            this._minimumTurnOfPages = 0;

            this._drawingBook();
            this.printResult();
        }

            private _drawingBook() {
                this._turnOfPagesFromFront = this._calculateTurnOfPages(this._page);
        
                const maximumTurns: number = this._calculateTurnOfPages(this._pageQuantity);

                this._turnOfPagesFromBack = maximumTurns - this._turnOfPagesFromFront;

                this._minimumTurnOfPages = Math.min(this._turnOfPagesFromFront, this._turnOfPagesFromBack);
            }

                private _calculateTurnOfPages(page: number): number {
                    return page & 1 ? this._pageIsOdd(page) : this._pageIsEven(page);
                }

                    private _pageIsOdd(page: number): number {
                        return (page - 1) / 2;
                    }

                    private _pageIsEven(page: number): number {
                        return page / 2;
                    }
        
            printResult() {
                console.log(this._minimumTurnOfPages);
            }
    }
