// https://app.codility.com/programmers/lessons/5-prefix_sums/passing_cars/

int solution(vector<int> &array)
{
    int passing_cars_pairs {0};

    for (int east {0}, passing_cars_limit {1000000000}; const auto west : array)
        if (west) {
            if ((passing_cars_pairs += east) > passing_cars_limit)
                return -1;
        }
        else
            east++;

    return passing_cars_pairs;
}
