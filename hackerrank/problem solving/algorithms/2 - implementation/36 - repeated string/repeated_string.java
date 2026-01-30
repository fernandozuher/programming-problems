// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true
// Java 25

void main() {
    String inputString = IO.readln();
    long nCharacters = Long.parseLong(IO.readln());
    final char letter = 'a';
    IO.println(countInRepeatedString(inputString, letter, nCharacters));
}

// n: length of inputString
// T: O(n)
// S: O(1) extra space
long countInRepeatedString(String inputString, char letter, long nCharacters) {
    long fullRepeats = nCharacters / inputString.length();
    long nSubstring = nCharacters % inputString.length();

    long count = inputString.chars().filter(x -> x == letter).count();
    count *= fullRepeats;
    long substring_count = inputString.chars().limit(nSubstring).filter(x -> x == letter).count();
    return count + substring_count;
}
