#include<iostream>
#include<string>
using namespace std;

/**
 * 835 Trie字符串统计
*/
const int N=1e5+10;
//son表示子节点，因为全是小写字母，最多有26个子节点
//cnt表示以当前节点为字节点的单词个数，
//idx表示当前插入的最后一个节点的编号
int son[N][26],cnt[N],idx=0;

char x[N];


void insert(char str[])
{   
    int p=0;//当前正在操作的树上的节点
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'a';//将字母映射到数字
        if(!son[p][u])son[p][u]=++idx;//创建子节点
        p=son[p][u];
    }
    cnt[p]++;
}
/**
 * 返回找到的个数
*/
int search(char str[])
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'a';
        if(!son[p][u])return 0;
        else
            p=son[p][u];
    }
    return cnt[p];
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {   
        // char op[2];//操作和操作数,能够接受中间的空格
        // scanf("%s%s",op,x);
        // if(op[0]=='I')insert(x);
        // else  printf("%d\n",search(x));

        char op;
        scanf(" %c",&op);
        scanf("%s",x);
        if(op=='I')insert(x);
        else printf("%d\n",search(x));

        // //这种方法运行时长为121ms,而第一种而57ms
        // char op;
        // cin>>op>>x;
        // if(op=='I')insert(x);
        // else printf("%d\n",search(x));

    }

    return 0;
}