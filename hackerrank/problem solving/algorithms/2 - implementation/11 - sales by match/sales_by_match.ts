// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function (inputStdin: string): void {
    inputString += inputStdin;
});

process.stdin.on('end', function (): void {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine(): string {
    return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
    readLine();
    let array: number[] = readIntArray();
    console.log(sockMerchant(array));
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    function sockMerchant(socks: number[]): number {
        let pairs = 0;
        let socksPairing = new Map<number, boolean>();

        for (const sock of socks) {
            if (socksPairing.get(sock))
                ++pairs;
            socksPairing.set(sock, !socksPairing.get(sock));
        }

        return pairs;
    }
