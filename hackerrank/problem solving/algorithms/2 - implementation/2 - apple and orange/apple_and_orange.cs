// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        AppleAndOrange input = _readInput();
        _countApplesAndOranges(input);
    }

        private static AppleAndOrange _readInput()
        {
            List<int> temp = _readIntArray();
            int startingSam = temp.First();
            int endingSam = temp.Last();

            temp = _readIntArray();
            int appleTreeLocation = temp.First();
            int orangeTreeLocation = temp.Last();

            // Discard sizes of arrays
            Console.ReadLine();

            List<int> applesDistanceFromTree = _readIntArray();
            List<int> orangesDistanceFromTree = _readIntArray();

            return new AppleAndOrange(startingSam, endingSam,
                                      appleTreeLocation, orangeTreeLocation,
                                      applesDistanceFromTree, orangesDistanceFromTree);
        }

            private static List<int> _readIntArray()
            {
                return Console.ReadLine().Split().Select(int.Parse).ToList();
            }

        private static void _countApplesAndOranges(AppleAndOrange input)
        {
            int applesOnHouse = _countFruitsOnHouse(input, "apple");
            int orangesOnHouse = _countFruitsOnHouse(input, "orange");
            Console.WriteLine("{0}\n{1}", applesOnHouse, orangesOnHouse);
        }

            private static int _countFruitsOnHouse(AppleAndOrange input, string fruit)
            {
                List<List<int>> filteredInput = _filterInput(input, fruit);
                int treeLocation = filteredInput.First().First();
                List<int> fruits = filteredInput.Last();

                return fruits.Count(partialLocation => {
                    int location = treeLocation + partialLocation;
                    return location >= input.startingSam && location <= input.endingSam;
                });
            }

                private static List<List<int>> _filterInput(AppleAndOrange input, string fruit)
                {
                    const int data = 2;
                    var filteredInput = new List<List<int>>(data);
                    filteredInput.Add(new List<int>());
                    filteredInput.Add(new List<int>());

                    if (fruit == "apple") {
                        filteredInput.First().Add(input.appleTreeLocation);
                        filteredInput[1] = input.applesDistanceFromTree;
                    }
                    else {
                        filteredInput.First().Add(input.orangeTreeLocation);
                        filteredInput[1] = input.orangesDistanceFromTree;
                    }

                    return filteredInput;
                }
}

    public class AppleAndOrange
    {
        public int startingSam, endingSam;
        public int appleTreeLocation, orangeTreeLocation;
        public List<int> applesDistanceFromTree, orangesDistanceFromTree;

        public AppleAndOrange(int startingSam, int endingSam,
                              int appleTreeLocation, int orangeTreeLocation,
                              List<int> applesDistanceFromTree,
                              List<int> orangesDistanceFromTree)
        {
            this.startingSam = startingSam;
            this.endingSam = endingSam;
            this.appleTreeLocation = appleTreeLocation;
            this.orangeTreeLocation = orangeTreeLocation;
            this.applesDistanceFromTree = applesDistanceFromTree;
            this.orangesDistanceFromTree = orangesDistanceFromTree;
        }
    }
