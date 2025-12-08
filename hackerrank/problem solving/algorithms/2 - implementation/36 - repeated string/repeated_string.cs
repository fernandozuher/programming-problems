// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

string inputString = Console.ReadLine()!;
long nCharacters = long.Parse(Console.ReadLine()!);
const char letter = 'a';
Console.WriteLine(CountInRepeatedString(inputString, letter, nCharacters));

long CountInRepeatedString(string inputString, char letter, long nCharacters)
{
    long nSubstring;
    long fullRepeats = Math.DivRem(nCharacters, inputString.Length, out nSubstring);
    var substring = inputString[..(int)nSubstring];

    long quantity = inputString.Count(x => x == letter);
    quantity *= fullRepeats;
    return quantity + substring.Count(x => x == letter);
}
