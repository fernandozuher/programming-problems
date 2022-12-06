#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class Supply_Stacks {

private:
    string top_stacks_crate_mover_9000;
    string top_stacks_crate_mover_9001;
    vector<vector<char>> stacks_crate_mover_9000;
    vector<vector<char>> stacks_crate_mover_9001;

    void initialize_stacks_state(const vector<string> input) {
        
        for (int i {0}, lines_initial_state_stacks {8}; i < lines_initial_state_stacks; i++)

            for (int stackIndex {0}, crateIndex {1}, n {9}; stackIndex < n; stackIndex++, crateIndex += 4)

                if (char crate {input.at(i).at(crateIndex)}; crate != ' ')
                    this->stacks_crate_mover_9000.at(stackIndex).push_back(crate);

        for (int i {0}, n {static_cast<int>(this->stacks_crate_mover_9000.size())}; i < n; i++)
            reverse(this->stacks_crate_mover_9000.at(i).begin(), this->stacks_crate_mover_9000.at(i).end());

        for (auto stack : this->stacks_crate_mover_9000)
            this->stacks_crate_mover_9001.push_back(stack);
    }

    void run_rearrangement_procedure(const vector<string> input) {
        int index_first_procedure {10};
        for (int i {index_first_procedure}, n {static_cast<int>(input.size())}; i < n; i++) {
            vector<int> extracted_procedure {extract_procedure(input.at(i))};
            move_crates(extracted_procedure);
        }
    }

    vector<int> extract_procedure(const string procedure) {
        istringstream procedure_stream(procedure);
        int quantity_to_be_moved, from_stack, to_stack;
        string garbage_string;

        procedure_stream >> garbage_string >> quantity_to_be_moved >> garbage_string >> from_stack >> garbage_string >> to_stack;

        from_stack--, to_stack--;

        vector<int> extracted_procedure {quantity_to_be_moved, from_stack, to_stack};

        return extracted_procedure;
    }

    void move_crates(const vector<int> extracted_procedure) {
        int quantity_to_be_moved {extracted_procedure.at(0)};
        int from_stack {extracted_procedure.at(1) };
        int to_stack {extracted_procedure.at(2)};

        int crate_index_to_move_by_9001 {static_cast<int>(this->stacks_crate_mover_9001.at(from_stack).size()) - quantity_to_be_moved};

        for (int i {0}; i < quantity_to_be_moved; i++) {
            int crate_to_move_by_9000 {this->stacks_crate_mover_9000[from_stack].back()};
            this->stacks_crate_mover_9000[from_stack].pop_back();

            int crate_to_move_by_9001 {this->stacks_crate_mover_9001[from_stack].at(crate_index_to_move_by_9001)};
            auto it = this->stacks_crate_mover_9001[from_stack].begin();
            this->stacks_crate_mover_9001[from_stack].erase(it + crate_index_to_move_by_9001);

            this->stacks_crate_mover_9000[to_stack].push_back(crate_to_move_by_9000);
            this->stacks_crate_mover_9001[to_stack].push_back(crate_to_move_by_9001);
        }
    }

    void initialize_top_stacks() {
        for (int i {0}; i < 9; i++) {
            if (this->stacks_crate_mover_9000[i].size())
                this->top_stacks_crate_mover_9000 += this->stacks_crate_mover_9000[i].back();

            if (this->stacks_crate_mover_9001[i].size())
                this->top_stacks_crate_mover_9001 += this->stacks_crate_mover_9001[i].back();
        }
    }

public:
    Supply_Stacks(vector<string> input): top_stacks_crate_mover_9000{""}, top_stacks_crate_mover_9001{""} {
        for (int i = 0; i < 9; i++)
            this->stacks_crate_mover_9000.push_back(vector<char>());

        initialize_stacks_state(input);
        run_rearrangement_procedure(input);
        initialize_top_stacks();
        print_output();
    }

    void print_output() const {
        cout << this->top_stacks_crate_mover_9000 << "\n" << this->top_stacks_crate_mover_9001 << "\n";
    }
};

vector<string> read_input_from_file() {
    ifstream file("input.txt");

    if (!file.is_open()) {
        cout << "\nError in opening file.\n";
        exit(EXIT_FAILURE);
    }

    vector<string> input;
    for (string line; getline(file, line); input.push_back(line));
    return input;
}

int main() {
    vector<string> input {read_input_from_file()};
    Supply_Stacks supply_stacks(input);
    return 0;
}
