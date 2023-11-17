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
        let [positiveQuantity, negativeQuantity, zeroQuantity]: number[] = [0, 0, 0];

        for (let number of array)
            if (number > 0)
                ++positiveQuantity;
            else if (number < 0)
                ++negativeQuantity;
            else
                ++zeroQuantity;

        let n: number = array.length;
        let positiveValuesProportion: number = positiveQuantity / n;
        let negativeValuesProportion: number = negativeQuantity / n;
        let zeroValuesProportion: number = zeroQuantity / n;
        
        console.log(positiveValuesProportion.toFixed(6));
        console.log(negativeValuesProportion.toFixed(6));
        console.log(zeroValuesProportion.toFixed(6));
    }
