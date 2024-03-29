// https://www.hackerrank.com/challenges/30-binary-trees/problem?isFullScreen=true

process.stdin.resume();
process.stdin.setEncoding('ascii');
let _input = "";

process.stdin.on('data', function(data) {
    _input += data;
});

process.stdin.on('end', function() {
    let tree = new BinarySearchTree();
    let root = null;
    let values = _input.split('\n').map(Number);

    for (let i = 1; i < values.length; ++i)
        root = tree.insert(root, values[i]);

    tree.levelOrder(root);
});

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
            } else {
                if (root.right)
                    this.insert(root.right, data);
                else
                    root.right = new Node(data);
            }

            return this.root;
        };

        this.levelOrder = function(root) {
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
        };
    };

        function Node(data) {
            this.data = data;
            this.left = null;
            this.right = null;
        };
