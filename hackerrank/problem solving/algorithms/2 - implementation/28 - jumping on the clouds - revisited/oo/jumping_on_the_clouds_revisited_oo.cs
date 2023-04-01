// Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

using System;


public class Solution
{
    public static void Main()
    {
        List<int> array = _ReadAnArray();
        int _sizeArray = array.First();
        int jumpLength = array.Last();
        array = _ReadAnArray();

        JumpingOnTheClouds obj = new JumpingOnTheClouds(array, jumpLength);
        Console.WriteLine(obj.GetRemainingEnergy());
    }

        private static List<int> _ReadAnArray()
        {
            List<int> array = Console.ReadLine().Split().Select(int.Parse).ToList();
            return array;
        }
}

    class JumpingOnTheClouds
    {
        List<int> _Array;
        int _JumpLength;
        int _Energy;

        public JumpingOnTheClouds(List<int> array, int jumpLength)
        {
            _Array = array;
            _JumpLength = jumpLength;
            _Energy = 100;

            _JumpOnClouds();
        }

            private void _JumpOnClouds()
            {
                for (int cloudIndex = 0; true; )
                {
                    _Energy -= _SpentEnergyAccordingToTypeOfCloud(_Array[cloudIndex]);
                    cloudIndex = _GenerateNewCloudIndex(cloudIndex);
                    if (_IsCloudIndexBackToFirstCloud(cloudIndex))
                        break;
                }
            }

                private int _SpentEnergyAccordingToTypeOfCloud(int cloudType)
                {
                    return cloudType == 0 ? 1 : 3;
                }

                private int _GenerateNewCloudIndex(int cloudIndex)
                {
                    return (cloudIndex + _JumpLength) % _Array.Count;
                }

                private bool _IsCloudIndexBackToFirstCloud(int cloudIndex)
                {
                    return cloudIndex == 0;
                }

        public int GetRemainingEnergy()
        {
            return _Energy;
        }
    }
