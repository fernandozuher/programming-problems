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

class Solution {
    myQueue: string[]
    myStack: string[]
    
    constructor() {
        this.myQueue = []
        this.myStack = []
    }

    pushCharacter(ch : string) {this.myStack.push(ch)}

    enqueueCharacter(ch : string) {this.myQueue.push(ch)}

    popCharacter() {return this.myStack.pop()}

    dequeueCharacter() {return this.myQueue.shift()}

    isEmpty() {return this.myStack.length}
}

function main() {
    let s = readLine()
    let obj = new Solution()
    
    for (let ch of s) {
        obj.pushCharacter(ch)
        obj.enqueueCharacter(ch)
    }

    let i = 0
    for ( ; obj.isEmpty() && obj.popCharacter() === obj.dequeueCharacter(); i++);

    const isPalindrome = i < s.length
    console.log("The word, " + s +", is " + (!isPalindrome ? "" : "not ") + "a palindrome.");
}
