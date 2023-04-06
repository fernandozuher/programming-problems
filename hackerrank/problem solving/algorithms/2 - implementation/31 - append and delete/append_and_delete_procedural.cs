// Source: https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main()
    {
        string initialString = _ReadAWord();
        string finalString = _ReadAWord();
        int numberOfOperations = _ReadANumber();

        bool response = _AppendAndDelete(initialString, finalString, numberOfOperations);
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

        private static bool _AppendAndDelete(string initialString, string finalString, int numberOfOperations)
        {
            int commonPrefixSizeBetweenStrings = _FindCommonPrefixSizeBetweenStrings(initialString, finalString);

            int sizeOfDifferentCharactersFromInitialString = initialString.Length - commonPrefixSizeBetweenStrings;
            int sizeOfDifferentCharactersFromFinalString = finalString.Length - commonPrefixSizeBetweenStrings;

            int minimalQuantityOfOperationsToReplaceString = sizeOfDifferentCharactersFromInitialString + sizeOfDifferentCharactersFromFinalString;
            numberOfOperations -= minimalQuantityOfOperationsToReplaceString;

            return _AreOperationsSuitableToReplaceString(numberOfOperations, commonPrefixSizeBetweenStrings);
        }

            private static int _FindCommonPrefixSizeBetweenStrings(string initialString, string finalString)
            {
                int size = 0;
                while (size != initialString.Length && size != finalString.Length && initialString[size] == finalString[size])
                    size++;
                return size;
            }

            private static bool _AreOperationsSuitableToReplaceString(int numberOfOperations, int commonPrefixSizeBetweenStrings)
            {
                if (numberOfOperations < 0 ||
                    (_AreOperationsBiggerThanZeroAndOdd(numberOfOperations) &&
                        _AreNotOperationsEnoughToRemoveAndReplaceCommonPrefix(numberOfOperations, commonPrefixSizeBetweenStrings)))
                    return false;
                return true;
            }

                private static bool _AreOperationsBiggerThanZeroAndOdd(int numberOfOperations)
                {
                    return numberOfOperations > 0 && numberOfOperations % 2 == 1;
                }

                private static bool _AreNotOperationsEnoughToRemoveAndReplaceCommonPrefix(int numberOfOperations, int commonPrefixSizeBetweenStrings)
                {
                    return numberOfOperations < commonPrefixSizeBetweenStrings * 2;
                }

        public static void PrintOutput(bool response)
        {
            Console.WriteLine(response ? "Yes" : "No");
        }
}
