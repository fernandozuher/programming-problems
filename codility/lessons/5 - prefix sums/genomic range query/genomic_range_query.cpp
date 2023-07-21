// https://app.codility.com/programmers/lessons/5-prefix_sums/genomic_range_query/

#include <algorithm>

using namespace std;

vector<vector<int>> convert_biggest_dna_sequence(const pair<int, int>& min_and_max, const string& dna_sequence);
vector<int> find_answers_to_queries(const pair<vector<int>, vector<int>>& query_range, const vector<vector<int>>& matrix);

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

vector<int> solution(string& dna_sequence, vector<int>& begin_query, vector<int>& end_query)
{
    const pair<int, int> min_and_max {*ranges::min_element(begin_query), *ranges::max_element(end_query)};
    const vector<vector<int>> matrix {convert_biggest_dna_sequence(min_and_max, dna_sequence)};

    const pair<vector<int>, vector<int>> query_range {begin_query, end_query};
    return find_answers_to_queries(query_range, matrix);
}

    vector<vector<int>> convert_biggest_dna_sequence(const pair<int, int>& min_and_max, const string& dna_sequence)
    {
        const auto& [min, max] = min_and_max;
        const int nucleotides {4};
        vector<vector<int>> matrix(nucleotides);

        // Convert only the range of array dna_sequence that will be looked from min to max (inclusive).
        for (int i {min}, j; i <= max; ++i) {
            j = {convert(dna_sequence.at(i))};
            matrix.at(j).push_back(i);
        }

        return matrix;
    }

    vector<int> find_answers_to_queries(const pair<vector<int>, vector<int>>& query_range, const vector<vector<int>>& matrix)
    {
        const auto& [begin_query, end_query] = query_range;
        vector<int> answers_to_queries(begin_query.size());
        const int nucleotides {4};

        for (size_t i {0}; i < begin_query.size(); ++i)
            for (int j {0}; j < nucleotides; ++j)
                for (size_t k {0}; k < matrix.at(j).size(); ++k)

                    if (matrix.at(j).at(k) >= begin_query.at(i)) {
                        if (matrix.at(j).at(k) <= end_query.at(i)) {
                            answers_to_queries.at(i) = {j + 1};
                            j = {nucleotides};
                        }
                        break;
                    }

        return answers_to_queries;
    }
