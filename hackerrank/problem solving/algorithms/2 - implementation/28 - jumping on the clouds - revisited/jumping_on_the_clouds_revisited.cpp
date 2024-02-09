// https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Jumping_On_The_Clouds {
public:
    Jumping_On_The_Clouds(const vector<int>& clouds, const int jump_length);
    int remaining_energy() const;

private:
    vector<int> clouds;
    int jump_length;
    int energy;

    void calculate_remaining_energy();
        int spent_energy_according_to_type_of_cloud(const int cloud_type) const;
        int generate_new_cloud_index(const int cloud_index) const;
        bool is_cloud_index_back_to_first_cloud(const int cloud_index) const;
};

    Jumping_On_The_Clouds::Jumping_On_The_Clouds(const vector<int>& clouds, const int jump_length)
        : clouds{clouds}, jump_length{jump_length}, energy{100}
    {
        calculate_remaining_energy();
    }

        void Jumping_On_The_Clouds::calculate_remaining_energy()
        {
            for (int cloud_index{}; true;) {
                energy -= spent_energy_according_to_type_of_cloud(clouds.at(cloud_index));
                cloud_index = generate_new_cloud_index(cloud_index);
                if (is_cloud_index_back_to_first_cloud(cloud_index))
                    break;
            }
        }

            int Jumping_On_The_Clouds::spent_energy_according_to_type_of_cloud(const int cloud_type) const
            {
                return cloud_type == 0 ? 1 : 3;
            }

            int Jumping_On_The_Clouds::generate_new_cloud_index(const int cloud_index) const
            {
                return (cloud_index + jump_length) % clouds.size();
            }

            bool Jumping_On_The_Clouds::is_cloud_index_back_to_first_cloud(const int cloud_index) const
            {
                return cloud_index == 0;
            }

    int Jumping_On_The_Clouds::remaining_energy() const
    {
        return energy;
    }

//////////////////////////////////////////////////

template<class T = int>
vector<int> read(const int n);

int main()
{
    int n, jump_length;
    cin >> n >> jump_length;
    vector<int> array {read(n)};

    Jumping_On_The_Clouds obj{array, jump_length};
    cout << obj.remaining_energy() << '\n';

    return 0;
}

    template<class T = int>
    vector<int> read(const int n)
    {
        vector<T> array(n);
        auto read = []{T x; cin >> x; return x;};
        ranges::generate(array, read);
        return array;
    }
