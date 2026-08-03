// https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true
// Java 25

void main() {
    int jumpLength = readNums()[1];
    int[] arr = readNums();
    IO.println(jumpingOnTheClouds(arr, jumpLength));
}

int[] readNums() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// n: length of clouds; 2 to 25
// k (jumpLength): 1 <= k <= n
// n % k = 0
// c[i] = 0 or 1
// T: O(n) = O(25) = O(1)
// S: O(1) extra space
int jumpingOnTheClouds(int[] clouds, int jumpLength) {
    int energy = 100;

    for (int cloudIndex = 0; ; ) {
        energy -= clouds[cloudIndex] == 0 ? 1 : 3;
        cloudIndex = (cloudIndex + jumpLength) % clouds.length;
        if (cloudIndex == 0) break;
    }

    return energy;
}
