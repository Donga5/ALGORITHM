#include<iostream>
#include<cstring>
using namespace std;

/**举例：
 * 利用双指针算法求出输入句子中每个单词，每个单词以一行进行输出
*/
int main()
{
    char str[100];
    gets(str);//可以包含空格

    int len=strlen(str);

    for(int i=0;i<len;i++)
    {
        int j=i;//每次开始的时候j和i的位置相同
        while(j<len&&str[j] != ' ')j++;
        
        //题目逻辑，可以替换
        for(int k=i;k<=j;k++)cout<<str[k];
        cout<<endl;

        //i移动
        i=j;
    }    
    return 0;
}