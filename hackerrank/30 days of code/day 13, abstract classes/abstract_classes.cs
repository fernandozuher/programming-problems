// https://www.hackerrank.com/challenges/30-abstract-classes/problem?isFullScreen=true

using static System.Console;

public class Solution
{
    public static void Main()
    {
        string title = ReadLine();
        string author = ReadLine();
        int price = int.Parse(ReadLine());
        Book novel = new MyBook(title, author, price);
        novel.Display();
    }
}

abstract class Book(string title, string author)
{
    protected string title = title, author = author;

    public abstract void Display();
}

class MyBook(string title, string author, double price) : Book(title, author)
{
    private double _price = price;

    public override void Display()
    {
        WriteLine("Title: {0} \nAuthor: {1} \nPrice: {2}", title, author, _price);
    }
}
