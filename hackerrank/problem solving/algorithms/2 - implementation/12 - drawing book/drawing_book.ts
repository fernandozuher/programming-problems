// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

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

////////////////////////////////////////////////

function main() {
    let pageQuantity: number = +readLine();
    let page: number = +readLine();
    let obj = new DrawingBook(pageQuantity, page);
    console.log(obj.minimumTurnOfPages());
}

    class DrawingBook {
        private pageQuantity: number;
        private page: number;
        private turnOfPagesFromFront: number;
        private turnOfPagesFromBack: number;
        private minTurnOfPages: number;

        constructor(pageQuantity: number, page: number) {
            this.pageQuantity = pageQuantity;
            this.page = page;
            this.turnOfPagesFromFront = 0;
            this.turnOfPagesFromBack = 0;
            this.minTurnOfPages = 0;
            this.pageCount();
        }

            private pageCount() {
                this.turnOfPagesFromFront = this.calculateTurnOfPages(this.page);
                const maximumTurns: number = this.calculateTurnOfPages(this.pageQuantity);
                this.turnOfPagesFromBack = maximumTurns - this.turnOfPagesFromFront;
                this.minTurnOfPages = Math.min(this.turnOfPagesFromFront, this.turnOfPagesFromBack);
            }

                private calculateTurnOfPages(page: number): number {
                    return page & 1 ? this.pageIsOdd(page) : this.pageIsEven(page);
                }

                    private pageIsOdd(page: number): number {
                        return (page - 1) / 2;
                    }

                    private pageIsEven(page: number): number {
                        return page / 2;
                    }

        public minimumTurnOfPages(): number {
            return this.minTurnOfPages;
        }
    }
