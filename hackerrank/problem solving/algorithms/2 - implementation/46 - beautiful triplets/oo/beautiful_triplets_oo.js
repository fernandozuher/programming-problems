// Source: https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

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
    const [SIZE, BEAUTIFUL_DIFFERENCE] = readAnArray();
    const ARRAY = readAnArray();

    const OBJ = new BeautifulTriplets(ARRAY, BEAUTIFUL_DIFFERENCE);
    console.log(OBJ.getNBeautifulTriplets());
}

    function readAnArray() {
        const ARRAY = readLine().split(" ").map(Number);
        return ARRAY;
    }

    class BeautifulTriplets {
        #array;
        #beautifulDifference;
        #nBeautifulTriplets;

        constructor(array, beautifulDifference) {
            this.#array = array;
            this.#beautifulDifference = beautifulDifference;
            this.#findBeautifulTriplets();
        }

            #findBeautifulTriplets() {
                this.#nBeautifulTriplets = 0;

                if (this.#array.length > 2)
                    for (let i = 0; i < this.#array.length-2; i++)
                        for (let j = i + 1; j < this.#array.length-1; j++) {
                            const FIRST_DIFFERENCE = this.#array[j] - this.#array[i];

                            if (FIRST_DIFFERENCE < this.#beautifulDifference)
                                continue;
                            else if (FIRST_DIFFERENCE > this.#beautifulDifference)
                                break;

                            for (let k = j + 1; k < this.#array.length; k++) {
                                const SECOND_DIFFERENCE = this.#array[k] - this.#array[j];

                                if (SECOND_DIFFERENCE == this.#beautifulDifference)
                                    this.#nBeautifulTriplets++;
                                else if (SECOND_DIFFERENCE > this.#beautifulDifference)
                                    break;
                            }
                        }
            }

        getNBeautifulTriplets() {
            return this.#nBeautifulTriplets;
        }
    }
