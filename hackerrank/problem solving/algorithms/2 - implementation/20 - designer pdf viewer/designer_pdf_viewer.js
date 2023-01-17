// Source: https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

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
    const inputLine1 = readLineAsNumberArray();
    const inputLine2 = readLineAsString();

    const result = new Result(inputLine1, inputLine2);
}

    function readLineAsNumberArray() {
        const inputLine = readLine().split(" ").map(Number);
        return inputLine;
    }

    function readLineAsString() {
        const inputLine = readLine();
        return inputLine;
    }

    class Result {
        #lettersHeights;
        #word;
        #area;

        constructor(lettersHeights, word) {
            this.#lettersHeights = [...lettersHeights];
            this.#word = word;
            this.#area = 0;

            this.#designerPdfViewer();
            this.printResult();
        }

            #designerPdfViewer() {
                let maxHeight = 0;

                for (const letter of this.#word) {
                    const letterIndex = letter.charCodeAt(0) - "a".charCodeAt(0);
                    const letterHeight = this.#lettersHeights[letterIndex];
                    if (maxHeight < letterHeight) maxHeight = letterHeight;
                }

                this.#area = maxHeight * this.#word.length;
            }

            printResult() {
                console.log(this.#area);
            }
    }
