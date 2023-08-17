/*给你一个 rows x cols 大小的矩形披萨和一个整数 k ，矩形包含两种字符： 'A' （表示苹果）和 '.' （表示空白格子）。你需要切披萨 k-1 次，得到 k 块披萨并送给别人。

切披萨的每一刀，先要选择是向垂直还是水平方向切，再在矩形的边界上选一个切的位置，将披萨一分为二。如果垂直地切披萨，那么需要把左边的部分送给一个人，如果水平地切，那么需要把上面的部分送给一个人。在切完最后一刀后，需要把剩下来的一块送给最后一个人。

请你返回确保每一块披萨包含 至少 一个苹果的切披萨方案数。由于答案可能是个很大的数字，请你返回它对 10^9 + 7 取余的结果。

 */
 class Arrsum{
private:
    vector<vector<int>>sum;

public:
    Arrsum(vector<string> &arr){
        int m=arr.size();
        int n=arr[0].size();
        sum=vector<vector<int>>(m+1,vector<int>(n+1));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                // 二维前缀和模板（'A' 的 ASCII 码最低位为 1，'.' 的 ASCII 码最低位为 0）
                sum[i+1][j+1]=sum[i+1][j]+sum[i][j+1]-sum[i][j]+(arr[i][j]&1);
                
            }
        }
    }
    // 返回左上角在 (r1,c1) 右下角在 (r2-1,c2-1) 的子矩阵元素和（类似前缀和的左闭右开）
    int query(int r1,int c1,int r2,int c2){
        cout<<sum[r2][c2]-sum[r2][c1]-sum[r1][c2]+sum[r1][c1]<<endl;
        return sum[r2][c2]-sum[r2][c1]-sum[r1][c2]+sum[r1][c1];
    }
};



class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        const int MOD=1e9+7;
        Arrsum as(pizza);
        int m=pizza.size();
        int n=pizza[0].size();
        int f[k][m][n];
        for(int c=0;c<k;++c){
            for(int i=0;i<m;++i){
                for(int j=0;j<n;++j){
                    if(c==0){
                        f[c][i][j]=as.query(i,j,m,n) ? 1 : 0;
                        continue;
                    }
                    int res=0;
                    for(int j2=j+1;j2<n;++j2){
                        if(as.query(i,j,m,j2)){
                            res = (res+f[c-1][i][j2])%MOD;
                        }
                    }
                    for(int i2=i+1;i2<m;++i2){
                        if(as.query(i,j,i2,n)){
                            res = (res+f[c-1][i2][j])%MOD;
                        }
                    }
                    f[c][i][j]=res;
                    
                }
            }
        }
        return f[k-1][0][0];
    }
};