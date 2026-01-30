// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

string inputString = Console.ReadLine()!;
long nCharacters = long.Parse(Console.ReadLine()!);
const char letter = 'a';
Console.WriteLine(CountInRepeatedString(inputString, letter, nCharacters));

// n: length of inputString
// T: O(n)
// S: O(1) extra space
long CountInRepeatedString(string inputString, char letter, long nCharacters)
{
    long nSubstring;
    long fullRepeats = Math.DivRem(nCharacters, inputString.Length, out nSubstring);
    var substring = inputString.AsSpan(0, (int)nSubstring);

    long count = inputString.Count(x => x == letter);
    count *= fullRepeats;
    return count + substring.Count(letter);
}
