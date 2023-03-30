// Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

using System;


public class Solution {
    public static void Main() {
        List<int> array = _ReadAnArray();
        int _sizeArray = array.First();
        int jumpLength = array.Last();
        array = _ReadAnArray();

        int energy = _JumpingOnClouds(array, jumpLength);
        Console.WriteLine(energy);
    }

        private static List<int> _ReadAnArray() {
            List<int> array = Console.ReadLine().Split().Select(int.Parse).ToList();
            return array;
        }

        private static int _JumpingOnClouds(List<int> array, int jumpLength) {
            int energy = 100;

            for (int cloudIndex = 0; true; ) {
                energy -= _SpentEnergyAccordingToTypeOfCloud(array[cloudIndex]);
                cloudIndex = _GenerateNewCloudIndex(cloudIndex, array.Count, jumpLength);
                if (_IsCloudIndexBackToFirstCloud(cloudIndex))
                    break;
            }

            return energy;
        }

            private static int _SpentEnergyAccordingToTypeOfCloud(int cloudType) {
                return cloudType == 0 ? 1 : 3;
            }

            private static int _GenerateNewCloudIndex(int cloudIndex, int sizeArray, int jumpLength) {
                return (cloudIndex + jumpLength) % sizeArray;
            }

            private static bool _IsCloudIndexBackToFirstCloud(int cloudIndex) {
                return cloudIndex == 0;
            }
}
