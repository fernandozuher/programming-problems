// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

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
    let array: number[] = readIntArray();
    let [positiveProportion, negativeProportion, zeroProportion]: number[] = plusMinus(array);
    console.log(positiveProportion.toFixed(6));
    console.log(negativeProportion.toFixed(6));
    console.log(zeroProportion.toFixed(6));
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    function plusMinus(array: number[]): number[] {
        let [positive, negative, zero] = [0, 0, 0];

        for (let x of array)
            if (x > 0)
                ++positive;
            else if (x < 0)
                ++negative;
            else
                ++zero;

        let n: number = array.length;
        let positiveProportion: number = positive / n;
        let negativeProportion: number = negative / n;
        let zeroProportion: number = zero / n;
        
        return [positiveProportion, negativeProportion, zeroProportion];
    }
