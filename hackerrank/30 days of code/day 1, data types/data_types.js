// https://www.hackerrank.com/challenges/30-data-types/problem?isFullScreen=true

process.stdin.resume();
process.stdin.setEncoding("ascii");

_input = "";

process.stdin.on("data", function(input) {
    _input += input;
});

process.stdin.on("end", function() {
    processData(_input);
});

function main() {
    const I = 4;
    const D = 4.0;
    const S = "HackerRank ";

    const I2 = parseInt(readLine());
    const D2 = parseFloat(readLine());
    const S2 = readLine();

    console.log(I + I2);
    console.log((D + D2).toFixed(1));
    console.log(S + S2);
}
