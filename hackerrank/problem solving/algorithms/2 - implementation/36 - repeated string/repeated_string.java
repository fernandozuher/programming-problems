// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true
// Java 25

void main() {
    String str = IO.readln();
    long nChars = Long.parseLong(IO.readln());
    final char letter = 'a';
    IO.println(countInRepeatedString(str, letter, nChars));
}

// n: length of str
// T: O(n)
// S: O(1) extra space
long countInRepeatedString(String str, char letter, long nChars) {
    long fullRepeats = nChars / str.length();
    long nSubstr = nChars % str.length();

    long count = countChar(str, letter);
    count *= fullRepeats;
    long substrCount = str.chars().limit(nSubstr).filter(x -> x == letter).count();
    return count + substrCount;
}

long countChar(String str, char letter) {
    return str.chars().filter(x -> x == letter).count();
}
