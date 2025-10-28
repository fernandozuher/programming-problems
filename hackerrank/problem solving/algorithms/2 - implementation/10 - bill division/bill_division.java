// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.*;

void main() {
    Input data = readInput();
    int charged = bonAppetit(data);
    IO.println(charged > 0 ? charged : "Bon Appetit");
}

Input readInput() {
    int itemNotEaten = readNumbers()[1];
    int[] mealCosts = readNumbers();
    int amountCharged = readNumbers()[0];
    return new Input(itemNotEaten, mealCosts, amountCharged);
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

record Input(int itemNotEaten, int[] mealCosts, int amountCharged) {
}

int bonAppetit(Input data) {
    int totalSharedCost = Arrays.stream(data.mealCosts).sum() - data.mealCosts[data.itemNotEaten];
    totalSharedCost /= 2;
    return data.amountCharged - totalSharedCost;
}
