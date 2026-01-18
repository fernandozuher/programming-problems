// https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true
// Java 25

void main() {
    int days = Integer.parseInt(IO.readln());
    IO.println(viralAdvertising(days));
}

// n: days
// T: O(n)
// S: O(1) extra space
int viralAdvertising(int days) {
    int cumulative = 0;
    for (int shared = 5; days > 0; days--) {
        int liked = shared / 2;
        shared = liked * 3;
        cumulative += liked;
    }
    return cumulative;
}
