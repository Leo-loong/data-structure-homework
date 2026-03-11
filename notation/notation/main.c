//
//  main.c
//  notation
//
//  Created by 匡萍 on 2026/3/11.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char a[1009];
int main()
{
    scanf("%s",a);
    if(a[0]=='0')
    {
        int i;
        for(i=2;i<strlen(a);i++)
        {
            if(a[i]!='0')
            {
                break;
            }
        }
        int j=i;
        j--;
        j=-j;
        if(i==strlen(a)-1)
        {
            printf("%ce%d\n",a[strlen(a)-1],j);
        }
        else
        {
            printf("%c.",a[i]);
            for(int k = i+1;k<strlen(a);k++)
            {
                printf("%c",a[k]);
            }
            printf("e%d\n",j);
        }
    }
    else
    {
        int i;
        for(i=1;i<strlen(a);i++)
        {
            if(a[i]=='.')
            {
                break;
            }
        }
        int j=i;
        j--;
        printf("%c.",a[0]);
        for(int k=1;k<strlen(a);k++)
        {
            if(a[k]!='.')
            {
                printf("%c",a[k]);
            }
        }
        printf("e%d\n",j);
    }
    return 0;
}
