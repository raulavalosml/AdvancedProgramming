#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *substring(int i,int j,char *ch)
{
    int n,k=0;
    char *ch1;
    ch1=(char*)malloc((j-i+1)*1);
    n=j-i+1;

    while(k<n)
    {
        ch1[k]=ch[i];
        i++;k++;
    }

    return (char *)ch1;
}

int main()
{
    int i=0,j=2;
    char s[]="String";
    char *test;

    test=substring(i,j,s);
    printf("%s",test);
    free(test); //free the test 
    return 0;
}
