#include<iostream>
#include<algorithm>
using namespace std;

//504.转圈游戏
const int N=1e6+10;
typedef long long LL;
int n;

int qmi(int a,int k,int p)
{
	int res=1%p;
	while(k)
	{
		if(k&1)res=(LL)res*a%p;
		a=(LL)a*a%p;
		k>>=1;
	}
	return res;
}
int main()
{
	int m,x,k;
	cin>>n>>m>>k>>x;
	
	int res=(x%n+(LL)qmi(10,k,n)*m%n)%n;
	cout<<res<<endl;
	return 0;
}