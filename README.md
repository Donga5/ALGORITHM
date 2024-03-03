
# 蓝桥杯备赛
本项目是备赛蓝桥杯时候写的一些算法，主要是参考学习Acwing算法课程，可以参考学习一下.
其他相关的一些知识参考[我的notion文档](https://donga5.notion.site/f660d51771b24f2484c6918481e8393d?pvs=4)

### Referecens
- [Acwing官网](https://www.acwing.com/activity/content/introduction/11/)
- [Acwing课程题解](https://www.cnblogs.com/littlehb/p/15393332.html)


### 常用快捷键总结
使用的IDE是vscode，以下是一些常用快捷键
- `Ctrl+Shift+P` 打开命令面板，显示的是当前context下的命令,或者是`Ctrl+shift`打开面板，然后输入`>`。
- `Ctrl + Shift + [` 将当前的代码块进行折叠，(fold region)`Ctrl + Shift + ]` 展开(unfold region)
- `Ctrl+shift+N` 运行当前代码
- `Ctrl+I`使用copilot
- `Ctrl+B`折叠侧边栏

### 编写技巧和注意事项
- 当数据的规模达到了1e6，输入输出应当尽量使用scanf和printf
    - 使用scanf("%s",str+1); **表示输入的字符串从1开始存储**
- 需要使用单个字符的时候，尽量使用字符串进行读入
- puts只能输出字符串，并且默认会输入换行符。puts在输出纯字符串的时候更快
    - **或者是单纯需要输出一个换行符的时候**
- 数值常识: pow(2,32)和 1e9相近


### 常见函数以及对应的头文件
- swap <algorithm>
- pair<>  <utility>
- strcmp <cstring> 或者<string.h> 可以用来比较两个字符串是否相同。(char[]数组表示的字符串也是可以的)
    - 如果返回值<0，则表示str1小于str2。
    - 如果返回值>0，则表示str1大于str2。
    - 如果返回值=0，则表示str1和str2相等。
- memset <cstring> 三个参数依次为数组指针,int,value，num
要注意memset是按照每个字节设置value
所以一般这个是value可取的值为0,-1。0对应0，-1对-1.
value不能取值为其他。
```
int arr[100];
memset(arr,0,sizeof(arr));
```