// https://www.hackerrank.com/challenges/30-binary-trees/problem?isFullScreen=true

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
    let root = null;
    for (let n = +readLine(), data; n--; data = +readLine(), root = Tree.insert(root, data));
    Tree.levelOrder(root);
}

    class Tree {
        public static insert(root: MyNode, data: number) {
            if (!root)
                return new MyNode(data);
            
            if (data <= root.data)
                if (root.left)
                    this.insert(root.left, data);
                else
                    root.left = new MyNode(data);
            else
                if (root.right)
                    this.insert(root.right, data);
                else
                    root.right = new MyNode(data);
            return root;
        }

        public static levelOrder(root: MyNode) {
            if (!root)
                return;

            let myQueue = [];
            myQueue.push(root);
            process.stdout.write(myQueue[0].data + " ");

            for (; myQueue.length; myQueue.shift()) {
                if (myQueue[0].left) {
                    myQueue.push(myQueue[0].left);
                    process.stdout.write(myQueue[0].left.data + " ");
                }

                if (myQueue[0].right) {
                    myQueue.push(myQueue[0].right);
                    process.stdout.write(myQueue[0].right.data + " ");
                }
            }
        }
    }

        class MyNode {
            public data: number;
            public left: MyNode | null;
            public right: MyNode | null;
            public constructor(data: number) {
                this.data = data;
            }
        }
