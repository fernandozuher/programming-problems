// https://www.hackerrank.com/challenges/30-queues-stacks/problem?isFullScreen=true

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
    let word = readLine();
    let obj = new QueuesAndStacks();
    
    for (const ch of word) {
        obj.pushCharacter(ch);
        obj.enqueueCharacter(ch);
    }

    checkIfWordIsPalindrome(obj, word);
}

    class QueuesAndStacks {
        private myQueue: string[];
        private myStack: string[];
        
        public constructor() {
            this.myQueue = [];
            this.myStack = [];
        }

        public pushCharacter(ch: string) {
            this.myStack.push(ch);
        }

        public enqueueCharacter(ch: string) {
            this.myQueue.push(ch);
        }

        public popCharacter() {
            return this.myStack.pop();
        }

        public dequeueCharacter() {
            return this.myQueue.shift();
        }
    }

    function checkIfWordIsPalindrome(obj: QueuesAndStacks, word: string) {
        let isPalindrome = true;

        for (let i = 0, len = word.length / 2; i < len; ++i)
            if (obj.popCharacter() != obj.dequeueCharacter()) {
                isPalindrome = false;
                break;
            }

        let notWord: string = isPalindrome ? " " : " not ";
        console.log("The word, " + word + ", is" + notWord + "a palindrome.");
    }
