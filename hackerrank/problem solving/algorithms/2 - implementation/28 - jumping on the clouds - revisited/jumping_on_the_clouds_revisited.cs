// https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        List<int> array = _readIntArray();
        int n = array.First();
        int jumpLength = array.Last();
        array = _readIntArray();

        var obj = new JumpingOnTheClouds(array, jumpLength);
        Console.WriteLine(obj.remainingEnergy());
    }

        private static List<int> _readIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }
}

    public class JumpingOnTheClouds
    {
        List<int> _clouds;
        int _jumpLength;
        int _remainingEnergy;

        public JumpingOnTheClouds(List<int> clouds, int jumpLength)
        {
            _clouds = clouds;
            _jumpLength = jumpLength;
            _remainingEnergy = 100;
            _calculateRemainingEnergy();
        }

            private void _calculateRemainingEnergy()
            {
                for (int cloudIndex = 0; true;)
                {
                    _remainingEnergy -= _spentEnergyAccordingToTypeOfCloud(_clouds[cloudIndex]);
                    cloudIndex = _generateNewCloudIndex(cloudIndex);
                    if (_isCloudIndexBackToFirstCloud(cloudIndex))
                        break;
                }
            }

                private int _spentEnergyAccordingToTypeOfCloud(int cloudType)
                {
                    return cloudType == 0 ? 1 : 3;
                }

                private int _generateNewCloudIndex(int cloudIndex)
                {
                    return (cloudIndex + _jumpLength) % _clouds.Count;
                }

                private bool _isCloudIndexBackToFirstCloud(int cloudIndex)
                {
                    return cloudIndex == 0;
                }

        public int remainingEnergy()
        {
            return _remainingEnergy;
        }
    }
