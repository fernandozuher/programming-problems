// https://www.hackerrank.com/challenges/30-linked-list/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine() {
    return inputLines[currentLine++];
}

function main() {
    let T = +readLine();
    let head = null;
    let mylist = new Solution();

    while (T--)
        head = mylist.insert(head, +readLine());

    mylist.display(head);
}

    function Node(data) {
        this.data = data;
        this.next = null;
    }

    function Solution() {
        this.insert = function(head, data) {
            let start;
            if (head) {
                start = head;
                for ( ; start.next; start = start.next);
                start.next = new Node(data);
            }
            else {
                start = new Node(data);
                head = start;
            }

            return head;
        }

        this.display = function(head) {
            let start = head;
            while (start) {
                process.stdout.write(start.data + ' ');
                start = start.next;
            }
        };
    }
