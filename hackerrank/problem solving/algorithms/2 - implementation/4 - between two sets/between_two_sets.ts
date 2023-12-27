// Source: https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

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
    readIntArray();
    let setA: number[] = readIntArray();
    let setB: number[] = readIntArray();
    let result = new Result(setA, setB);
    console.log(result.totalFactors());
}

    function readIntArray() {
        return readLine().split(" ").map(Number);
    }

    class Result {
        private setA: number[];
        private setB: number[];
        private potentialFactors: number[];
        private factors: number;

        public constructor(setA: number[], setB: number[]) {
            this.setA = [...setA];
            this.setB = [...setB];
            this.potentialFactors = new Array();
            this.factors = 0;

            this.findFactors();
        }

            private findFactors() {
                this.findNumbersDivisibleBySetA();
                this.findFactorsOfSetB();
                this.countFactors();
            }

                private findNumbersDivisibleBySetA() {
                    let lastElementOfSetA: number = this.setA[this.setA.length - 1];

                    for (let potentialFactor = lastElementOfSetA; potentialFactor <=this.setB[0]; potentialFactor += lastElementOfSetA) {
                        let isARealPotentialFactor = true;

                        for (let elementA of this.setA)
                            if (potentialFactor % elementA) {
                                isARealPotentialFactor = false;
                                break;
                            }

                        if (isARealPotentialFactor)
                            this.potentialFactors.push(potentialFactor);
                    }
                }

                private findFactorsOfSetB() {
                    for (let elementB of this.setB)
                        for (let [i, potentialFactor] of this.potentialFactors.entries())
                            if (potentialFactor && elementB % potentialFactor)
                                this.potentialFactors[i] = 0;
                }

                private countFactors() {
                    this.factors = this.potentialFactors.reduce((sum, item) => item != 0 ? ++sum : sum, 0);
                }
            
            public totalFactors(): number {
                return this.factors;
            }
    }
