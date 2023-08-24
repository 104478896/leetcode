/*给你两个字符串 start 和 target ，长度均为 n 。每个字符串 仅 由字符 'L'、'R' 和 '_' 组成，其中：

字符 'L' 和 'R' 表示片段，其中片段 'L' 只有在其左侧直接存在一个 空位 时才能向 左 移动，而片段 'R' 只有在其右侧直接存在一个 空位 时才能向 右 移动。
字符 '_' 表示可以被 任意 'L' 或 'R' 片段占据的空位。
如果在移动字符串 start 中的片段任意次之后可以得到字符串 target ，返回 true ；否则，返回 false 。

 */
 class Solution {
public:
    bool canChange(string start, string target) {
        string s=start;
        s.erase(remove(s.begin(),s.end(),'_'),s.end());
        string t=target;
        t.erase(remove(t.begin(),t.end(),'_'),t.end());
        if(s!=t){
            return false;
        }
        //i为start中的下标，j为target中的下标
        //对于L字符，当i<j时，表明在start中的L的下标在target的左侧，L字符无法右移，返回false
        //对于R字符，当i>j时，表明在start中的R的下标在target的右侧，R字符无法左移，返回false
        for(int i=0,j=0;i<start.size();++i){
            if(start[i]=='_'){//找到第一个字母
                continue;
            }
            while(target[j]=='_'){//找到第一个字母
                j++;
            }
            //当i==j时，表明在当前下标处start和target的字符相同，直接跳过
            //当i!=j时，如果i<j同时start的字符为L，返回false;
            //         如果i>j同时start的字符为R，返回false;
            if(i!=j&&((start[i]=='L')==(i<j))){
                return false;
            }
            j++;
        }
        return true;
    }
};