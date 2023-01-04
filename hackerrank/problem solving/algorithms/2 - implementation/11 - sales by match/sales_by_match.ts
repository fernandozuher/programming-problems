// Source: https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

'use strict';

import { WriteStream, createWriteStream } from "fs";
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
    readLineAsNumberArray();
    const socks: number[] = readLineAsNumberArray();

    const result = new Result(socks);
}

    function readLineAsNumberArray() {
        const numbers: number[] = readLine().split(" ").map(Number);
        return numbers;
    }

    class Result {
        _socks: number[];
        _pairs: number;

        constructor(socks: number[]) {
            this._socks = [...socks];
            this._pairs = 0;

            this._sockMerchant();
            this.printResult();
        }

            _sockMerchant() {
                const socksPairing = new Map<number, boolean>();

                for (let sock of this._socks) {
                    if (socksPairing.get(sock))
                        this._pairs++;
                    socksPairing.set(sock, !socksPairing.get(sock));
                }
            }
        
            printResult() {
                console.log(this._pairs);
            }
    }
