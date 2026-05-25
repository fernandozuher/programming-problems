// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true
// Java 25

void main() {
    IO.readln();
    int[] arr = readNumbers();
    double[] ratios = plusMinus(arr);
    for (var ratio : ratios)
        System.out.printf("%.6f\n", ratio);
}

int[] readNumbers() {
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
