// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine() {
    return inputLines[currentLine++];
}

////////////////////////////////////////////////

function main() {
    let pageQuantity = +readLine();
    let page = +readLine();
    let obj = new DrawingBook(pageQuantity, page);
    console.log(obj.minimumTurnOfPages());
}

    class DrawingBook {
        #pageQuantity;
        #page;
        #turnOfPagesFromFront;
        #turnOfPagesFromBack;
        #minimumTurnOfPages;

        constructor(pageQuantity, page) {
            this.#pageQuantity = pageQuantity;
            this.#page = page;
            this.#turnOfPagesFromFront = 0;
            this.#turnOfPagesFromBack = 0;
            this.#minimumTurnOfPages = 0;
            this.#pageCount();
        }

            #pageCount() {
                this.#turnOfPagesFromFront = this.#calculateTurnOfPages(this.#page);
                let maximumTurns = this.#calculateTurnOfPages(this.#pageQuantity);
                this.#turnOfPagesFromBack = maximumTurns - this.#turnOfPagesFromFront;
                this.#minimumTurnOfPages = Math.min(this.#turnOfPagesFromFront, this.#turnOfPagesFromBack);
            }

                #calculateTurnOfPages(page) {
                    return page & 1 ? this.#pageIsOdd(page) : this.#pageIsEven(page);
                }

                    #pageIsOdd(page) {
                        return (page - 1) / 2;
                    }

                    #pageIsEven(page) {
                        return page / 2;
                    }

        minimumTurnOfPages() {
            return this.#minimumTurnOfPages;
        }
    }
