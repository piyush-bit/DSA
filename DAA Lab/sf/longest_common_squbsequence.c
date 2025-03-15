#include<stdio.h>
#include<stdlib.h>
    int stringLen(char * s){
        int ans =0; 
        while(s[ans]!='\0'){
            ans++;
        }
        return ans ;
    }
// Function to find the longest common subsequence (LCS)
char *lcs(char *str1, char *str2, int n, int m) {
    if (n == 0 || m == 0) {
        char *emptyStr = (char *)malloc(1);
        emptyStr[0] = '\0';
        return emptyStr;
    }

    if (str1[0] == str2[0]) {
        char *res = lcs(str1 + 1, str2 + 1, n - 1, m - 1);
        int len = stringLen(res);
        char *newStr = (char *)malloc(len + 2);
        newStr[0] = str1[0];
        strcpy(newStr + 1, res);
        free(res);
        return newStr;
    }

    char *ans1 = lcs(str1 + 1, str2, n - 1, m);
    char *ans2 = lcs(str1, str2 + 1, n, m - 1);

    char *finalAns;
    if (stringLen(ans1) > stringLen(ans2)) {
        finalAns = ans1;
        free(ans2);
    } else {
        finalAns = ans2;
        free(ans1);
    }

    return finalAns;
}

    

int main(){
    char str1[100];
    char str2[100];
    char ans[100];

    printf("enter size of first string");
    int n;
    scanf("%d",&n);
    printf("enter first string");
    scanf("%s",str1);
    printf("enter size of second string");
    int m;
    scanf("%d",&m);
    printf("enter string");
    scanf("%s",str2);
    printf("%s",lcs(str1,str2,n,m));
    return 0;
}

