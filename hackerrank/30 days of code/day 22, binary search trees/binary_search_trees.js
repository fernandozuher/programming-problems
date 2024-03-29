// https://www.hackerrank.com/challenges/30-binary-search-trees/problem?isFullScreen=true

process.stdin.resume();
process.stdin.setEncoding('ascii');
let _input = "";

process.stdin.on('data', function(data) {
    _input += data;
});

function main() {
    let tree = new BinarySearchTree();
    let root = null;
    let values = _input.split('\n').map(Number);

    for (let x of values)
        root = tree.insert(root, x);

    console.log(tree.getHeight(root));
}

    function BinarySearchTree() {
        this.insert = function(root, data) {
            if (!root) {
                this.root = new Node(data);
                return this.root;
            }

            if (data <= root.data) {
                if (root.left)
                    this.insert(root.left, data);
                else
                    root.left = new Node(data);
            }
            else {
                if (root.right)
                    this.insert(root.right, data);
                else
                    root.right = new Node(data);
            }

            return this.root;
        };

        this.getHeight = function(root) {
// Immutable HackerRank code above

            arguments.callee.currentHeight = arguments.callee.currentHeight || 0;
            arguments.callee.maxHeight = arguments.callee.maxHeight || 0;
            
            if (root.left || root.right) {
                arguments.callee.currentHeight++;
                
                if (root.left)
                    this.getHeight(root.left);
                
                if (root.right)
                    this.getHeight(root.right);
                
                arguments.callee.currentHeight--;

            }
            else if (arguments.callee.currentHeight > arguments.callee.maxHeight)
                arguments.callee.maxHeight = arguments.callee.currentHeight;
            
            return arguments.callee.maxHeight;
        };
    };

// Immutable HackerRank code below
        function Node(data) {
            this.data = data;
            this.left = null;
            this.right = null;
        };
