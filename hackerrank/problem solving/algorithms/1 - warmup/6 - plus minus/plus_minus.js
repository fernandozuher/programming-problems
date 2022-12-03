'use strict';
process.stdin.resume();
process.stdin.setEncoding('utf-8');
let inputString = '';
let currentLine = 0;
process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});
process.stdin.on('end', function() {
    inputString = inputString.split('\n');
    main();
});

function readLine() {
    return inputString[currentLine++];
}
/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
function plusMinus(arr) {
    let [positiveQuantity, negativeQuantity, zeroQuantity] = [0, 0, 0];

    for (let number of arr)
        if (number > 0)
            positiveQuantity++;
        else if (number < 0)
            negativeQuantity++;
        else
            zeroQuantity++;

    const n = arr.length;
    const positiveValuesProportion = positiveQuantity / n;
    const negativeValuesProportion = negativeQuantity / n;
    const zeroValuesProportion = zeroQuantity / n;
    
    console.log(positiveValuesProportion.toFixed(6));
    console.log(negativeValuesProportion.toFixed(6));
    console.log(zeroValuesProportion.toFixed(6));
}

function main() {
    const n = parseInt(readLine().trim(), 10);
    const arr = readLine().replace(/\s+$/g, '').split(' ').map(arrTemp => parseInt(arrTemp, 10));
    plusMinus(arr);
}
