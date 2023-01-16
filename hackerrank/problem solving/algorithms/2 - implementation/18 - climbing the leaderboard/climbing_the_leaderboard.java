// Source: https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;


public class Solution {

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        readLineAsListInteger(bufferedReader);
        final List<Integer> ranked = readLineAsListInteger(bufferedReader);

        readLineAsListInteger(bufferedReader);
        final List<Integer> player = readLineAsListInteger(bufferedReader);

        final Result result = new Result(ranked, player);
    }

        private static List<Integer> readLineAsListInteger(BufferedReader bufferedReader) {
            try {
                var inputLine = Stream.of(bufferedReader.readLine().split(" "))
                                .map(Integer::parseInt)
                                .collect(toList());

                return inputLine;
            } catch (Exception e) {
                System.out.println("Exception caught during reading");
            }
            return null;
        }
}

    class Result {
        private List<Integer> _ranked;
        private List<Integer> _player;
        private List<Integer> _playerRank;

        public Result(List<Integer> ranked, List<Integer> player) {
            _ranked = new ArrayList<Integer>(ranked);
            _player = new ArrayList<Integer>(player);
            _playerRank = Arrays.asList(new Integer[_player.size()]);

            _removeDuplicatesFromRankedList();
            _climbingLeaderboard();
            printResult();
        }

            private void _removeDuplicatesFromRankedList() {
                Set<Integer> set = new HashSet<Integer>(_ranked);
                _ranked.clear();
                _ranked.addAll(set);
                _ranked.sort(Collections.reverseOrder());
            }

            private void _climbingLeaderboard() {
                for (int i = 0, n = _player.size(), lastIndex = _ranked.size() - 1; i < n; i++) {
                    int index = _binarySearchDescendingOrder(0, lastIndex, _player.get(i));
                    _playerRank.set(i, ++index);
                }
            }

                private int _binarySearchDescendingOrder(int low, int high, int key) {
                    if (high >= low) {
                        final int middle = low + (high - low) / 2;

                        if (key == _ranked.get(middle))
                            return middle;
                        else if (key > _ranked.get(middle))
                            return _binarySearchDescendingOrder(low, middle - 1, key);
                        else
                            return _binarySearchDescendingOrder(middle + 1, high, key);
                    }
                    return low;
                }

            public void printResult() {
                for (int playerRank : _playerRank)
                    System.out.println(playerRank);
            }
    }
