#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
/**
 * 883 高斯消元解线性方程组
 * 1.找到每列的最大值
 * 2.然后当最大值所在行和没有处理过的行进行互换
 * 3.然后将互换后的行第一个非0数字化为1
 * 4.然后用当前行消去其他行
*/
const int N=105;
const double eps=1e-8;
double a[N][N];
int n;

int gauss()
{
    int r,c;
    for(c=0,r=0;c<n;c++)
    {
        int t=r;//保存列的最大值所在的行
        for(int i=r;i<n;i++)
        {
            if(fabs(a[i][c]>fabs(a[t][c])))
                t=i;
        }

        if(fabs(a[t][c])<eps)continue;//表示当前列均为0

        //将最大值所在的行交换
        for(int i=0;i<=n;i++)swap(a[t][i],a[r][i]);
        for(int i=n;i>=c;i--)a[r][i]/=a[r][c];//只能从前往后除
        for(int i=r+1;i<n;i++)//将当前这一列消为0
            if(fabs(a[i][c])>eps)
                {
                    for(int j=n;j>=0;j--)
                        a[i][j]-=a[r][j]*a[i][c];
                }

        r++;
    }

    if(r<n)
    {
        for(int i=r;i<n;i++)
            if(fabs(a[i][n])>eps)
                return 2;//存在0=其他的情况，无解

        return 1;//无穷多解
    }

    //有唯一解
    for(int i=n-2;i>=0;i--)//从倒数第二行开始更好一些
        for(int j=i+1;j<n;j++)
            a[i][n]-=a[i][j]*a[j][n];

    return 0;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n+1;j++)
            scanf("%lf",&a[i][j]);
    
    int res=gauss();
    if(res==2)puts("No solution");
    else if (res==1)puts("Infinite group solutions");
    else 
    {
        for(int i=0;i<n;i++)
            printf("%.2lf\n",a[i][n]);
    }
            
    return 0;
}