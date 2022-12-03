// Writing...

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int n;
    scanf("%d", &n);

    char *names[n], *phone[n];

    for (int i = 0; i < n; ++i) {
        char temp1[20], temp2[15];
        
        scanf("%s %s", temp1, temp2);

        names[i] = (char*) malloc(sizeof(char) * (strlen(temp1) + 1));
        phone[i] = (char*) malloc(sizeof(char) * (strlen(temp2) + 1));

        strcpy(names[i], temp1);
        strcpy(phone[i], temp2);
    }

    qsort(*names, n, )

    for (int i = 0; i < n; ++i) {
        char temp[20];
        scanf("%s", temp);

        int j;
        for (j = 0; j < n; ++j) {
            if (strcmp(temp, names[j]) == 0) {
                printf("%s=%s", temp, phone[j]);
                break;   
            }
        }
        
        if (j == n) 
            puts("\nNot found");
    }
    return 0;
}
