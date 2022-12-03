process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_stdin_array = "";
var input_currentline = 0;

process.stdin.on('data', function (data) {
    input_stdin += data;
});

process.stdin.on('end', function () {
    input_stdin_array = input_stdin.split("\n");
    main();    
});

function readLine() {
    return input_stdin_array[input_currentline++];
}

function Calculator() {
    this.power = (n, p) => {
        if (n < 0 || p < 0)
            throw "n and p should be non-negative"
        return Math.pow(n, p)
    }
}

function main() {

    let myCalculator = new Calculator();
    let T = parseInt(readLine());

    while (T-- > 0) {
        let num = (readLine().split(" "));
        try {
            let n = parseInt(num[0]);
            let p = parseInt(num[1]);
            let ans = myCalculator.power(n,p);
            console.log(ans);
        }
        catch(e) {
            console.log(e);
        }
    }
}
