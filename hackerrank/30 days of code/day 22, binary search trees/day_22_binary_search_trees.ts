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

class myNode {
    data: number
    left: myNode | null
    right: myNode | null
    
    constructor(data: number) {
        this.data = data
    }
}

class Tree {

    static currentHeight = 0
    static maxHeight = 0

    static insert(root: myNode, data : number) : myNode {
        if (root === null) {
            root = new myNode(data)
            return root;
        }
        
        if (data <= root.data) {
            if (root.left)
                this.insert(root.left, data);
            else
                root.left = new myNode(data)
        }
        else {
            if (root.right)
                this.insert(root.right, data);
            else
                root.right = new myNode(data)
        }
        
        return root;
    }

    static getHeight(root: myNode) : number {

        if (root.left || root.right) {
            this.currentHeight++
            if (root.left)
                this.getHeight(root.left)
            if (root.right)
                this.getHeight(root.right)
            this.currentHeight--
        }
        else if (this.currentHeight > this.maxHeight)
            this.maxHeight = this.currentHeight
        
        return this.maxHeight
    }

    static resetHeight() {
        this.currentHeight = 0
        this.maxHeight = 0
    }
}

function main() {
    
    let root: myNode = null
    
    for (let n = +readLine(); n--; )
        root = Tree.insert(root, +readLine())
    
    Tree.resetHeight()
    console.log(Tree.getHeight(root))
}
