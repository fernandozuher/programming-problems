// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

string str = Console.ReadLine()!;
long nChars = long.Parse(Console.ReadLine()!);
const char letter = 'a';
Console.WriteLine(CountInRepeatedString(str, letter, nChars));

// n: length of str
// T: O(n)
// S: O(1) extra space
long CountInRepeatedString(string str, char letter, long nChars)
{
    long nSubstr;
    long fullRepeats = Math.DivRem(nChars, str.Length, out nSubstr);
    var substr = str.AsSpan(0, (int)nSubstr);

    long count = str.Count(c => c == letter);
    count *= fullRepeats;
    return count + substr.Count(letter);
}
