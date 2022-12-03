process.stdin.resume();
process.stdin.setEncoding('ascii');

let input_stdin = "";
let input_stdin_array = "";
let input_currentline = 0;

process.stdin.on('data', function (data) {
    input_stdin + = data;
});

process.stdin.on('end', function () {
    input_stdin_array = input_stdin.split("\n");
    main();    
});

function readLine() {
    return input_stdin_array[input_currentline++];
}

function Node(data) {
    this.data = data;
    this.next = null;
}

function Solution() {

    this.insert = function(head, data) {

        let start
        if (head) {
            start = head
            for ( ; start.next; start = start.next);
            start.next = new Node(data)
        }
        else {
            start = new Node(data)
            head = start
        }

        return head
    }

    this.display = function(head) {

        let start = head;
            while (start) {
                process.stdout.write(start.data + " ");
                start = start.next;
            }
    };
}

function main() {
    let T = +readLine();
    let head = null;
    let mylist = new Solution();

    while (T--)
        head = mylist.insert(head, +readLine());

    mylist.display(head);
}
