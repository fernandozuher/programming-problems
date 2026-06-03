// https://www.hackerrank.com/challenges/dynamic-array/problem?isFullScreen=true
// Java 25

void main() {
    int[] arr = readNumbers();
    int n = arr[0];
    int nQueries = arr[1];
    var obj = new DynamicArray(n);

    for (int i = 0; i < nQueries; i++)
        obj.handleQuery(readNumbers());

    obj.answers().forEach(IO::println);
}

int[] readNumbers() {
    return Arrays.stream(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

static class DynamicArray {
    private final int n;
    private final List<List<Integer>> arr;
    private final List<Integer> answersToQueries;
    private int lastAnswer;

    public DynamicArray(int n) {
        this.n = n;

        arr = new ArrayList<>(n);
        for (int i = 0; i < n; ++i)
            arr.add(new ArrayList<>());

        answersToQueries = new ArrayList<>();
        lastAnswer = 0;
    }

    public void handleQuery(int[] query) {
        int type = query[0];
        int x = query[1];
        int y = query[2];

        int index = (x ^ lastAnswer) % n;

        if (type == 1) arr.get(index).add(y);
        else {
            int j = y % arr.get(index).size();
            lastAnswer = arr.get(index).get(j);
            answersToQueries.add(lastAnswer);
        }
    }

    public List<Integer> answers() {
        return answersToQueries;
    }
}
