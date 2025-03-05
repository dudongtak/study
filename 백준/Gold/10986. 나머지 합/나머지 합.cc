#include<iostream>
#include<map>
#include<vector>
using namespace std;

int n,m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;

    vector<long long> arr(n+1);
    map<long long,long long> mod;

    long long num;
    cin>>num;
    arr[0]=num;
    mod[arr[0]%m]++;

    for(int i=1;i<n;i++){
        cin>>num;
        arr[i]=arr[i-1]+num;
        mod[arr[i]%m]++;
    }

    long long answer=mod[0];

    for(auto M:mod){
        answer+=M.second*(M.second-1)/2;
    }
    cout<<answer;
}