// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

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
    let array: number[] = readIntArray();
    console.log(kangaroo(array));
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }
    
    function kangaroo(array: number[]): string {
        let [x1, v1, x2, v2]: number[] = [...array];
        if (v2 >= v1)
            return 'NO';
        for (; x1 < x2; x1 += v1, x2 += v2);
        return x1 === x2 ? 'YES' : 'NO';
    }
