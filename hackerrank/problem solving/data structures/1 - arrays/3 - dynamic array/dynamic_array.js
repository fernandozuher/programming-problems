// https://www.hackerrank.com/challenges/dynamic-array/problem?isFullScreen=true

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
    let [n, nQueries] = readIntArray();
    let obj = new DynamicArray(n);

    while (nQueries--)
        obj.handleQuery(readIntArray());
    obj.answers().forEach(x => console.log(x));
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    class DynamicArray {
        #n;
        #array;
        #answers;
        #lastAnswer;

        constructor(n) {
            this.#n = n;
            this.#array = new Array(n).fill([]).map(x => []);
            this.#answers = [];
            this.#lastAnswer = 0;
        }

        handleQuery(queries) {
            const [type, x, y] = queries
            let index = (x ^ this.#lastAnswer) % this.#n;

            if (type === 1)
                this.#array[index].push(y);
            else {
                let j = y % this.#array[index].length;
                this.#lastAnswer = this.#array[index][j];
                this.#answers.push(this.#lastAnswer);
            }
        }

        answers() {
            return this.#answers;
        }
    }
