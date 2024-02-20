// https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main()
    {
        string initialString = Console.ReadLine();
        string finalString = Console.ReadLine();
        int operations = int.Parse(Console.ReadLine());
        var obj = new AppendAndDelete(initialString, finalString, operations);
        Console.WriteLine(obj.AreOperationsSuitableToReplacement ? "Yes" : "No");
    }
}

    public class AppendAndDelete
    {
        private string _initialString;
        private string _finalString;
        private int _operations;

        private int _commonPrefixSizeBetweenStrings;
        private bool _areOperationsSuitableToReplacement;

        public AppendAndDelete(string initialString, string finalString, int operations)
        {
            _initialString = initialString;
            _finalString = finalString;
            _operations = operations;

            _commonPrefixSizeBetweenStrings = 0;
            _areOperationsSuitableToReplacement = false;

            _appendAndDelete();
        }

            private void _appendAndDelete()
            {
                _commonPrefixSizeBetweenStrings = _findCommonPrefixSizeBetweenStrings();

                int sizeOfDifferentCharactersFromInitialString = _initialString.Length - _commonPrefixSizeBetweenStrings;
                int sizeOfDifferentCharactersFromFinalString = _finalString.Length - _commonPrefixSizeBetweenStrings;

                int minimalQuantityOfOperationsToReplaceString = sizeOfDifferentCharactersFromInitialString + sizeOfDifferentCharactersFromFinalString;

                _operations -= minimalQuantityOfOperationsToReplaceString;
                _areOperationsSuitableToReplacement = _areOperationsSuitableToReplaceString();
            }

                private int _findCommonPrefixSizeBetweenStrings()
                {
                    int size = 0;
                    int n = Math.Min(_initialString.Length, _finalString.Length);
                    while (n-- > 0 && _initialString[size] == _finalString[size])
                        ++size;
                    return size;
                }

                private bool _areOperationsSuitableToReplaceString()
                {
                    if (_operations < 0 ||
                            (_areOperationsBiggerThanZeroAndOdd() && _areNotOperationsEnoughToRemoveAndReplaceCommonPrefix()))
                        return false;
                    return true;
                }

                    private bool _areOperationsBiggerThanZeroAndOdd()
                    {
                        return _operations > 0 && _operations % 2 == 1;
                    }

                    private bool _areNotOperationsEnoughToRemoveAndReplaceCommonPrefix()
                    {
                        return _operations < _commonPrefixSizeBetweenStrings * 2;
                    }

        public bool AreOperationsSuitableToReplacement
        {
            get { return _areOperationsSuitableToReplacement; }
        }
    }
