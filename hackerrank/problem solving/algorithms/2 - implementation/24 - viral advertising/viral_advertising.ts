// https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

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
    let days: number = +readLine();
    console.log(viralAdvertising(days));
}

    function viralAdvertising(days: number): number {
        let [shared, liked, cumulative]: number[] = [5, 0, 0];

        while (days--) {
            liked = Math.trunc(shared / 2);
            cumulative += liked;
            shared = liked * 3;
        }

        return cumulative;
    }
