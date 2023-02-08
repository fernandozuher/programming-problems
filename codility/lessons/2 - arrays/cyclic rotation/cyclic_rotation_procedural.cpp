// Source: https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/

using namespace std;


vector<int> is_there_rotation(const vector<int> VEC, const int ROTATION);
    int reduce_rotations(const int VEC_SIZE, const int ROTATION);
    vector<int> rotate_elements(const vector<int> VEC, const int ROTATION);


vector<int> solution(vector<int> &A, int K) {
    const vector<int> ROTATED_VEC {is_there_rotation(A, K)};

    if (ROTATED_VEC.size() > 0)
        return ROTATED_VEC;
    else
        return A;
}

    vector<int> is_there_rotation(const vector<int> VEC, const int ROTATION) {
        const int NEW_ROTATION {reduce_rotations(VEC.size(), ROTATION)};
        vector<int> rotated_array;

        if (NEW_ROTATION > 0)
            rotated_array = {rotate_elements(VEC, NEW_ROTATION)};

        return rotated_array;
    }

        int reduce_rotations(const int VEC_SIZE, const int ROTATION) {
            if (VEC_SIZE > 1)
                return ROTATION >= VEC_SIZE ? ROTATION % VEC_SIZE : ROTATION;
            else
                return 0;
        }

        vector<int> rotate_elements(const vector<int> VEC, const int ROTATION) {
            vector<int> new_vector {VEC.begin() + VEC.size() - ROTATION, VEC.end()};
            const vector<int> TEMP_VEC {VEC.begin(), VEC.begin() + VEC.size() - ROTATION};

            new_vector.insert(new_vector.end(), TEMP_VEC.begin(), TEMP_VEC.end());
            return new_vector;
        }
