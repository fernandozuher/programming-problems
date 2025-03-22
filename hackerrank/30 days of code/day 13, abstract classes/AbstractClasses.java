// https://www.hackerrank.com/challenges/30-abstract-classes/problem?isFullScreen=true

import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            String title = scan.nextLine();
            String author = scan.nextLine();
            int price = scan.nextInt();
            Book novel = new MyBook(title, author, price);
            novel.display();
        }
    }
}

abstract class Book {
    protected String title, author;

    Book(String title, String author) {
        this.title = title;
        this.author = author;
    }

    public abstract void display();
}

class MyBook extends Book {
    private double price;

    MyBook(String title, String author, double price) {
        super(title, author);
        this.price = price;
    }

    @Override
    public void display() {
        System.out.println("Title: " + title + "\nAuthor: " + author + "\nPrice: " + String.format("%.0f", price));
    }
}
