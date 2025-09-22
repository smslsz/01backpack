#include <iostream>
using namespace std;

int main(){ 
    int n, m;
    cin>>n>>m;//物品数与背包容量
    int v[n],w[n];//物品价值和重量
    int dp[n][m];//在前n个物品中以m为容量的背包能获得的最高价值
    //有此状态转移方程 
    //if(w[i]>j) dp[i][j]=dp[i-1][j] 不能放入
    //if(w[i]<=j]) dp[i][j]=max(dp[i-1][j], dp[i-1][j-w[i]]+v[i])
    //用双重循环m,n即可

    //也有一维dp滚动用法
    //如果仅用dp[m]记录，则必须逆序遍历
    //这是因为：
    //此时状态转移方程为
    //if(w[i]>j) dp[j]=dp[j];
    //if(w[i]<=j) dp[j]=max(dp[j], dp[j-w[i]+v[i]])
    //在调用"dp[j-w[i]]"时，这个值实际上已经被更新过了，因为我们是
    //从小到大遍历的，j-w[i]这个index先于j更新
    //如此会导致此时的dp[j-w[i]]已经不是上一行(即i-1时)的数据，可能会出错
    //因此应用for(int i=0;i<=n;i++){
    //  for(int j=m;j>0;j--)
    //}遍历
    
    //而对完全背包，只需改为
    //if(w[i]<=j]) dp[i][j]=max(dp[i-1][j], dp[i][j-w[i]]+v[i])
    //允许使用先前i这一层刚跟新过的数据
    //也允许在dp[i][j-w[i]]这个状态已经放入过i这个物品
    //在一维情形，只需正向遍历即可
}