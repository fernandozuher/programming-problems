#include <stdio.h>
#include <stdlib.h>

/*
 * Complete the 'kangaroo' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER x1
 *  2. INTEGER v1
 *  3. INTEGER x2
 *  4. INTEGER v2
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
char* kangaroo(int x1, int v1, int x2, int v2) {
    if (v2 >= v1)
        return "NO";
    for (; x1 < x2; x1 += v1, x2 += v2);
    return x1 == x2 ? "YES" : "NO";
}

int main() {
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");
    
    int input[4];
    for (int i = 0; i < 4; scanf("%d", &input[i++]));

    int x1 = input[0];
    int v1 = input[1];
    int x2 = input[2];
    int v2 = input[3];

    char* result = kangaroo(x1, v1, x2, v2);
    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}
