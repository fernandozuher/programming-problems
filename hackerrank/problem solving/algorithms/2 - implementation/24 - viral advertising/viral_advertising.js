// https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

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

//////////////////////////////////////////////////

function main() {
  const days = +readLine();
  console.log(viralAdvertising(days));
}

function readLine() {
  return inputLines[currentLine++];
}

function viralAdvertising(days) {
  let cumulative = 0;

  for (let shared = 5; days > 0; days--) {
    const liked = Math.trunc(shared / 2);
    cumulative += liked;
    shared = liked * 3;
  }

  return cumulative;
}
