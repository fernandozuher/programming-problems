// https://www.hackerrank.com/challenges/dynamic-array/problem?isFullScreen=true

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
    let [n, nQueries]: number[] = readIntArray();
    let obj = new DynamicArray(n);

    while (nQueries--)
        obj.handleQuery(readIntArray());
    obj.answers().forEach(x => console.log(x));
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    class DynamicArray {
        private n: number;
        private array: number[][];
        private answersToQueries: number[];
        private lastAnswer: number;

        constructor(n: number) {
            this.n = n;
            this.array = new Array(n).fill([]).map(x => []);
            this.answersToQueries = [];
            this.lastAnswer = 0;
        }

        public handleQuery(queries: number[]) {
            const [type, x, y]: number[] = queries
            let index: number = (x ^ this.lastAnswer) % this.n;

            if (type === 1)
                this.array[index].push(y);
            else {
                let j: number = y % this.array[index].length;
                this.lastAnswer = this.array[index][j];
                this.answersToQueries.push(this.lastAnswer);
            }
        }

        public answers(): number[] {
            return this.answersToQueries;
        }
    }
