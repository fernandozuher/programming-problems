// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function (inputStdin: string): void {
    inputString += inputStdin;
});

process.stdin.on('end', function (): void {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine(): string {
    return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
    readIntArray();
    let setA: number[] = readIntArray();
    let setB: number[] = readIntArray();
    let obj = new BetweenTwoSets(setA, setB);
    obj.findFactors();
    console.log(obj.totalFactors());
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }
    
    class BetweenTwoSets {
        private readonly setA: number[];
        private readonly setB: number[];
        private readonly potentialFactors: number[];
        private factors: number;
    
        public constructor(setA: number[], setB: number[]) {
            this.setA = setA;
            this.setB = setB;
            this.potentialFactors = [];
            this.factors = 0;
        }
    
        public findFactors() {
            this.findNumbersDivisibleBySetA();
            this.findFactorsOfSetB();
            this.countFactors();
        }
    
            private findNumbersDivisibleBySetA() {
                for (let potentialFactor = this.setA.at(-1); potentialFactor <= this.setB[0]; potentialFactor += this.setA.at(-1)) {
                    let isARealPotentialFactor = true;
        
                    for (let x of this.setA)
                        if (potentialFactor % x) {
                            isARealPotentialFactor = false;
                            break;
                        }
        
                    if (isARealPotentialFactor)
                        this.potentialFactors.push(potentialFactor);
                }
            }
        
            private findFactorsOfSetB() {
                for (let x of this.setB)
                    for (let [i, potentialFactor] of this.potentialFactors.entries())
                        if (potentialFactor && x % potentialFactor)
                            this.potentialFactors[i] = 0;
            }
        
            private countFactors() {
                this.factors = this.potentialFactors.filter(x => x).length;
            }
    
        public totalFactors(): number {
            return this.factors;
        }
    }
