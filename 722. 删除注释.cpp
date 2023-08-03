/*给一个 C++ 程序，删除程序中的注释。这个程序source是一个数组，其中source[i]表示第 i 行源码。 这表示每行源码由 '\n' 分隔。

在 C++ 中有两种注释风格，行内注释和块注释。

字符串// 表示行注释，表示//和其右侧的其余字符应该被忽略。
字符串/* 表示一个块注释，它表示直到下一个（非重叠）出现的*/之间的所有字符都应该被忽略。（阅读顺序为从左到右）非重叠是指，字符串/*/并没有结束块注释，因为注释的结尾与开头相重叠。
第一个有效注释优先于其他注释。

如果字符串//出现在块注释中会被忽略。
同样，如果字符串/*出现在行或块注释中也会被忽略。
如果一行在删除注释之后变为空字符串，那么不要输出该行。即，答案列表中的每个字符串都是非空的。

样例中没有控制字符，单引号或双引号字符。

比如，source = "string s = "/* Not a comment. */ 
/*";" 不会出现在测试样例里。
此外，没有其他内容（如定义或宏）会干扰注释。

我们保证每一个块注释最终都会被闭合， 所以在行或块注释之外的/*总是开始新的注释。

最后，隐式换行符可以通过块注释删除。 有关详细信息，请参阅下面的示例。

从源代码中删除注释后，需要以相同的格式返回源代码。*/
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string>ans;
        bool flag=false;
        string temp="";
        for(auto str:source){
            
            for(int i=0;i<str.size();++i){
                if(flag){
                    if(i+1<str.size()&&str[i]=='*'&&str[i+1]=='/'){
                        flag=false;
                        i++;
                    }
                }else{
                    if(i+1<str.size()&&str[i]=='/'&&str[i+1]=='*'){
                        flag=true;
                        i++;
                    }else if(i+1<str.size()&&str[i]=='/'&&str[i+1]=='/'){
                        break;
                    }else{
                        temp+=str[i];
                    }
                }
            }
            if(!flag&&temp!=""){
                ans.push_back(temp);
                temp="";
            }

        }
        return ans;
    }
};