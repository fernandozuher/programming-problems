// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

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
    let [startingDayNumber, endingDayNumber, divisor]: number[] = readIntArray();
    let obj = new BeautifulDays(startingDayNumber, endingDayNumber, divisor);
    console.log(obj.nBeautifulDays());
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    class BeautifulDays {
        private startingDayNumber: number;
        private endingDayNumber: number;
        private divisor: number;
        private beautifulDaysQuantity: number;

        constructor(startingDayNumber: number, endingDayNumber: number, divisor: number) {
            this.startingDayNumber = startingDayNumber;
            this.endingDayNumber = endingDayNumber;
            this.divisor = divisor;
            this.beautifulDaysQuantity = 0;
            this.calculateBeautifulDaysQuantity();
        }

            private calculateBeautifulDaysQuantity() {
                for (let number = this.startingDayNumber; number <= this.endingDayNumber; ++number) {
                    let reverseNumber: number = this.generateReverseNumber(number);
                    if (this.isDayBeautiful(number, reverseNumber))
                        ++this.beautifulDaysQuantity;
                }
            }

                private generateReverseNumber(number: number): number {
                    let reverseNumber = 0;
                    for (; number > 0; number = Math.trunc(number / 10))
                        reverseNumber = (reverseNumber * 10) + (number % 10);
                    return reverseNumber;
                }

                private isDayBeautiful(number: number, reverseNumber: number): boolean {
                    return Math.abs(number - reverseNumber) % this.divisor == 0;
                }

        public nBeautifulDays(): number {
            return this.beautifulDaysQuantity;
        }
    }
