// https://www.hackerrank.com/challenges/append-and-delete/problem?isfullscreen=true

#include <iostream>

using namespace std;

class Append_And_Delete {
public:
    Append_And_Delete(const string& initial_string, const string& final_string, const int operations);
    bool are_operations_suitable_to_replacement() const;

private:
    string initial_string;
    string final_string;
    int operations;

    int common_prefix_size_between_strings;
    bool are_operations_proper_to_replacement;

    void append_and_delete();
        int find_common_prefix_size_between_strings() const;
        bool are_operations_suitable_to_replace_string() const;
            bool are_operations_bigger_than_zero_and_odd() const;
            bool are_not_operations_enough_to_remove_and_replace_common_prefix() const;
};

    Append_And_Delete::Append_And_Delete(const string& initial_string, const string& final_string, const int operations)
        : initial_string{initial_string}, final_string{final_string}, operations{operations},
          common_prefix_size_between_strings{}, are_operations_proper_to_replacement{}
    {
        append_and_delete();
    }

        void Append_And_Delete::append_and_delete()
        {
            common_prefix_size_between_strings = find_common_prefix_size_between_strings();

            int size_of_different_characters_from_initial_string = initial_string.length() - common_prefix_size_between_strings;
            int size_of_different_characters_from_final_string = final_string.length() - common_prefix_size_between_strings;

            int minimal_quantity_of_operations_to_replace_string {size_of_different_characters_from_initial_string + size_of_different_characters_from_final_string};

            operations -= minimal_quantity_of_operations_to_replace_string;
            are_operations_proper_to_replacement = are_operations_suitable_to_replace_string();
        }

            int Append_And_Delete::find_common_prefix_size_between_strings() const
            {
                int size{};
                int n = min(initial_string.length(), final_string.length());
                while (n-- && initial_string.at(size) == final_string.at(size))
                    ++size;
                return size;
            }

            bool Append_And_Delete::are_operations_suitable_to_replace_string() const
            {
                if (operations < 0 ||
                        (are_operations_bigger_than_zero_and_odd() && are_not_operations_enough_to_remove_and_replace_common_prefix()))
                    return false;
                return true;
            }

                bool Append_And_Delete::are_operations_bigger_than_zero_and_odd() const
                {
                    return operations > 0 && operations & 1;
                }

                bool Append_And_Delete::are_not_operations_enough_to_remove_and_replace_common_prefix() const
                {
                    return operations < common_prefix_size_between_strings * 2;
                }

    bool Append_And_Delete::are_operations_suitable_to_replacement() const
    {
        return are_operations_proper_to_replacement;
    }

//////////////////////////////////////////////////

int main()
{
    string initial_string, final_string;
    int operations;
    cin >> initial_string >> final_string >> operations;

    Append_And_Delete obj{initial_string, final_string, operations};
    cout << (obj.are_operations_suitable_to_replacement() ? "Yes\n" : "No\n");

    return 0;
}
