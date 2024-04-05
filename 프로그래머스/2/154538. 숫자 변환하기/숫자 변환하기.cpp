#include <string>
#include <vector>
#include<algorithm>
using namespace std;


int solution(int x, int y, int n) {
    vector<int> dp(1000001,1000001);
    dp[x]=0;
    for(int i=x+1;i<=y;i++){
        int n1=1000001,n2=1000001,n3=1000001;
        if(i%2==0&&dp[i/2]!=1000001)n1=dp[i/2]+1;
        if(i%3==0&&dp[i/3]!=1000001)n2=dp[i/3]+1;
        if(i-n>0&&dp[i-n]!=1000001)n3=dp[i-n]+1;
        dp[i]=min(min(n1,n2),n3);
    }
    if(dp[y]==1000001)return -1;
    return dp[y];
}