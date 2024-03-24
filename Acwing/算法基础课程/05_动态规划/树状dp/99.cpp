#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 285.没有上司的舞会
 * 数状dp
*/
const int N=6010;
int h[N],e[N],ne[N],idx;
int n;
int f[N][2];
int a[N];
bool has_father[N];

void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int x)
{
    f[x][1]=a[x];
    for(int i=h[x];~i;i=ne[i])
    {
        int j=e[i];
        dfs(j);//递归求解子节点
        f[x][1]+=f[j][0];
        f[x][0]+=max(f[j][0],f[j][1]);  
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    memset(h,-1,sizeof(h));
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        has_father[a]=true;
        add(b,a);     
    }

    //找到根节点
    int root=1;
    while(has_father[root])root++;
    
    dfs(root);
    
    cout<<max(f[root][0],f[root][1])<<endl;

    return 0;
}