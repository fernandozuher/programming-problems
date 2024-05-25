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

function main() {
    let n: number = +readLine();
    let array: number[] = readLine().split(' ').map(Number);
    plusMinus(array);
}

    function plusMinus(array: number[]) {
        let [positive, negative, zero]: number[] = [0, 0, 0];

        for (let number of array)
            if (number > 0)
                ++positive;
            else if (number < 0)
                ++negative;
            else
                ++zero;

        let n: number = array.length;
        let positiveProportion: number = positive / n;
        let negativeProportion: number = negative / n;
        let zeroProportion: number = zero / n;
        
        console.log(positiveProportion.toFixed(6));
        console.log(negativeProportion.toFixed(6));
        console.log(zeroProportion.toFixed(6));
    }
