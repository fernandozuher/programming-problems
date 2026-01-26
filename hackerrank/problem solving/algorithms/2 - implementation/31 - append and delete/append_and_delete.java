// https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true
// Java 25

void main() {
    String s1 = IO.readln();
    String s2 = IO.readln();
    int nOps = Integer.parseInt(IO.readln());
    IO.println(appendAndDelete(s1, s2, nOps) ? "Yes" : "No");
}

// n1: length of string s1
// n2: length of string s2
// T: O(min(n1, n2))
// S: O(1) extra space
boolean appendAndDelete(String s1, String s2, int nOps) {
    int prefixLen = commonPrefixLength(s1, s2);
    int opsNeeded = (s1.length() - prefixLen) + (s2.length() - prefixLen);
    if (nOps < opsNeeded) return false;
    if (nOps >= s1.length() + s2.length()) return true;
    return (nOps - opsNeeded) % 2 == 0;
}

int commonPrefixLength(String s1, String s2) {
    int minLen = Math.min(s1.length(), s2.length());
    for (int i = 0; i < minLen; i++)
        if (s1.charAt(i) != s2.charAt(i)) return i;
    return minLen;
}
