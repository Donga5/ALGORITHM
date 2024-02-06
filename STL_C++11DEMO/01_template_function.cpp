#include<iostream>
using namespace std;

//一个模板参数的情形
template <typename T> T mymax(T a, T b)
{
    return (a>b)? a:b;
}

template <typename T> T add(T a, T b)
{
    return a+b;
}

template <typename T,typename D> T sub(T a, D b)
{
    return a-b;
}

void demo1(){
    cout<<mymax(3, 7)<<endl;
    cout<<mymax(3.0, 7.0)<<endl;
    cout<<mymax('g', 'e')<<endl;
    cout<<"-----"<<endl;
}
void demo2()
{
    //显示指定模板参数类型，如果不指定自动进行推断
    cout<<mymax<int>(3,7)<<endl;
    cout<<mymax<double>(3.5,7.5)<<endl;//显示指定模板参数类型
    cout<<mymax(3.5,7.5)<<endl; //编译器会自动推导出类型
    //两个参数类型不一致，出现错误，因为只定义了一个模板参数，
    //implict cast not acceptiable for templates
    //cout<<mymax(3,7.5)<<endl; 
}



/**
 * 当返回值类型和形参类型不同(都是使用模板参数的情况):
 * 1.必须将返回值类型放到模板参数的第一个
 * 2.在使用该函数的时候必须指定返回值类型,其他类型是否指定可选
 * (因为这种情况下，返回值类型不能自动推导，形参类型能够自动推导)
*/
template <typename T,typename R> T mymax2(R a, R b)
{
    return (a>b)? a:b;
}

void demo3(){
    cout<<mymax2<int>('a','b')<<endl;//98
    cout<<mymax2<char>('a','b')<<endl;//b
    cout<<"-----"<<endl;
}

int main()
{
    //demo1();
    //demo2();
    //cout<<sub(3,7.5)<<endl;
    demo3();

    return 0;
}