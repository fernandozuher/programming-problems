// https://www.hackerrank.com/challenges/30-linked-list-deletion/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function(inputStdin: string): void {
    inputString += inputStdin;
});

process.stdin.on('end', function(): void {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine(): string {
    return inputLines[currentLine++];
}

function main() {
    let myNode: MyNode = new MyNode();
    let head = myNode;

    for (let n = +readLine(); n--; myNode = myNode.next)
        myNode.next = new MyNode(+readLine());
    head = head.next;

    MyStaticListFunctions.removeDuplicates(head);
    MyStaticListFunctions.display(head);
}

    class MyNode {
        data: number;
        next: MyNode;

        constructor(data: number = 0) {
            this.data = data;
            this.next = null;
        }
    }

    namespace MyStaticListFunctions {
        export function removeDuplicates(head: MyNode) {
            while (head.next)
                head.data == head.next.data ? (head.next = head.next.next) : (head = head.next);
        }

        export function display(head: MyNode) {
            for (; head; head = head.next)
                process.stdout.write(head.data + ' ');
        }
    }
