// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;

void main() {
    int price = Reader.read(Integer::parseInt);
    int discount = Reader.read(Integer::parseInt);
    int minPrice = Reader.read(Integer::parseInt);
    int budget = Reader.read(Integer::parseInt);
    IO.println(howManyGamesCanBeBought(price, discount, minPrice, budget));
}

// T: O(budget / minPrice)
// S: O(1) extra space
int howManyGamesCanBeBought(int price, int discount, int minPrice, int budget) {
    int count = 0;
    while (budget >= price) {
        count++;
        budget -= price;
        price = Math.max(price - discount, minPrice);
    }
    return count;
}
