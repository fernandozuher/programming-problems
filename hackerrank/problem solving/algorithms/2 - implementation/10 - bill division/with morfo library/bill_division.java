// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;
import morfo.math.Sum;

import java.util.List;

record Input(int itemNotEaten, List<Integer> mealCosts, int amountCharged) {
}

void main() {
    Input data = readInput();
    int charged = bonAppetit(data);
    IO.println(charged > 0 ? charged : "Bon Appetit");
}

Input readInput() {
    int n = Reader.read(Integer::parseInt);
    int itemNotEaten = Reader.read(Integer::parseInt);
    List<Integer> mealCosts = Reader.read(n, Integer::parseInt);
    int amountCharged = Reader.read(Integer::parseInt);
    return new Input(itemNotEaten, mealCosts, amountCharged);
}

// n: length of data.mealCosts
// T: O(n)
// S: O(1) extra space
int bonAppetit(Input data) {
    int totalCost = Sum.ofInts(data.mealCosts());
    int totalSharedCost = totalCost - data.mealCosts().get(data.itemNotEaten());
    totalSharedCost /= 2;
    return data.amountCharged() - totalSharedCost;
}
