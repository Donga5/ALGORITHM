#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
    //FILE* freopen(const char* filename, const char* mode, FILE* stream);
    
    freopen("./files/test.txt","r",stdin);\

    string file_content;
    cin>>file_content;
    cout<<file_content;  //遇到空格会进行截断
    fclose(stdin);
    
    
    // freopen("./files/test.txt","w",stdout);
    // cout<<"This is a test file,which used to test file operation"<<endl;
    // fclose(stdout);

    return 0;
}