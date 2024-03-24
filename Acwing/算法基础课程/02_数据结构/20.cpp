#include<iostream>
using namespace std;
/**
 * 826.单链表
 * 使用数组来模拟实现单链表的一些操作
 *
 * 
*/
const int N=1e6+10;
//e表示节点的值，ne表示下个节点的index,
int head,e[N],ne[N],idx;

void list_init()
{
    head=-1;//表示当前链表为空
    idx=0;//指向最后一个节点的下一个位置
}


void add_to_head(int x)
{
    e[idx]=x;
    ne[idx]=head;
    head=idx;
    idx++;
}

void add(int k,int x)
{
    e[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx;
    idx++;
}
//删除第k个插入的数后边的数:后边的数指的是在链表中的后一个数
void remove(int k)
{
    ne[k]=ne[ne[k]];
}

int main()
{
    int M;
    cin>>M;
    //链表初始化
    list_init();

    while(M--)
    {
        char op;
        int k,x;
        
        scanf(" %c",&op);//这样会跳过前面的空白字符，（scanf默认不会跳过）写的时候要注意，或者使用cin


        if(op=='H')
        {
            scanf("%d",&x);
            add_to_head(x);
        }
        else if(op=='I')
        {
            scanf("%d%d",&k,&x);
            add(k-1,x);
        }
        else{
            scanf("%d",&k);
            if(k==0)
            {
                head=ne[head];
            }
            else{
                remove(k-1);
            }
        }
    }

    //遍历链表，进行输出
    for(int i=head;i!=-1;i=ne[i])cout<<e[i]<<" ";
    cout<<endl;

    return 0;
}