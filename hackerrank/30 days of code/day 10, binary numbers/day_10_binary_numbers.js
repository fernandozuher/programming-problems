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

function main() {
    
    let n = parseInt(readLine().trim(), 10)
    let max_ones = 0, ones
        
    for (ones = 0; n > 0; n = Math.floor(n/2)) {
        if (n % 2 == 1)
            ++ones
        else {
            if (ones > max_ones)
                max_ones = ones
            ones = 0
        }
    }

    console.log(ones > max_ones ? ones : max_ones)
}
