// https://app.codility.com/programmers/lessons/5-prefix_sums/genomic_range_query/

int* find_biggest_range(const int* begin_query, const int* end_query, const int size_queries);
int** convert_biggest_dna_sequence(const int* min_and_max, const int nucleotides, int* nucleotides_size, const char* dna_sequence);
int** allocate_memory_matrix(const int rows, const int columns);
int* find_answers_to_queries(const int* pair, int** query_range, const int* nucleotides_size, int** matrix);
int** free_matrix(int** matrix, const int rows);

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

struct Results solution(char* dna_sequence, int* begin_query, int* end_query, int size_queries)
{
    int* range = find_biggest_range(begin_query, end_query, size_queries);
    int min_and_max[2] = {range[0], range[1]};

    free(range);
    range = NULL;

    int nucleotides_size[] = {[0 ... 3] = 0};
    int nucleotides = 4;
    int** matrix = convert_biggest_dna_sequence(min_and_max, nucleotides, nucleotides_size, dna_sequence);

    int pair[] = {size_queries, nucleotides};
    int* query_range[] = {begin_query, end_query};
    int* answers_to_queries = find_answers_to_queries(pair, query_range, nucleotides_size, matrix);

    matrix = free_matrix(matrix, nucleotides);

    return (struct Results) { answers_to_queries, size_queries };
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

    int** convert_biggest_dna_sequence(const int* min_and_max, const int nucleotides, int* nucleotides_size, const char* dna_sequence)
    {
        int** matrix = allocate_memory_matrix(nucleotides, min_and_max[1]);

        // Convert only the range of array dna_sequence that will be looked from min to max (inclusive).
        for (int i = min_and_max[0], j; i <= min_and_max[1]; ++i) {
            j = convert(dna_sequence[i]);
            matrix[j][nucleotides_size[j]++] = i;
        }

        return matrix;
    }

        int** allocate_memory_matrix(const int rows, const int columns)
        {
            int** matrix = (int**) calloc(rows, sizeof(int*));
            for (int i = 0; i < rows; ++i)
                matrix[i] = (int*) calloc(columns, sizeof(int));
            return matrix;
        }

    int* find_answers_to_queries(const int* pair, int** query_range, const int* nucleotides_size, int** matrix)
    {
        int size_queries = pair[0];
        int nucleotides = pair[1];
        int* begin_query = query_range[0];
        int* end_query = query_range[1];
        int* answers_to_queries = (int*) calloc(size_queries, sizeof(int));

        for (int i = 0; i < size_queries; ++i)
            for (int j = 0; j < nucleotides; ++j)
                for (int k = 0; k < nucleotides_size[j]; ++k)

                    if (matrix[j][k] >= begin_query[i]) {
                        if (matrix[j][k] <= end_query[i]) {
                            answers_to_queries[i] = j + 1;
                            j = nucleotides;
                        }
                        break;
                    }

        return answers_to_queries;
    }

    int** free_matrix(int** matrix, const int rows)
    {
        for (int i = 0; i < rows; ++i)
            free(matrix[i]);
        free(matrix);
        return NULL;
    }
