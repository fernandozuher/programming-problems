// https://www.hackerrank.com/challenges/30-hello-world/problem?isFullScreen=true

function processData(inputString) {
    console.log("Hello, World.");
    console.log(inputString);
}

process.stdin.resume();
process.stdin.setEncoding("ascii");

_input = "";

process.stdin.on("data", function(input) {
    _input += input;
});

process.stdin.on("end", function() {
    processData(_input);
});
