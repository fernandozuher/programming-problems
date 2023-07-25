// https://app.codility.com/programmers/lessons/5-prefix_sums/genomic_range_query/

function solution(dnaSequence, beginQuery, endQuery) {
    const MIN_AND_MAX = [Math.min(...beginQuery), Math.max(...endQuery)];
    const MATRIX = convertBiggestDnaSequence(MIN_AND_MAX, dnaSequence);

    const QUERY_RANGE = [beginQuery, endQuery];
    return findAnswersToQueries(QUERY_RANGE, MATRIX);
}

    function convertBiggestDnaSequence(minAndMax, dnaSequence) {
        const [MIN, MAX] = minAndMax;
        const NUCLEOTIDES = 4;
        const MATRIX = Array(NUCLEOTIDES).fill(null).map(_ => []);

        // Convert only the range of array dnaSequence that will be looked from min to max (inclusive).
        for (let i = MIN, j; i <= MAX; i++) {
            j = convert(dnaSequence[i]);
            MATRIX[j].push(i);
        }

        return MATRIX;
    }

        function convert(nucl) {
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

    function findAnswersToQueries(queryRange, matrix) {
        const [BEGIN_QUERY, END_QUERY] = queryRange;
        const ANSWERS_TO_QUERIES = Array(BEGIN_QUERY.length).fill(0);
        const NUCLEOTIDES = 4;

        for (let i = 0; i < BEGIN_QUERY.length; i++)
            for (let j = 0; j < NUCLEOTIDES; j++)
                for (let k = 0; k < matrix[j].length; k++)

                    if (matrix[j][k] >= BEGIN_QUERY[i]) {
                        if (matrix[j][k] <= END_QUERY[i]) {
                            ANSWERS_TO_QUERIES[i] = j + 1;
                            j = NUCLEOTIDES;
                        }
                        break;
                    }

        return ANSWERS_TO_QUERIES;
    }
