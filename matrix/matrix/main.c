//
//  main.c
//  matrix
//
//  Created by 匡萍 on 2026/3/16.
//

#include <stdio.h>      // 标准输入输出库（如printf、scanf、getchar、putchar）
#include <stdlib.h>     // 通用工具库（如malloc、free、rand、system）
#include <string.h>     // 字符串处理库（如memset、memcpy、strlen）
#include <time.h>       // 时间处理库（如time、srand）
#include <unistd.h>     // Unix标准库（如sleep、getpid，Windows下可能需要替换）

//                          !!! Ciallo~ !!!                             //
//C indicates a luminous linguistic orientation~//

#define In inline // 内联函数标记，用I代替inline，简化代码书写
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
    ll num;
}Object;
int cmp(const void *e1,const void *e2)
{
    const Object *s1=(const void *)e1;
    const Object *s2=(const void *)e2;
    return s1->num - s2->num ;
}
ll a[109][109];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%lld",&a[i][j]);
        }
    }
    while(1)
    {
        char s;
        getchar();
        scanf("%c",&s);
        if(s=='#')
            break;
        else
        {
            if(s=='+')
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        int q;
                        scanf("%d",&q);
                        a[i][j]=a[i][j]+q;
                    }
                }
            }
            else
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        int q;
                        scanf("%d",&q);
                        a[i][j]=a[i][j]-q;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==0)
            {
                printf("    %lld",a[i][j]);
            }
            else
            {
                int w=0;
                ll e =a[i][j];
                if(a[i][j]<0)
                {
                    w++;
                    e=-e;
                }
                while(e>0)
                {
                    e=e/10;
                    w++;
                }
                w = 5-w;
                for(int r=0;r<w;r++)
                {
                    printf(" ");
                }
                printf("%lld",a[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
