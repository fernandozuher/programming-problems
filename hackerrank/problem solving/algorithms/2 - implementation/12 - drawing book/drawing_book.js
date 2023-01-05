// Source: https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');
    main();
});

function readLine() {
    return inputString[currentLine++];
}


function main() {
    const pageQuantity = readLineAsNumberArray();
    const page = readLineAsNumberArray();

    const result = new Result(pageQuantity[0], page[0]);
}

    function readLineAsNumberArray() {
        const numbers = readLine().split(" ").map(Number);
        return numbers;
    }

    class Result {
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

            this.#drawingBook();
            this.printResult();
        }

            #drawingBook() {
                this.#turnOfPagesFromFront = this.#calculateTurnOfPages(this.#page);
        
                const maximumTurns = this.#calculateTurnOfPages(this.#pageQuantity);

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
        
            printResult() {
                console.log(this.#minimumTurnOfPages);
            }
    }
