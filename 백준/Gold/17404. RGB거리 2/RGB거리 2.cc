#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> line;
vector<vector<int>> dp;
int Max=10000000;
int n,answer=Max;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    line.resize(n,vector<int>(3));
    dp.resize(n,vector<int>(3));
    for(int i=0;i<n;i++)cin>>line[i][0]>>line[i][1]>>line[i][2];

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==j)dp[0][j]=line[0][j];
            else dp[0][j]=Max;
        }

        for(int j=1;j<n;j++){
            dp[j][0]=line[j][0]+min(dp[j-1][1],dp[j-1][2]);
            dp[j][1]=line[j][1]+min(dp[j-1][0],dp[j-1][2]);
            dp[j][2]=line[j][2]+min(dp[j-1][1],dp[j-1][0]);
        }

        for(int j=0;j<3;j++){
            if(i==j)continue;
            answer=min(dp[n-1][j],answer);
        }
    }
    cout<<answer;
}