#include <stdio.h>
#include <string.h>
int find_longest(char *X, char *Y, int m, int n);
int main(){
    char string1[100];
    char string2[100];
    scanf("%s",string1);
    scanf("%s",string2);
    int len1 = strlen(string1);
    int len2 = strlen(string2);
    printf("%d",find_longest(string1, string2, len1, len2));
    return 0;
}
int find_longest (char *string1, char *string2, int len1, int len2){
    int longest[len1 + 1][len2 + 1];
    int len = 0;
    int row, col;
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0 || j == 0)
                longest[i][j] = 0;
            else if (string1[i - 1] == string2[j - 1]) {
                longest[i][j] = longest[i - 1][j - 1] + 1;
                if (len < longest[i][j]) {
                    len = longest[i][j];
                    row = i;
                    col = j;
                }
            }
            else
                longest[i][j] = 0;
        }
    }
    return len;
}