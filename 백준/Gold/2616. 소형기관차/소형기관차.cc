#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,s;

vector<int> people,sum;
vector<vector<int>> dp(4,vector<int>(50001,0));

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    people.resize(n+1);
    sum.resize(n+1);
    people[0]=0;
    sum[0]=0;
    for(int i=1;i<=n;i++){
        cin>>people[i];
        sum[i]=sum[i-1]+people[i];
    }
    cin>>s;
    
    for(int i=1;i<=3;i++){
        for(int j=i*s;j<=n;j++){
            dp[i][j]=max(dp[i][j-1],dp[i-1][j-s]+sum[j]-sum[j-s]);
        }
    }

    cout<<dp[3][n];
}