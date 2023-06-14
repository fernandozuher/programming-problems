// Source: https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

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


function main() {
    const [SIZE, BEAUTIFUL_DIFFERENCE]: Array<number> = readAnArray();
    const ARRAY: Array<number> = readAnArray();

    const OBJ: BeautifulTriplets = new BeautifulTriplets(ARRAY, BEAUTIFUL_DIFFERENCE);
    console.log(OBJ.getNBeautifulTriplets());
}

    function readAnArray(): Array<number> {
        const ARRAY: Array<number> = readLine().split(" ").map(Number);
        return ARRAY;
    }

    class BeautifulTriplets {
        private array: Array<number>;
        private beautifulDifference: number;
        private nBeautifulTriplets: number;

        constructor(array: Array<number>, beautifulDifference: number) {
            this.array = array;
            this.beautifulDifference = beautifulDifference;
            this.findBeautifulTriplets();
        }

            private findBeautifulTriplets() {
                this.nBeautifulTriplets = 0;

                if (this.array.length > 2)
                    for (let i = 0; i < this.array.length-2; i++)
                        for (let j = i + 1; j < this.array.length-1; j++) {
                            const FIRST_DIFFERENCE: number = this.array[j] - this.array[i];

                            if (FIRST_DIFFERENCE < this.beautifulDifference)
                                continue;
                            else if (FIRST_DIFFERENCE > this.beautifulDifference)
                                break;

                            for (let k = j + 1; k < this.array.length; k++) {
                                const SECOND_DIFFERENCE: number = this.array[k] - this.array[j];

                                if (SECOND_DIFFERENCE == this.beautifulDifference)
                                    this.nBeautifulTriplets++;
                                else if (SECOND_DIFFERENCE > this.beautifulDifference)
                                    break;
                            }
                        }
            }

        public getNBeautifulTriplets(): number {
            return this.nBeautifulTriplets;
        }
    }
