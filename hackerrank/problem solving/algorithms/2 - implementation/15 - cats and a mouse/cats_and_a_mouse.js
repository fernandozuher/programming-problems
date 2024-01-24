// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true

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
    let n = +readLine();
    let nearestCatsOrNot = Array(n).fill('');

    for (let i = 0, animals = 3; i < n; ++i) {
        let positions = readIntArray(animals);
        let obj = new CatsAndAMouse(positions);
        nearestCatsOrNot[i] = obj.nearestCatOrNot();
    }

    nearestCatsOrNot.forEach(x => console.log(x));
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    class CatsAndAMouse {
        #catAPosition;
        #catBPosition;
        #mousePosition;
        #nearestCatOrNot;

        constructor(catsAndMousePositions) {
            [this.#catAPosition, this.#catBPosition, this.#mousePosition] = catsAndMousePositions;
            this.#nearestCatOrNot = '';
            this.#findNearestCatOrNot();
        }

            #findNearestCatOrNot() {
                let catAPositionFromMouse = Math.abs(this.#catAPosition - this.#mousePosition);
                let catBPositionFromMouse = Math.abs(this.#catBPosition - this.#mousePosition);

                if (catAPositionFromMouse < catBPositionFromMouse)
                    this.#nearestCatOrNot = "Cat A";
                else if (catAPositionFromMouse > catBPositionFromMouse)
                    this.#nearestCatOrNot = "Cat B";
                else
                    this.#nearestCatOrNot = "Mouse C";
            }

        nearestCatOrNot() {
            return this.#nearestCatOrNot;
        }
    }
