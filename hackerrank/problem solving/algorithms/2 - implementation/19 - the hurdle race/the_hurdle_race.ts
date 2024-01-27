// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

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

////////////////////////////////////////////////

function main() {
    let [n, maximumHeightCanJump]: number[] = readIntArray();
    let hurdlesHeights: number[] = readIntArray();
    let obj = new HurdleRace(hurdlesHeights, maximumHeightCanJump);
    console.log(obj.doses());
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    class HurdleRace {
        private hurdlesHeights: number[];
        private maximumHeightCanJump: number;
        private nDoses: number;

        constructor(hurdlesHeights: number[], maximumHeightCanJump: number) {
            this.hurdlesHeights = hurdlesHeights;
            this.maximumHeightCanJump = maximumHeightCanJump;
            this.nDoses = 0;
            this.hurdleRace();
        }

            private hurdleRace() {
                let highestHurdle: number = Math.max(...this.hurdlesHeights)
                this.nDoses = highestHurdle > this.maximumHeightCanJump ? highestHurdle - this.maximumHeightCanJump : 0;
            }

        public doses(): number {
            return this.nDoses;
        }
    }
