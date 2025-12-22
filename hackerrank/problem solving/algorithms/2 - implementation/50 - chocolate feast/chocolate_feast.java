// https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true
// Java 25

void main() {
    for (int i = 0, n = readNumbers()[0]; i < n; i++) {
        var arr = readNumbers();
        int money = arr[0];
        int cost = arr[1];
        int wrappersNeeded = arr[2];
        IO.println(howManyChocolatesCanBeEaten(money, cost, wrappersNeeded));
    }
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

int howManyChocolatesCanBeEaten(int money, int cost, int wrappersNeeded) {
    int chocolates = money / cost;

    for (int wrappers = chocolates; wrappers >= wrappersNeeded; ) {
        int freeChocolates = wrappers / wrappersNeeded;
        wrappers = wrappers % wrappersNeeded + freeChocolates;
        chocolates += freeChocolates;
    }

    return chocolates;
}
