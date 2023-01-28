// Source: https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

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
    const [startingDayNumber, endingDayNumber, divisor]: number[] = readLineAsNumberArray();
    const beautifulDays: BeautifulDays = new BeautifulDays(startingDayNumber, endingDayNumber, divisor);
}

    function readLineAsNumberArray(): number[] {
        const inputLine: number[] = readLine().split(" ").map(Number);
        return inputLine;
    }

    class BeautifulDays {
        private _startingDayNumber: number;
        private _endingDayNumber: number;
        private _divisor: number;
        private _nBeautifulDays: number;
        
        constructor(startingDayNumber: number, endingDayNumber: number, divisor: number) {
            this._startingDayNumber = startingDayNumber;
            this._endingDayNumber = endingDayNumber;
            this._divisor = divisor;
            this._nBeautifulDays = 0;
        
            this._beautifulDays();
            this.printNBeautifulDays();
        }
        
            private _beautifulDays() {
                for (let dayNumber = this._startingDayNumber; dayNumber <= this._endingDayNumber; dayNumber++) {
                    const reverseNumber = this._generateReverseNumber(dayNumber);

                    if (this._isDayBeautiful(dayNumber, reverseNumber))
                        this._nBeautifulDays++;
                }
            }
            
                private _generateReverseNumber(dayNumber: number): number {
                    let reverseNumber = 0;
                    for (; dayNumber > 0; dayNumber = Math.trunc(dayNumber / 10))
                        reverseNumber = (reverseNumber * 10) + (dayNumber % 10);
                    return reverseNumber;
                }
                
                private _isDayBeautiful(number: number, reverseNumber: number): boolean {
                    const beautifulDay = Math.abs(number - reverseNumber) % this._divisor == 0;
                    return beautifulDay;
                }
            
            printNBeautifulDays() {
                console.log(this._nBeautifulDays);
            }
    }
