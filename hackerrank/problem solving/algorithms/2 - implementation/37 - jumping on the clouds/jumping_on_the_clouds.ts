// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

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
    let n: number = +readLine();
    let clouds: number[] = readLine().split(' ').map(Number);
    console.log(minimumNumberOfJumps(clouds));
}

    function minimumNumberOfJumps(clouds: number[]): number {
        let jumps = 0;
        for (let i = 0, size = clouds.length - 1; i < size; ++jumps)
            i += nextJump(i, clouds);
        return jumps;
    }

        function nextJump(index: number, clouds: number[]): number {
            let isNextSecondCloudCumulus = false;
            if (index + 2 < clouds.length)
                isNextSecondCloudCumulus = clouds[index + 2] == 0;
            return isNextSecondCloudCumulus ? 2 : 1;
        }
