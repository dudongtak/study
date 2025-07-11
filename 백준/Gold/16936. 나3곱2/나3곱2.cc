#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

int N;
typedef long long ll;
vector<ll> arr;
map<ll,int> m;
vector<vector<int>> arrs(101);

bool check(int i,string s,int depth){
    if(depth==N-1){
        cout<<s;
        return true;
    }
    for(int j=0;j<arrs[i].size();j++){
        if(check(arrs[i][j],s+" "+to_string(arr[arrs[i][j]]),depth+1))return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;
    arr.resize(N);

    for(int i=0;i<N;i++){
        cin>>arr[i];
        m[arr[i]]=i;
    }

    for(int i=0;i<N;i++){
        if(m.find(arr[i]*3)!=m.end())arrs[m[arr[i]*3]].push_back(i);
        if(arr[i]%2==0&&m.find(arr[i]/2)!=m.end())arrs[m[arr[i]/2]].push_back(i);
    }
    for(int i=0;i<N;i++)if(check(i,to_string(arr[i]),0))break;
}