//
//  main.c
//  enough
//
//  Created by 匡萍 on 2026/3/24.
//

#include <stdio.h>
#include <stdlib.h>
struct node {
        int n;
        struct node *link;
};

int main()
{
    int n;
    struct node *list=NULL, *tail, *q;
    
    scanf("%d",&n);
    while(n!=-1){
        q = (struct node *)malloc(sizeof(struct node));
        q->n = n;
        q->link = NULL;
        
        if(list == NULL)
            list = q;
        else
            tail->link = q;
        tail=q;
        
        scanf("%d",&n);
    }
    struct node *a;
    a = list;
    while(a!=NULL)
    {
        int num[10009];
        int i=0;
        int N = a->n;
        while(N > 0)
        {
            num[i] = N%10;
            N=N/10;
            i++;
        }
        if(i<=3)
        {
            printf("%d ",a->n);
        }
        else
        {
            int w=i%3;
            if(w!=0)
            {
                for(int e=0;e<w;e++)
                {
                    printf("%d",num[i-1-e]);
                }
                printf(",");
            }
            i = i-w;
            for(int e =1;e<=i;e++)
            {
                printf("%d",num[i-e]);
                if(e!=i&&e%3==0)
                {
                    printf(",");
                }
            }
            printf(" ");
        }
        a=a->link;
    }
    return 0;
}







