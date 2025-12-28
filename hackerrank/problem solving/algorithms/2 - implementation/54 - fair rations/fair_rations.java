// https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true
// Java 25

void main() {
    IO.readln();
    int[] peopleLoafCounts = readNumbers();
    int minLoaves = minLoavesToSatisfyRules(peopleLoafCounts);
    IO.println(minLoaves == -1 ? "NO" : minLoaves);
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

int minLoavesToSatisfyRules(int[] peopleLoafCounts) {
    int loavesGiven = 0;
    int counts = peopleLoafCounts[0];

    for (int i = 1; i < peopleLoafCounts.length; i++) {
        if (isOdd(counts)) {
            loavesGiven += 2;
            counts = peopleLoafCounts[i] + 1;
        } else {
            counts = peopleLoafCounts[i];
        }
    }

    return isOdd(counts) ? -1 : loavesGiven;
}

boolean isOdd(int n) {
    return n % 2 == 1;
}
