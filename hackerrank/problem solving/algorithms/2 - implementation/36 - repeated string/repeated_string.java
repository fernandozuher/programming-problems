// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true
// Java 25

void main() {
    String inputString = IO.readln();
    long nCharacters = Long.parseLong(IO.readln());
    final char letter = 'a';
    IO.println(countInRepeatedString(inputString, letter, nCharacters));
}

long countInRepeatedString(String inputString, char letter, long nCharacters) {
    long fullRepeats = nCharacters / inputString.length();
    long nSubstring = nCharacters % inputString.length();
    var substring = inputString.substring(0, (int) nSubstring);

    long quantity = inputString.chars().filter(x -> x == letter).count();
    quantity *= fullRepeats;
    return quantity + substring.chars().filter(x -> x == letter).count();
}
