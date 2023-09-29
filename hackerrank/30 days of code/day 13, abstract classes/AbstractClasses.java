// https://www.hackerrank.com/challenges/30-abstract-classes/problem?isFullScreen=true

import java.util.Scanner;

public class AbstractClasses {
    public static void main(String[] args) {
        var scan = new Scanner(System.in);

        String title = scan.nextLine();
        String author = scan.nextLine();
        int price = scan.nextInt();

        Book novel = new MyBook(title, author, price);
        novel.display();
    }
}

    abstract class Book {
        protected String title, author;

        Book(final String title, final String author) {
            this.title = title;
            this.author = author;
        }

        public abstract void display();
    }

        class MyBook extends Book {
            private double price;

            MyBook(final String title, final String author, final double price) {
                super(title, author);
                this.price = price;
            }

            @Override
            public void display() {
                System.out.println("Title: " + title + "\nAuthor: " + author + "\nPrice: " + String.format("%.0f", price));
            }
        }
