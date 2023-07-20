// https://app.codility.com/programmers/lessons/5-prefix_sums/genomic_range_query/

int* find_biggest_range(const int* begin_query, const int* end_query, const int size_queries);

inline int convert(const char nucl)
{
    switch (nucl) {
    case 'A':
        return 0;
    case 'C':
        return 1;
    case 'G':
        return 2;
    default:
        return 3;
    }
}

struct Results solution(char *S, int begin_query[], int end_query[], int size_queries)
{
    int* range = find_biggest_range(begin_query, end_query, size_queries);
    int min = range[0], max = range[1];

    // Create matrix to be the size of max
    int nucleotides = 4;
    int matrix[nucleotides][max + 1]; // Initialized with 0
    int nucleotides_size[] = {[0 ... 3] = 0}; // Initialize with 0

    // Convert only the range of array S that will be looked from min to max (inclusive).
    for (int i = min, j; i < max + 1; i++) {
        j = convert(S[i]);
        matrix[j][nucleotides_size[j]++] = i;
    }

    int *A = (int*) malloc(sizeof(int) * size_queries);
    for (int i = 0; i < size_queries; i++)
        for (int j = 0; j < nucleotides; j++)
            for (int k = 0; k < nucleotides_size[j]; k++)
                if (matrix[j][k] >= begin_query[i]) {
                    if (matrix[j][k] <= end_query[i])
                        A[i] = j + 1, j = nucleotides;
                    break;
                }
    return (struct Results) { A, size_queries };
}

int* find_biggest_range(const int* begin_query, const int* end_query, const int size_queries)
{
    int min = begin_query[0], max = end_query[0];
    for (int i = 1; i < size_queries; ++i) {
        if (min > begin_query[i])
            min = begin_query[i];
        if (max < end_query[i])
            max = end_query[i];
    }

    int* biggest_range = (int*) calloc(2, sizeof(int));
    biggest_range[0] = min;
    biggest_range[1] = max;

    return biggest_range;
}
