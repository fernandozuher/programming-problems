// Source: https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main()
    {
        string initialString = _ReadAWord();
        string finalString = _ReadAWord();
        int numberOfOperations = _ReadANumber();

        AppendAndDelete obj = new AppendAndDelete(initialString, finalString, numberOfOperations);
        bool response = obj.GetResponse();
        PrintOutput(response);
    }

        private static string _ReadAWord()
        {
            return Console.ReadLine();
        }

        private static int _ReadANumber()
        {
            return int.Parse(Console.ReadLine());
        }

        public static void PrintOutput(bool response)
        {
            Console.WriteLine(response ? "Yes" : "No");
        }
}

    public class AppendAndDelete
    {
        private string _InitialString;
        private string _FinalString;
        private int _NumberOfOperations;

        private int _CommonPrefixSizeBetweenStrings;
        private bool _AreOperationsSuitableToReplacement;

        public AppendAndDelete(string initialString, string finalString, int numberOfOperations) {
            _InitialString = initialString;
            _FinalString = finalString;
            _NumberOfOperations = numberOfOperations;

            _AppendAndDelete();
        }

            private void _AppendAndDelete()
            {
                _CommonPrefixSizeBetweenStrings = _FindCommonPrefixSizeBetweenStrings();

                int sizeOfDifferentCharactersFromInitialString = _InitialString.Length - _CommonPrefixSizeBetweenStrings;
                int sizeOfDifferentCharactersFromFinalString = _FinalString.Length - _CommonPrefixSizeBetweenStrings;

                int minimalQuantityOfOperationsToReplaceString = sizeOfDifferentCharactersFromInitialString + sizeOfDifferentCharactersFromFinalString;

                _NumberOfOperations -= minimalQuantityOfOperationsToReplaceString;
                _AreOperationsSuitableToReplacement = _AreOperationsSuitableToReplaceString();
            }

                private int _FindCommonPrefixSizeBetweenStrings()
                {
                    int size = 0;
                    while (size != _InitialString.Length && size != _FinalString.Length && _InitialString[size] == _FinalString[size])
                        size++;
                    return size;
                }

                private bool _AreOperationsSuitableToReplaceString()
                {
                    if (_NumberOfOperations < 0 ||
                            (_AreOperationsBiggerThanZeroAndOdd() && _AreNotOperationsEnoughToRemoveAndReplaceCommonPrefix()))
                        return false;
                    return true;
                }

                    private bool _AreOperationsBiggerThanZeroAndOdd()
                    {
                        return _NumberOfOperations > 0 && _NumberOfOperations % 2 == 1;
                    }

                    private bool _AreNotOperationsEnoughToRemoveAndReplaceCommonPrefix()
                    {
                        return _NumberOfOperations < _CommonPrefixSizeBetweenStrings * 2;
                    }

        public bool GetResponse() {
            return _AreOperationsSuitableToReplacement;
        }
    }
