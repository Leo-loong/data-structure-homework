//
//  main.c
//  area
//
//  Created by 匡萍 on 2026/3/16.
//

#include <stdlib.h>
#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int main()
{
    int ax1,ay1,ax2,ay2;
    int bx1,by1,bx2,by2;
    scanf("%d%d%d%d",&ax1,&ay1,&ax2,&ay2);
    scanf("%d%d%d%d",&bx1,&by1,&bx2,&by2);
    int max_ax=max(ax1,ax2);
    int min_ax=min(ax1,ax2);
    int max_bx=max(bx1,bx2);
    int min_bx=min(bx1,bx2);
    int max_ay=max(ay1,ay2);
    int min_ay=min(ay1,ay2);
    int max_by=max(by1,by2);
    int min_by=min(by1,by2);
    if(min(max_ax,max_bx)-max(min_ax,min_bx)>0&&min(max_ay,max_by)-max(min_ay,min_by)>0)
    {
        int X =min(max_ax,max_bx)-max(min_ax,min_bx);
        int Y =min(max_ay,max_by)-max(min_ay,min_by);
        int sum =X*Y;
        printf("%d\n",sum);
    }
    else
    {
        printf("0\n");
    }
    return 0;
}
