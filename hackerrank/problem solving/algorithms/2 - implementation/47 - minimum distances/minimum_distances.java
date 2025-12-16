// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true
// Java 25

void main() {
    IO.readln();
    int[] arr = readNumbers();
    IO.println(minDistance(arr));
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

int minDistance(int[] arr) {
    var lastSeen = new HashMap<Integer, Integer>();
    int minDist = -1;

    for (int i = 0; i < arr.length; i++) {
        int x = arr[i];

        if (lastSeen.containsKey(x)) {
            int dist = i - lastSeen.get(x);
            if (minDist == -1 || dist < minDist) {
                minDist = dist;
                if (minDist == 1) return 1;
            }
        }
        lastSeen.put(x, i);
    }

    return minDist;
}
