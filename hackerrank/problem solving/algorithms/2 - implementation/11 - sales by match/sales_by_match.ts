// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

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
    let array: number[] = readIntArray();
    let obj = new SalesByMatch(array);
    console.log(obj.pairs());
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    class SalesByMatch {
        socks: number[];
        nPairs: number;

        constructor(socks: number[]) {
            this.socks = socks;
            this.nPairs = 0;
            this.sockMerchant();
        }

            private sockMerchant() {
                let socksPairing = new Map<number, boolean>();

                for (const sock of this.socks) {
                    if (socksPairing.get(sock))
                        ++this.nPairs;
                    socksPairing.set(sock, !socksPairing.get(sock));
                }
            }

        public pairs(): number {
            return this.nPairs;
        }
    }
