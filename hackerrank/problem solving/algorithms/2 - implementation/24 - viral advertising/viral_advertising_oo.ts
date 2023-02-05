// Source: https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

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
    const days: number = +readLine();
    const cumulativeLikes: ViralAdvertising = new ViralAdvertising(days);
}

    class ViralAdvertising {
        private _days: number;
        private _cumulativeLikes: number;

        constructor(days: number) {
            this._days = days;
            this._cumulativeLikes = 0;
        
            this._viralAdvertising();
            this.printCumulativeLikes();
        }

        _viralAdvertising() {
            let [shared, liked, cumulative]: number[] = [5, 0, 0];

            for (let _ = 0; _ < this._days; _++) {
                liked = Math.trunc(shared / 2);
                this._cumulativeLikes += liked;
                shared = liked * 3;
            }
        }

        printCumulativeLikes() {
            console.log(this._cumulativeLikes);
        }
    }
