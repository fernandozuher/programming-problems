// Source: https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main()
    {
        string inputString = Console.ReadLine();
        ulong nCharacters = ulong.Parse(Console.ReadLine());

        RepeatedString obj = new RepeatedString(inputString, nCharacters);
        ulong quantityOfA = obj.GetQuantityOfA();
        Console.WriteLine(quantityOfA);
    }
}

    public class RepeatedString
    {
        private string _inputString;
        private ulong _nCharacters;
        private ulong _quantityOfA;

        public RepeatedString(string inputString, ulong nCharacters)
        {
            _inputString = inputString;
            _nCharacters = nCharacters;
            _quantityOfA = 0;

            _FindQuantityOfAInRepeatedString();
        }

            private void _FindQuantityOfAInRepeatedString()
            {
                _quantityOfA = _FindQuantityOfAInString(_inputString);
                _quantityOfA *= _FindQuantityOfRepeatedEntireString();
                _quantityOfA += _FindQuantityOfRemainingA();
            }

                private ulong _FindQuantityOfAInString(string inputString)
                {
                    ulong quantityOfA = 0;

                    foreach (char character in inputString)
                        if (character == 'a')
                            quantityOfA++;

                    return quantityOfA;
                }

                private ulong _FindQuantityOfRepeatedEntireString()
                {
                    ulong nStrings = (ulong) Math.Truncate((double) _nCharacters / _inputString.Length);
                    return nStrings;
                }

                private ulong _FindQuantityOfRemainingA()
                {
                    ulong nRemainingCharactersOfString = _nCharacters % (ulong) _inputString.Length;

                    if (nRemainingCharactersOfString == 0)
                        return 0;

                    string subString = _inputString.Substring(0, (int) nRemainingCharactersOfString);
                    return _FindQuantityOfAInString(subString);
                }

        public ulong GetQuantityOfA()
        {
            return _quantityOfA;
        }
    }
