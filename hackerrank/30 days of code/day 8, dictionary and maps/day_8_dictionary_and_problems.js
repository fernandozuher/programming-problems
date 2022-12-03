function processData(input) {
    
    const inputSplitted = input.trim().split(/\s+/)
    const n = inputSplitted[0]
    phoneBook = []
    let i, j

    for (i = 1, j = 0; j < n; i+=2, j++)
        phoneBook[inputSplitted[i]] = inputSplitted[i+1]

    for (; i < inputSplitted.length; i++)
        if (phoneBook.hasOwnProperty(inputSplitted[i]))
            console.log(`${inputSplitted[i]}=${phoneBook[inputSplitted[i]]}`)
        else
            console.log("Not found")
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
