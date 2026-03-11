//
//  main.c
//  bar
//
//  Created by 匡萍 on 2026/3/11.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
{
    char s;
    int a[109];
    for(int i=0;i<='z'-'a';i++)
    {
        a[i]=0;
    }
    while(scanf("%c",&s)!=EOF)
    {
        int q = s-'a';
        int w = 'z'-s;
        if(q>=0&&w>=0)
        {
            a[q]++;
        }
    }
    int max=0;
    for(int i=0;i<='z'-'a';i++)
    {
        if(a[i]>max)
            max=a[i];
    }
    for(int j=0;j<max;j++)
    {
        for(int k=0;k<='z'-'a';k++)
        {
            if(a[k]-max+j>=0)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    for(int k=0;k<='z'-'a';k++)
    {
        char t = 'a'+k;
        printf("%c",t);
    }
    printf("\n");
    return 0;
}
