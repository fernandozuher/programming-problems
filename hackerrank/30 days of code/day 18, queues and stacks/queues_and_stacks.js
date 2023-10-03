// https://www.hackerrank.com/challenges/30-queues-stacks/problem?isFullScreen=true

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
    let word = readLine();
    let obj = new QueuesAndStacks();
    
    for (const ch of word) {
        obj.pushCharacter(ch);
        obj.enqueueCharacter(ch);
    }

    checkIfWordIsPalindrome(obj, word);
}

    function QueuesAndStacks() {
        this.myQueue = [];
        this.myStack = [];
     
        this.pushCharacter = ch => this.myStack.push(ch);
        this.enqueueCharacter = ch => this.myQueue.push(ch);
     
        this.popCharacter = () => {
            return this.myStack.pop();
        }
     
        this.dequeueCharacter = () => {
            return this.myQueue.shift();
        }
    }
    
    function checkIfWordIsPalindrome(obj, word) {
        let isPalindrome = true;

        for (let i = 0, len = word.length / 2; i < len; ++i)
            if (obj.popCharacter() != obj.dequeueCharacter()) {
                isPalindrome = false;
                break;
            }

        let notWord = isPalindrome ? " " : " not ";
        console.log("The word, " + word + ", is" + notWord + "a palindrome.");
    }
