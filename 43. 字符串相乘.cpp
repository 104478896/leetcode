/*给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。*/
class Solution {
public:
    string add(string str1,string str2){
        int index1=str1.size()-1;
        int index2=str2.size()-1;
        int count=0;
        string res;
        while(index1>=0||index2>=0){
            if(index1<0){
                int sum=str2[index2]-'0'+count;
                res+=to_string(sum%10);
                count=sum/10;
                index2--;
            }else if(index2<0){
                int sum=str1[index1]-'0'+count;
                res+=to_string(sum%10);
                count=sum/10;
                index1--;
            }else{
                int sum=str1[index1]-'0'+str2[index2]-'0'+count;
                res+=to_string(sum%10);
                count=sum/10;
                index1--;
                index2--;
            }
        }
        if(count){
            res+=to_string(count);
        }
        reverse(res.begin(),res.end());
        return res;
    }
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0"){
            return "0";
        }
        string ans="0";
        int len1=num1.size();
        int len2=num2.size();
        for(int i=len2-1;i>=0;--i){
            string temp;
            int count=0;
            for(int j=len2-1;j>i;--j){
                temp+='0';
            }
            int num=num2[i]-'0';
            for(int j=len1-1;j>=0;--j){
                int mul=(num1[j]-'0')*num+count;
                temp+=to_string(mul%10);
                count=mul/10;
            }
            while(count){
                temp+=to_string(count%10);
                count=count/10;
            }
            reverse(temp.begin(),temp.end());
            
            ans=add(ans,temp);
            // cout<<ans<<endl;
        }
        return ans;
    }
};