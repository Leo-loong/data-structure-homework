//
//  main.c
//  books
//
//  Created by 匡萍 on 2026/3/24.
//

#include <stdio.h>      // 标准输入输出库（如printf、scanf、getchar、putchar）
#include <stdlib.h>     // 通用工具库（如malloc、free、rand、system）
#include <string.h>     // 字符串处理库（如memset、memcpy、strlen）
#include <math.h>       // 数学函数库（如sqrt、pow、sin）
#include <time.h>       // 时间处理库（如time、srand）
#include <unistd.h>     // Unix标准库（如sleep、getpid，Windows下可能需要替换）

//                          !!! Ciallo~ !!!                             //
//C indicates a luminous linguistic orientation~//

#define I inline // 内联函数标记，用I代替inline，简化代码书写
#define max(a,b) ((a)>(b)?(a):(b)) // 自定义最大值函数，返回a和b中较大的数
#define min(a,b) ((a)<(b)?(a):(b)) // 自定义最小值函数，返回a和b中较小的数
#define abs(x) ((x)>0?(x):-(x)) // 自定义绝对值函数，返回x的绝对值（注意：原代码对负数0处理无影响，仅针对整数）
#define ll long long // 用ll代替long long，简化长整型变量的定义
#define db double // 用db代替double，简化双精度浮点型变量的定义
#define lb long double // 这里是笔误，正确应为long double（长双精度浮点型），用lb代替
#define N (300+5) // 原始节点数上限，值为305，用于限制数组大小（如节点相关数组）
#define M (900+5) // 虚拟节点数上限，值为905，用于虚拟节点相关数组的大小限制
#define K (200000+5) // 特殊点数量上限，值为200005，用于特殊点相关数组的大小限制
#define mod 998244353 // 定义一个大的质数
#define eps (1e-9) // 浮点精度误差值，用于判断浮点数是否相等（如两个浮点数差值小于eps则认为相等）
#define U unsigned int // 用U代替unsigned int，简化无符号整型变量的定义
#define it iterator // 用it代替iterator，迭代器（C++中常用，C语言中无此概念，这里是预留定义）
#define Gc() getchar() // 用Gc()代替getchar()，简化快读操作（getchar是比scanf更快的输入函数）
#define Me(x,y) memset(x,y,sizeof(x)) // 用Me(x,y)代替memset(x,y,sizeof(x))，快速初始化数组（如将数组x全部设为y）
#define Mc(x,y) memcpy(x,y,sizeof(x)) // 用Mc(x,y)代替memcpy(x,y,sizeof(x))，快速复制数组（将y的内容复制到x）
#define d(x,y) (n*(x-1)+(y)) // 二维坐标(x,y)转一维索引的公式（n是二维数组的行数，代码中未使用n，仅预留公式）
#define R(n) (rand()*rand()%(n)+1) // 生成1到n之间的随机数（注意：rand()返回0~RAND_MAX，两次相乘是为了扩大随机范围，避免小n时随机数分布不均）
#define Pc(x) putchar(x) // 用Pc(x)代替putchar(x)，简化字符输出操作
typedef struct Objest
{
    char name[109];
    char author[109];
    char loc[109];
    int year;
}Object;
int cmp(const void *e1,const void *e2)
{
    const Object *s1=(const void *)e1;
    const Object *s2=(const void *)e2;
    return strcmp(s1 ->name, s2->name);
}
Object a[10009];
int main()
{
    FILE *fp;
    FILE *out;
    out = fopen("ordered.txt", "w");
    fp =fopen("books.txt", "r");
    char s[10009];
    int Q = 0;
    while(fgets(s, sizeof(s), fp)!=NULL)
    {
        int i=0;
        int j=0;
        while(s[i]!=' ')
        {
            a[Q].name[j] = s[i];
            i++;
            j++;
        }
        a[Q].name[j] = '\0';
        i++;
        j=0;
        while(s[i]!=' ')
        {
            a[Q].author[j] = s[i];
            i++;
            j++;
        }
        a[Q].author[j] = '\0';
        j=0;
        i++;
        while(s[i]!=' ')
        {
            a[Q].loc[j] = s[i];
            i++;
            j++;
        }
        a[Q].loc[j] = '\0';
        i++;
        a[Q].year = 0;
        while(s[i]>='0'&&s[i]<='9')
        {
            a[Q].year = a[Q].year *10 +s[i] - '0';
            i++;
        }
        Q++;
    }
    qsort(a, Q, sizeof(Object), cmp);
    int op;
    while(~scanf("%d",&op))
    {
        getchar();
        if(op == 0)
            break;
        else if(op==1)
        {
            char A[10009];;
            fgets(A, sizeof(A), stdin);
            int i=0;
            int j=0;
            while(A[i]!=' ')
            {
                a[Q].name[j] = A[i];
                i++;
                j++;
            }
            a[Q].name[j] = '\0';
            i++;
            j=0;
            while(A[i]!=' ')
            {
                a[Q].author[j] = A[i];
                i++;
                j++;
            }
            a[Q].author[j] = '\0';
            j=0;
            i++;
            while(A[i]!=' ')
            {
                a[Q].loc[j] = A[i];
                i++;
                j++;
            }
            a[Q].loc[j] = '\0';
            i++;
            a[Q].year = 0;
            while(A[i]>='0'&&A[i]<='9')
            {
                a[Q].year = a[Q].year *10 +A[i] - '0';
                i++;
            }
            Q++;
            qsort(a, Q, sizeof(Object), cmp);
        }
        else if (op==2)
        {
            char A[1009];
            scanf("%s",A);
            for(int k=0;k<Q;k++)
            {
                if(strstr(a[k].name, A)!=NULL)
                {
                    printf("%s",a[k].name);
                    for(int w=0;w<50-strlen(a[k].name);w++)
                    {
                        printf(" ");
                    }
                    printf("%s",a[k].author);
                    for(int w=0;w<20-strlen(a[k].author);w++)
                    {
                        printf(" ");
                    }
                    printf("%s",a[k].loc);
                    for(int w=0;w<30-strlen(a[k].loc);w++)
                    {
                        printf(" ");
                    }
                    printf("%d\n",a[k].year);
                }
            }
            qsort(a, Q, sizeof(Object), cmp);
        }
        else
        {
            char A[1009];
            scanf("%s",A);
            int k=0;
            while(k<Q)
            {
                if(strstr(a[k].name, A)!=NULL)
                {
                    for(int w=k+1;w<Q;w++)
                    {
                        a[w-1] = a[w];
                    }
                    Q--;
                }
                else
                {
                    k++;
                }
            }
            qsort(a, Q, sizeof(Object), cmp);
        }
    }
    qsort(a, Q, sizeof(Object), cmp);
    for(int k=0;k<Q;k++)
    {
        fprintf(out, "%-50s",a[k].name);
        fprintf(out, "%-20s",a[k].author);
        fprintf(out, "%-30s",a[k].loc);
        fprintf(out, "%d\n", a[k].year);
    }
    fclose(fp);
    fclose(out);
    return 0;
}
