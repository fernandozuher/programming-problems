// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

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

//////////////////////////////////////////////////

function main() {
    let lettersHeights = readIntArray();
    let word = readLine();
    let obj = new DesignerPdfViewer(lettersHeights, word);
    console.log(obj.area());
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    class DesignerPdfViewer {
        #lettersHeights;
        #word;
        #area;

        constructor(lettersHeights, word) {
            this.#lettersHeights = lettersHeights;
            this.#word = word;
            this.#area = 0;
            this.#calculateArea();
        }

            #calculateArea() {
                let maxHeight = 0;

                for (const letter of this.#word) {
                    let letterIndex = letter.charCodeAt(0) - 'a'.charCodeAt(0);
                    let letterHeight = this.#lettersHeights[letterIndex];
                    maxHeight = Math.max(maxHeight, letterHeight);
                }

                this.#area = maxHeight * this.#word.length;
            }

        area() {
            return this.#area;
        }
    }
