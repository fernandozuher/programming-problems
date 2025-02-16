// https://www.hackerrank.com/challenges/30-review-loop/problem?isFullScreen=true

import java.util.Scanner;

public class LetsReview {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        for (int i = 0, n = scan.nextInt(); i < n && scan.hasNext(); i++) {
            String word = scan.next();
            StringBuilder word1 = new StringBuilder();
            StringBuilder word2 = new StringBuilder();
            boolean isWord1Turn = true;

            for (char ch : word.toCharArray()) {
                if (isWord1Turn)
                    word1.append(ch);
                else
                    word2.append(ch);
                isWord1Turn = !isWord1Turn;
            }

            System.out.println(word1 + " " + word2);
        }
    }
}
