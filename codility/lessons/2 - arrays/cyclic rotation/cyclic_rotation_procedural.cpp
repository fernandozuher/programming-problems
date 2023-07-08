// Source: https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/

using namespace std;

vector<int> is_there_rotation(const vector<int>& vec, const int rotation);
    int reduce_rotations(const int vec_size, const int rotation);
    vector<int> rotate_elements(const vector<int>& vec, const int rotation);

vector<int> solution(vector<int> &a, int k)
{
    const vector<int> rotated_vec {is_there_rotation(a, k)};

    if (!rotated_vec.empty())
        return rotated_vec;
    else
        return a;
}

    vector<int> is_there_rotation(const vector<int>& vec, const int rotation)
    {
        const int new_rotation {reduce_rotations(vec.size(), rotation)};
        vector<int> rotated_array;

        if (new_rotation > 0)
            rotated_array = {rotate_elements(vec, new_rotation)};

        return rotated_array;
    }

        int reduce_rotations(const int vec_size, const int rotation)
        {
            if (vec_size > 1)
                return rotation >= vec_size ? rotation % vec_size : rotation;
            else
                return 0;
        }

        vector<int> rotate_elements(const vector<int>& vec, const int rotation)
        {
            vector<int> new_vector {vec.begin() + vec.size() - rotation, vec.end()};
            const vector<int> temp_vec {vec.begin(), vec.begin() + vec.size() - rotation};

            new_vector.insert(new_vector.end(), temp_vec.begin(), temp_vec.end());
            return new_vector;
        }
