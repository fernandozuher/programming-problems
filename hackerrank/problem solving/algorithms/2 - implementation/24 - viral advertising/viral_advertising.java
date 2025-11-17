// https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true
// Java 25

import java.lang.IO;

void main() {
    int days = Integer.parseInt(IO.readln());
    IO.println(viralAdvertising(days));
}

// n = days = length of the iteration
// T = O(n)
// S = O(1)
int viralAdvertising(int days) {
    int cumulative = 0;

    for (int shared = 5; days > 0; days--) {
        int liked = shared / 2;
        cumulative += liked;
        shared = liked * 3;
    }

    return cumulative;
}
