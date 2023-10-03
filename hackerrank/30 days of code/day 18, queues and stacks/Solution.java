// https://www.hackerrank.com/challenges/30-queues-stacks/problem?isFullScreen=true

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class Solution {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String word = scan.nextLine();
        QueuesAndStacks obj = new QueuesAndStacks();

        for (char c : word.toCharArray()) {
            obj.pushCharacter(c);
            obj.enqueueCharacter(c);
        }

        checkIfWordIsPalindrome(obj, word);
    }

    public static void checkIfWordIsPalindrome(QueuesAndStacks obj, final String word) {
        boolean isPalindrome = true;

        for (int i = 0, len = word.length() / 2; i < len; ++i)
            if (obj.popCharacter() != obj.dequeueCharacter()) {
                isPalindrome = false;
                break;
            }

        String notWord = isPalindrome ? " " : " not ";
        System.out.println( "The word, " + word + ", is" + notWord + "a palindrome.");
    }
}

    class QueuesAndStacks {
        private Stack<Character> myStack;
        private Queue<Character> myQueue;

        public QueuesAndStacks() {
            myStack = new Stack<Character>();
            myQueue = new LinkedList<Character>();
        }

        public void pushCharacter(final char ch) {
            myStack.push(ch);
        }

        public void enqueueCharacter(final char ch) {
            myQueue.add(ch);
        }

        public char popCharacter() {
            return myStack.pop();
        }

        public char dequeueCharacter() {
            return myQueue.poll();
        }
    }
