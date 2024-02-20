# https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

def main():

    initial_string = input()
    final_string = input()
    operations = int(input())

    obj = AppendAndDelete(initial_string, final_string, operations)
    print("Yes" if obj.are_operations_suitable_to_replacement() else "No")


class AppendAndDelete:

    def __init__(self, initial_string, final_string, operations):

        self._initial_string = initial_string
        self._final_string = final_string
        self._operations = operations

        self._common_prefix_size_between_strings = 0
        self._are_operations_suitable_to_replacement = False

        self._append_and_delete()


    def _append_and_delete(self):

        self._common_prefix_size_between_strings = self._find_common_prefix_size_between_strings()

        size_of_different_characters_from_initial_string = len(self._initial_string) - self._common_prefix_size_between_strings
        size_of_different_characters_from_final_string = len(self._final_string) - self._common_prefix_size_between_strings

        minimal_quantity_of_operations_to_replace_string = size_of_different_characters_from_initial_string + size_of_different_characters_from_final_string
        
        self._operations -= minimal_quantity_of_operations_to_replace_string
        self._are_operations_suitable_to_replacement = self._are_operations_suitable_to_replace_string()


    def _find_common_prefix_size_between_strings(self):

        size = 0
        n = min(len(self._initial_string), len(self._final_string))
        
        while n > 0 and self._initial_string[size] == self._final_string[size]:
            size += 1
            n -= 1
        return size


    def _are_operations_suitable_to_replace_string(self):

        if self._operations < 0 or \
            (self._are_operations_bigger_than_zero_and_odd() and self._are_not_operations_enough_to_remove_and_replace_common_prefix()):
            return False
        return True


    def _are_operations_bigger_than_zero_and_odd(self):

        return self._operations > 0 and self._operations%2 == 1


    def _are_not_operations_enough_to_remove_and_replace_common_prefix(self):

        return self._operations < self._common_prefix_size_between_strings*2


    def are_operations_suitable_to_replacement(self):

        return self._are_operations_suitable_to_replacement


if __name__ == '__main__':
    main()
