// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function (inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function () {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine() {
    return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
    const [_, n] = readIntArray();
    findMaximumAffordableWidthsVehiclesWhileReadTestCases(n, readIntArray()).forEach(x => console.log(x));
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    function findMaximumAffordableWidthsVehiclesWhileReadTestCases(n, widthMeasurements) {
        return Array(n).fill(0).map(_ => maximumAffordableWidthVehicleInRange(widthMeasurements, readIntArray()));
    }

        function maximumAffordableWidthVehicleInRange(widthMeasurements, point) {
            return Math.min(...(widthMeasurements.slice(point[0], point[1] + 1)));
        }
