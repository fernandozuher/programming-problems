// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

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
  readLine();
  const a = readNumbers();
  const b = readNumbers();
  console.log(betweenTwoSets(a, b));
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function betweenTwoSets(a, b) {
  const lcmOfA = lcmArray(a);
  const gcdOfB = gcdArray(b);

  let count = 0;
  for (let i = lcmOfA; i <= gcdOfB; i += lcmOfA) {
    if (gcdOfB % i === 0) count++;
  }
  return count;
}

function lcmArray(arr) {
  return arr.reduce(lcm);
}

function lcm(a, b) {
  return (a * b) / gcd(a, b);
}

function gcdArray(arr) {
  return arr.reduce(gcd);
}

function gcd(a, b) {
  while (b !== 0) {
    const t = b;
    b = a % b;
    a = t;
  }
  return a;
}
