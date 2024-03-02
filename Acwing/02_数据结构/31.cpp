#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

/**
 * 手写堆
*/
const int N=1e5+10;
int h[N],ph[N],hp[N],sz=0;//ph[k]记录第k个插入的数在h[]对应的下标
//hp[j]下标为j的数对应是第几个插入数字


void heap_swap(int a,int b)
{   
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);//指针也得进行交换
    swap(h[a],h[b]);//交换数值
}
void down(int u)
{
    int t=u;
    if(2*u<=sz&&h[2*u]<h[t])t=2*u;
    if(2*u+1<=sz&&h[2*u+1]<h[t])t=2*u+1;
    if(u!=t)
    {
        heap_swap(u,t);
        down(t);
    }
}

void up(int u)
{
    while(u/2&&h[u/2]>h[u])
    {
        heap_swap(u,u/2);
        u/=2;
    }
}
int main()
{
    int k=0;//记录当前是第几个插入的数字 
    int m;
    scanf("%d",&m);
    while(m--)
    {
        char op[5];
        int k1,x;

        scanf("%s",op);
        if(!strcmp(op,"I"))
        {  
            scanf("%d",&x);
            k++;
            sz++;
            hp[sz]=k;
            ph[k]=sz;
            h[sz]=x;
            up(sz);
        }
        else if(!strcmp(op,"PM"))
        {
            printf("%d\n",h[1]);
        }
        else if(!strcmp(op,"DM"))
        {
            heap_swap(1,sz);
            sz--;
            down(1);
        }
        else if(!strcmp(op,"D")){
            scanf("%d",&k1);
            k1=ph[k1];//k直接指向在堆中的位置
            heap_swap(k1,sz);
            sz--;  
            down(k1),up(k1); //down和up最多只会执行一个 
        }
        else{
            scanf("%d%d",&k1,&x);
            k1=ph[k1];
            h[k1]=x;
            down(k1),up(k1);
        }

    }
    return 0;
}