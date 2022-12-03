// Start of function Node
function Node(data) {
    this.data = data;
    this.left = null;
    this.right = null;
}; // End of function Node

// Start of function BinarySearchTree
function BinarySearchTree() {
    this.insert = function(root, data) {
        if (root === null) {
            this.root = new Node(data);
            
            return this.root;
        }
        
        if (data <= root.data) {
            if (root.left) {
                this.insert(root.left, data);
            } else {
                root.left = new Node(data);
            }
        } else {
            if (root.right) {
                this.insert(root.right, data);
            } else {
                root.right = new Node(data);
            }
        }
        
        return this.root;
    };
    
    // Start of function getHeight
    this.getHeight = function(root) {
        // Immutable HackerRank code above
        
        arguments.callee.currentHeight = arguments.callee.currentHeight || 0
        arguments.callee.maxHeight = arguments.callee.maxHeight || 0

        if (root.left || root.right) {
            arguments.callee.currentHeight++
            if (root.left)
                this.getHeight(root.left)
            if (root.right)
                this.getHeight(root.right)
            arguments.callee.currentHeight--
        }
        else if (arguments.callee.currentHeight > arguments.callee.maxHeight)
            arguments.callee.maxHeight = arguments.callee.currentHeight
        
        return arguments.callee.maxHeight

    // Immutable HackerRank code below
    }; // End of function getHeight
}; // End of function BinarySearchTree

process.stdin.resume();
process.stdin.setEncoding('ascii');

var _input = "";

process.stdin.on('data', function (data) {
    _input += data;
});

process.stdin.on('end', function () {
    var tree = new BinarySearchTree();
    var root = null;
    
    var values = _input.split('\n').map(Number);
    
    for (var i = 1; i < values.length; i++) {
        root = tree.insert(root, values[i]);
    }
    
    console.log(tree.getHeight(root));
});