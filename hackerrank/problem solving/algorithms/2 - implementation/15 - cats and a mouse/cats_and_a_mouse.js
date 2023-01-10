// Source: https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true

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
    const inputLine = readLineAsNumberArray();
    const n = inputLine[0];

    const inputLines = readCatsAndMousePositionsLines(n);

    const result = new Result(inputLines);
}

    function readLineAsNumberArray() {
        const inputLine = readLine().split(" ").map(Number);
        return inputLine;
    }

    function readCatsAndMousePositionsLines(n) {
        let catsAndMousePositionsLines = new Array(n)

        for (let i = 0; i < n; i++)
            catsAndMousePositionsLines[i] = readLine().split(" ").map(Number);

        return catsAndMousePositionsLines;
    }

    class Result {
        #catsAndMousePositionsLines;
        #result;

        constructor(catsAndMousePositionsLines) {
            this.#catsAndMousePositionsLines = [...catsAndMousePositionsLines];
            this.#result = [];

            this.#catAndMouse();
            this.printResult();
        }

            #catAndMouse() {
                for (let catsAndMousePositions of this.#catsAndMousePositionsLines)
                    this.#findNearestCatOrNot(catsAndMousePositions);
            }

                #findNearestCatOrNot(catsAndMousePositions) {
                    const catAPosition = catsAndMousePositions[0];
                    const catBPosition = catsAndMousePositions[1];
                    const mousePosition = catsAndMousePositions[2];

                    const catAPositionDifference = Math.abs(catAPosition - mousePosition);
                    const catBPositionDifference = Math.abs(catBPosition - mousePosition);

                    this.#setStringResult(catAPositionDifference, catBPositionDifference);
                }

                    #setStringResult(catAPositionDifference, catBPositionDifference) {
                        if (catAPositionDifference < catBPositionDifference)
                            this.#result.push("Cat A");
                        else if (catAPositionDifference > catBPositionDifference)
                            this.#result.push("Cat B");
                        else
                            this.#result.push("Mouse C");
                    }

            printResult() {
                for (let result of this.#result)
                    console.log(result);
            }
}
