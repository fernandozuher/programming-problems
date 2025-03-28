// https://www.hackerrank.com/challenges/30-queues-stacks/problem?isFullScreen=true

using static System.Console;

public static class Solution
{
    public static void Main()
    {
        string word = ReadLine();
        var obj = InitQueueAndStack(word);
        CheckIfPalindrome(obj, word);
    }

    private static QueueAndStack InitQueueAndStack(string word)
    {
        QueueAndStack obj = new();
        foreach (char c in word)
        {
            obj.EnqueueCharacter(c);
            obj.PushCharacter(c);
        }
        return obj;
    }

    private static void CheckIfPalindrome(QueueAndStack obj, string word)
    {
        bool isPalindrome = true;

        for (int halfLength = word.Length / 2; halfLength-- > 0;)
            if (obj.DequeueCharacter() != obj.PopCharacter())
            {
                isPalindrome = false;
                break;
            }

        string notWord = isPalindrome ? " " : " not ";
        Write("The word, {0}, is{1}a palindrome.", word, notWord);
    }
}

public class QueueAndStack
{
    private Queue<char> _myQueue;
    private Stack<char> _myStack;

    public QueueAndStack()
    {
        _myQueue = new Queue<char>();
        _myStack = new Stack<char>();
    }

    public void EnqueueCharacter(char ch)
    {
        _myQueue.Enqueue(ch);
    }

    public void PushCharacter(char ch)
    {
        _myStack.Push(ch);
    }

    public char DequeueCharacter()
    {
        return _myQueue.Dequeue();
    }

    public char PopCharacter()
    {
        return _myStack.Pop();
    }
}
