// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

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
    let lettersHeights: number[] = readIntArray();
    let word: string = readLine();
    let obj = new DesignerPdfViewer(lettersHeights, word);
    console.log(obj.area());
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    class DesignerPdfViewer {
        private lettersHeights: number[];
        private word: string;
        private areaSize: number;

        constructor(lettersHeights: number[], word: string) {
            this.lettersHeights = lettersHeights;
            this.word = word;
            this.areaSize = 0;
            this.calculateArea();
        }

            private calculateArea() {
                let maxHeight = 0;

                for (const letter of this.word) {
                    let letterIndex: number = letter.charCodeAt(0) - 'a'.charCodeAt(0);
                    let letterHeight: number = this.lettersHeights[letterIndex];
                    maxHeight = Math.max(maxHeight, letterHeight);
                }

                this.areaSize = maxHeight * this.word.length;
            }

        public area(): number {
            return this.areaSize;
        }
    }
