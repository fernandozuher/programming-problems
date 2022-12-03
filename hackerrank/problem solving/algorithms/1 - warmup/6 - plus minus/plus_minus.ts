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

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

function plusMinus(arr: number[]): void {
    let [positiveQuantity, negativeQuantity, zeroQuantity]: number[] = [0, 0, 0];

    for (let number of arr)
        if (number > 0)
            positiveQuantity++;
        else if (number < 0)
            negativeQuantity++;
        else
            zeroQuantity++;

    const n: number = arr.length;
    const positiveValuesProportion: number = positiveQuantity / n;
    const negativeValuesProportion: number = negativeQuantity / n;
    const zeroValuesProportion: number = zeroQuantity / n;
    
    console.log(positiveValuesProportion.toFixed(6));
    console.log(negativeValuesProportion.toFixed(6));
    console.log(zeroValuesProportion.toFixed(6));
}

function main() {
    const n: number = parseInt(readLine().trim(), 10);

    const arr: number[] = readLine().replace(/\s+$/g, '').split(' ').map(arrTemp => parseInt(arrTemp, 10));

    plusMinus(arr);
}
