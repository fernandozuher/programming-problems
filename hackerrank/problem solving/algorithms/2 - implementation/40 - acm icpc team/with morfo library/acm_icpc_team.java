// https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;
import morfo.io.Writer;

void main() {
    int n = Reader.read(Integer::parseInt);
    Reader.skipInput();
    List<BitSet> binaries = readBinaries(n);
    Writer.println(acmTeam(binaries));
}

List<BitSet> readBinaries(int n) {
    return IntStream.range(0, n).mapToObj(_ -> toBitSet(Reader.read(s -> s))).toList();
}

BitSet toBitSet(String str) {
    int n = str.length();
    var binary = new BitSet(n);
    for (int i = 0; i < n; i++)
        if (str.charAt(i) == '1') binary.set(i);
    return binary;
}

List<Integer> acmTeam(List<BitSet> binaries) {
    int maxSubjects = 0;
    int teamsWithMax = 0;
    int i = 0;

    for (var a : binaries.subList(0, binaries.size() - 1))
        for (var b : binaries.subList(++i, binaries.size())) {
            int knownSubjects = countSubjectsKnownBy2Teams(a, b);

            if (knownSubjects > maxSubjects) {
                maxSubjects = knownSubjects;
                teamsWithMax = 1;
            } else if (knownSubjects == maxSubjects) teamsWithMax++;
        }

    return List.of(maxSubjects, teamsWithMax);
}

int countSubjectsKnownBy2Teams(BitSet a, BitSet b) {
    var bin = (BitSet) a.clone();
    bin.or(b);
    return bin.cardinality();
}
