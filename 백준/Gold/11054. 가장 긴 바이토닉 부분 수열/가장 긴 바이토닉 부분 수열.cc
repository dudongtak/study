#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>>N;

    vector<int> arr(N);

    for(int i=0;i<N;i++)cin>>arr[i];

    vector<int> l_dp(N);
    vector<int> r_dp(N);

    for(int i=0;i<N;i++){
        l_dp[i]=1;
        for(int j=0;j<=i;j++){
            if(arr[j]<arr[i]&&l_dp[i]<l_dp[j]+1)l_dp[i]=l_dp[j]+1;
        }
    }
    for(int i=N-1;i>=0;i--){
        r_dp[i]=1;
        for(int j=N-1;j>=i;j--){
            if(arr[j]<arr[i]&&r_dp[i]<r_dp[j]+1)r_dp[i]=r_dp[j]+1;
        }
    }
    int answer=0;
    for(int i=0;i<N;i++)answer=max(answer,l_dp[i]+r_dp[i]-1);

    cout<<answer;
}