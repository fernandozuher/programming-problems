// https://www.hackerrank.com/challenges/30-queues-stacks/problem?isFullScreen=true

using System;
using System.Collections.Generic;

public class Solution
{
    public static void Main()
    {
        string word = Console.ReadLine();
        QueuesAndStacks obj = new QueuesAndStacks();

        foreach (char c in word)
        {
            obj.PushCharacter(c);
            obj.EnqueueCharacter(c);
        }

        CheckIfWordIsPalindrome(obj, word);
    }

    public static void CheckIfWordIsPalindrome(QueuesAndStacks obj, string word)
    {
        bool isPalindrome = true;

        for (int i = 0, len = word.Length / 2; i < len; ++i)
            if (obj.PopCharacter() != obj.DequeueCharacter())
            {
                isPalindrome = false;
                break;
            }

        string notWord = isPalindrome ? " " : " not ";
        Console.Write("The word, {0}, is{1}a palindrome.", word, notWord);
    }
}

    public class QueuesAndStacks
    {
        private Stack<char> _myStack;
        private Queue<char> _myQueue;

        public QueuesAndStacks()
        {
            _myStack = new Stack<char>();
            _myQueue = new Queue<char>();
        }

        public void PushCharacter(char ch)
        {
            _myStack.Push(ch);
        }

        public void EnqueueCharacter(char ch)
        {
            _myQueue.Enqueue(ch);
        }

        public char PopCharacter()
        {
            return _myStack.Pop();
        }

        public char DequeueCharacter()
        {
            return _myQueue.Dequeue();
        }
    }
