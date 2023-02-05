// Source: https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

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
    const days = +readLine();
    const cumulativeLikes = new ViralAdvertising(days);
}

    class ViralAdvertising {
        #days;
        #cumulativeLikes;

        constructor(days) {
            this.#days = days;
            this.#cumulativeLikes = 0;
        
            this.#viralAdvertising();
            this.printCumulativeLikes();
        }

        #viralAdvertising() {
            let [shared, liked, cumulative] = [5, 0, 0];

            for (let _ = 0; _ < this.#days; _++) {
                liked = Math.trunc(shared / 2);
                this.#cumulativeLikes += liked;
                shared = liked * 3;
            }
        }

        printCumulativeLikes() {
            console.log(this.#cumulativeLikes);
        }
    }
