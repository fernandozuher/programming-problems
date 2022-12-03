import java.io.*;
import java.util.*;

public class Solution {
    private Stack<Character> myStack;
    private Queue<Character> myQueue;

    Solution() {
        myStack = new Stack<Character>();
        myQueue = new LinkedList<Character>();
    }

    void pushCharacter(char ch) {
        myStack.push(ch);
    }

    void enqueueCharacter(char ch) {
        myQueue.add(ch);
    }

    char popCharacter() {
        return myStack.pop();
    }

    char dequeueCharacter() {
        return myQueue.poll();
    }

    boolean empty() {
        return myStack.empty();
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String input = scan.nextLine();
        scan.close();

        // Convert input String to an array of characters:
        char[] s = input.toCharArray();

        Solution obj = new Solution();

        for (char c : s) {
            obj.pushCharacter(c);
            obj.enqueueCharacter(c);
        }

        int i = 0;
        for ( ; !obj.empty() && obj.popCharacter() == obj.dequeueCharacter(); ++i);

        boolean isPalindrome = i < s.length / 2;
        System.out.println( "The word, " + input + ", is " 
                           + (!isPalindrome ? "" : "not ") + "a palindrome." );
    }
}
