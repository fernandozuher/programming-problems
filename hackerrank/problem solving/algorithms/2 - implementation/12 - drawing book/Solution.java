// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        var scan = new Scanner(System.in);
        int pageQuantity = scan.nextInt();
        int page = scan.nextInt();
        var obj = new DrawingBook(pageQuantity, page);
        System.out.println(obj.minimumTurnOfPages());
    }
}

    class DrawingBook {
        private int pageQuantity;
        private int page;
        private int turnOfPagesFromFront;
        private int turnOfPagesFromBack;
        private int minTurnOfPages;

        public DrawingBook(final int pageQuantity, final int page) {
            this.pageQuantity = pageQuantity;
            this.page = page;
            turnOfPagesFromFront = 0;
            turnOfPagesFromBack = 0;
            minTurnOfPages = 0;
            pageCount();
        }

            private void pageCount() {
                turnOfPagesFromFront = calculateTurnOfPages(page);
                final int maximumTurns = calculateTurnOfPages(pageQuantity);
                turnOfPagesFromBack = maximumTurns - turnOfPagesFromFront;
                minTurnOfPages = Math.min(turnOfPagesFromFront, turnOfPagesFromBack);
            }

                private int calculateTurnOfPages(final int page) {
                    return (page & 1) == 1 ? pageIsOdd(page) : pageIsEven(page);
                }

                    private int pageIsOdd(final int page) {
                        return (page - 1) / 2;
                    }

                    private int pageIsEven(final int page) {
                        return page / 2;
                    }

        public int minimumTurnOfPages() {
            return minTurnOfPages;
        }
    }
