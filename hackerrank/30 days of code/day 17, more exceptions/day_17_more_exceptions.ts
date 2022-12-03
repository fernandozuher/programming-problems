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

class Calculator {
    
    power(n: number, p: number) : number {
        if (n < 0 || p < 0)
            throw "n and p should be non-negative"
        return Math.pow(n, p)
    }
}

function main() {

    for (let n = +readLine(), myCalculator = new Calculator(); n--; ) {

        let [n, p] = readLine().split(" ").map(Number);

        try {
            let ans = myCalculator.power(n, p);
            console.log(ans);
        }
        catch (e) {
            console.log(e);
        }
    }
}
