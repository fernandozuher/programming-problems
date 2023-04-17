// Source: https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

using System;

public class RepeatedString
{
    public static void Main()
    {
        string inputString = Console.ReadLine();
        ulong nCharacters = ulong.Parse(Console.ReadLine());

        ulong quantityOfA = _FindQuantityOfAInRepeatedString(inputString, nCharacters);
        Console.WriteLine(quantityOfA);
    }

        private static ulong _FindQuantityOfAInRepeatedString(string inputString, ulong nCharacters)
        {
            ulong quantityOfA = _FindQuantityOfAInString(inputString);
            quantityOfA *= _FindQuantityOfRepeatedEntireString(nCharacters, (ulong) inputString.Length);
            quantityOfA += _FindQuantityOfRemainingA(nCharacters, inputString);

            return quantityOfA;
        }

            private static ulong _FindQuantityOfAInString(string inputString)
            {
                ulong quantityOfA = 0;

                foreach (char character in inputString)
                    if (character == 'a')
                        quantityOfA++;

                return quantityOfA;
            }

            private static ulong _FindQuantityOfRepeatedEntireString(ulong nCharacters, ulong sizeString)
            {
                ulong nStrings = (ulong) Math.Truncate((double) nCharacters / sizeString);
                return nStrings;
            }

            private static ulong _FindQuantityOfRemainingA(ulong nCharacters, string inputString)
            {
                ulong nRemainingCharactersOfString = nCharacters % (ulong) inputString.Length;

                if (nRemainingCharactersOfString == 0)
                    return 0;

                string subString = inputString.Substring(0, (int) nRemainingCharactersOfString);
                return _FindQuantityOfAInString(subString);
            }
}
