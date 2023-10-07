// https://www.hackerrank.com/challenges/30-linked-list-deletion/problem?isFullScreen=true

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
    let nTests = +readLine();
    let head = null;
    let list = new Solution();

    for (i = 0; i < nTests; ++i) {
        let data = +readLine();
        head = list.insert(head, data);
    }

    head = list.removeDuplicates(head);
    list.display(head);
}

    function MoreLinkedLists() {
        this.insert = function(head, data) {
            let p = new Node(data);

            if (!head)
                head = p;
            else if (!head.next)
                head.next = p;
            else {
                let start = head;
                while (start.next)
                    start = start.next;
                start.next = p;
            }

            return head;
        };

        this.removeDuplicates = function(head) {
            let original = head;
            while (head.next)
                head.data === head.next.data ? (head.next = head.next.next) : (head = head.next);
            return original;
        }

        this.display = function(head) {
            for (let start = head; start;) {
                process.stdout.write(start.data + ' ');
                start = start.next;
            }
        };
    }

        function Node(data) {
            this.data = data;
            this.next = null;
        }
