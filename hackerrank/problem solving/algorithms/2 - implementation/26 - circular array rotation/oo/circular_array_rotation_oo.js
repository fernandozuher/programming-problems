// Source: https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

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
    const INPUT = readInput();
    const OBJ = new CircularArrayRotation(INPUT);
    OBJ.printRotatedArrayElementsAccordingToQueries();
}

    function readInput() {
        const [ARRAY_SIZE, ROTATION_COUNT, QUERIES_SIZE] = readLineAsNumericArray();
        const ARRAY = readLineAsNumericArray();
        const QUERIES = readQueries(QUERIES_SIZE);
        const INPUT = [ARRAY, ARRAY_SIZE, ROTATION_COUNT, QUERIES, QUERIES_SIZE];
        return INPUT;
    }

        function readLineAsNumericArray() {
            const ARRAY = readLine().split(" ").map(Number);
            return ARRAY;
        }

        function readQueries(size) {
            const ARRAY = new Array(size).fill().map(element => +readLine());
            return ARRAY;
        }

    class CircularArrayRotation {
        #array;
        #arraySize;
        #rotationCount;
        #queries;
        #querySize;

        constructor(input) {
            this.#array = input[0];
            this.#arraySize = input[1];
            this.#rotationCount = input[2];
            this.#queries = input[3];
            this.#querySize = input[4];

            this.#reduceInputRotations();
            this.#rotateInputArray();
        }
        
            #reduceInputRotations() {
                if (this.#arraySize > 1)
                    this.#rotationCount = this.#rotationCount >= this.#arraySize ? this.#rotationCount % this.#arraySize : this.#rotationCount;
                else
                    this.#rotationCount = 0;
            }

            #rotateInputArray() {
                const FIRST_PART_NEW_ARRAY = this.#array.slice(this.#arraySize - this.#rotationCount, this.#arraySize);
                const SECOND_PART_NEW_ARRAY = this.#array.slice(0, this.#arraySize - this.#rotationCount);
                const NEW_ARRAY = [...FIRST_PART_NEW_ARRAY, ...SECOND_PART_NEW_ARRAY];

                this.#array = NEW_ARRAY;
            }

        printRotatedArrayElementsAccordingToQueries() {
            this.#queries.forEach(query => console.log(this.#array[query]));
        }
    }
