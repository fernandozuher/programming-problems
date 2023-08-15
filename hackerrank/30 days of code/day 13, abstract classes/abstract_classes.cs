// https://www.hackerrank.com/challenges/30-abstract-classes/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main()
    {
        string title = Console.ReadLine();
        string author = Console.ReadLine();
        int price = int.Parse(Console.ReadLine());

        Book novel = new MyBook(title, author, price);
        novel.display();
    }
}

    abstract class Book
    {
        protected string title, author;

        public Book(string title, string author)
        {
            this.title = title;
            this.author = author;
        }

        public abstract void display();
    }

        class MyBook : Book
        {
            private double _price;

            public MyBook(string title, string author, double price) : base(title, author)
            {
                _price = price;
            }

            public override void display()
            {
                Console.WriteLine("Title: {0} \nAuthor: {1} \nPrice: {2}", title, author, _price);
            }
        }
