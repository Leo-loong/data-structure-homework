//
//  main.c
//  cycle
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
        q->link = list;
        if(list==NULL)
            list=q;
        else
            tail->link=q;
        tail=q;
        scanf("%d",&n);
    }
    tail->link = list;
    struct node *current,*prev;
    current = list;
    prev = tail;
    while(current->link != current)
    {
            printf("%d ", current->n);
            prev->link = current->link;
            struct node *to_delete = current;
            current = current->link->link;
            prev = prev->link;
            free(to_delete);
        }
        printf("%d", current->n);
        free(current);
    return 0;
}
