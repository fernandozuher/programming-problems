function processData(input) {
    list = input.split('\n').map(Number)

    for (let number of list.slice(1)) {
        if (number == 1) {
            console.log("Not prime")
            continue
        }

        let i = 2, limit = Math.sqrt(number);
        for (; i <= limit; i++)
            if (!(number % i)) {
                console.log("Not prime")
                break
            }

        if (i > limit)
            console.log("Prime")
    }
} 

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";

process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input);
});

