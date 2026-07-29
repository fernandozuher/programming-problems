// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true
// Java 25

void main() {
    IO.readln();
    int[] arr = readNums();
    double[] ratios = plusMinus(arr);
    printRatios(ratios);
}

int[] readNums() {
    return Arrays.stream(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
double[] plusMinus(int[] arr) {
    int positive = 0;
    int negative = 0;
    int zero = 0;

    for (int number : arr) {
        if (number > 0) positive++;
        else if (number < 0) negative++;
        else zero++;
    }

    double n = arr.length;
    return new double[]{positive / n, negative / n, zero / n};
}

void printRatios(double[] ratios) {
    for (var ratio : ratios)
        System.out.printf("%.6f\n", ratio);
}
