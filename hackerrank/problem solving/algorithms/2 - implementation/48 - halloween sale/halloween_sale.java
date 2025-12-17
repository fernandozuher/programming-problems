// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true
// Java 25

void main() {
    int[] arr = readNumbers();
    int price = arr[0];
    int discount = arr[1];
    int minPrice = arr[2];
    int budget = arr[3];
    IO.println(howManyGamesCanBeBought(price, discount, minPrice, budget));
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

int howManyGamesCanBeBought(int price, int discount, int minPrice, int budget) {
    int count = 0;
    while (budget >= price) {
        count++;
        budget -= price;
        price = Math.max(price - discount, minPrice);
    }
    return count;
}
