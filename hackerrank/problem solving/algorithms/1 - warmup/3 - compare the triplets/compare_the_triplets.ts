// 

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
    let array1: number[] = readAnIntArray();
    let array2: number[] = readAnIntArray();
    let result: number[] = compareTriplets(array1, array2);
    console.log(result.join(' '));
}

    function readAnIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    function compareTriplets(array1: number[], array2: number[]): number[] {
        let [player1, player2]: number[] = [0, 0];
        
        for (let i in array1)
            if (array1[i] > array2[i])
                player1++;
            else if (array1[i] < array2[i])
                player2++;
        
        return [player1, player2];
    }
