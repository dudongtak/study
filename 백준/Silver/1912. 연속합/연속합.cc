#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;
    vector<int> arr(N);
    vector<int> dp(N);
    for(int i=0;i<N;i++)cin>>arr[i];
    dp[0]=arr[0];

    int answer=dp[0];
    for(int i=1;i<N;i++){
        dp[i]=max(dp[i-1]+arr[i],arr[i]);
        answer=max(dp[i],answer);
    }
    cout<<answer;
}