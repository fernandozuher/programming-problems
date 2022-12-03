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

interface INode {
    data: number;
    next?: INode;
}

class LinkedList {
    
    private head: INode = null

    public insert(data: number): void {

        if (this.head) {
            let start: INode = this.head
            for ( ; start.next; start = start.next);
            start.next = {data: data, next: null}
        }
        else
            this.head = {data: data, next: null}
    }
    
    public printList(): void {
        for (let node = this.head; node; node = node.next)
            process.stdout.write(node.data + ' ')
    }
}

function main() {
    
    let n = +readLine()
    const list = new LinkedList()

    while (n--)
        list.insert(+readLine())

    list.printList()
}
