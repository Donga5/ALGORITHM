#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

/**
 * 1225正则问题
 * 递归
*/
const int N=100+10;
char str[N];
int k=0;

int dfs()
{
    int res=0;
    while(k<strlen(str))
    {
        if(str[k]=='(')
        {
            k++;
            res+=dfs();
            k++;//匹配右括号,这里的k++不能放到在)的判断中的原因:
                //因为如果括号中间有 | 还会进入下一层，此时和左括号不在同一层
                //遇到右括号的时候，先跳出|这一层，然后跳出括号这一层，回溯的时候才让k++
        }
        else if(str[k]=='|')
        {
            k++;
            res=max(res,dfs());
        }
        else if(str[k]==')')
        {
            break;
        }
        else
        {
            //x就直接++
            k++;
            res++;
        }
    }
    return res;
}
int main()
{
    scanf("%s",str);
    cout<<dfs()<<endl;
    return 0;
}