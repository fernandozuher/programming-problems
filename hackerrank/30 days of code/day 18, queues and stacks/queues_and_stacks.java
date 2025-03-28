// https://www.hackerrank.com/challenges/30-queues-stacks/problem?isFullScreen=true

import java.util.*;

class Solution {
    private static final Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        String word = scan.nextLine();
        QueueAndStack obj = initQueueAndStack(word);
        checkIfPalindrome(obj, word);
    }

    private static QueueAndStack initQueueAndStack(String word) {
        var obj = new QueueAndStack();
        for (char c : word.toCharArray()) {
            obj.enqueueCharacter(c);
            obj.pushCharacter(c);
        }
        return obj;
    }

    private static void checkIfPalindrome(QueueAndStack obj, String word) {
        boolean isPalindrome = true;

        for (int halfLength = word.length() / 2; halfLength-- > 0;)
            if (obj.dequeueCharacter() != obj.popCharacter()) {
                isPalindrome = false;
                break;
            }

        String notWord = isPalindrome ? " " : " not ";
        System.out.println("The word, " + word + ", is" + notWord + "a palindrome.");
    }
}

class QueueAndStack {
    private Queue<Character> myQueue;
    private Stack<Character> myStack;

    public QueueAndStack() {
        myQueue = new LinkedList<>();
        myStack = new Stack<>();
    }

    public void enqueueCharacter(char ch) {
        myQueue.add(ch);
    }

    public void pushCharacter(char ch) {
        myStack.push(ch);
    }

    public char dequeueCharacter() {
        return myQueue.poll();
    }

    public char popCharacter() {
        return myStack.pop();
    }
}
