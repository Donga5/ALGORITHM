#include<iostream>
#include<algorithm>
using namespace std;

//4968互质数的个数
//欧拉函数，快速幂,一定要千万注意数据范围，尤其是变量的类型

typedef long long LL;
const int mod=998244353;
LL a,b;

int qmi(LL a,LL k)
{
	int res=1;
	while(k)
	{
		if(k&1)res=(LL)res*a%mod;
		a=(LL)a*a%mod;
		k>>=1;
	}
	return res;
}

int main()
{
	cin>>a>>b;
	
	if(a==1)
	{
		cout<<0<<endl;
		return 0;
	}
	
	LL res=a,x=a;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
		{
			while(x%i==0)x/=i;
			res=res/i*(i-1);
		}
	if(x>1)res=res/x*(x-1);
	
	cout<<qmi(a,b-1)*res%mod<<endl;
	return 0;
}