#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,M;
typedef long long ll;
vector<ll> time;
ll answer=0;

bool is_possible(ll t){
    ll cnt=0;
    for(int i=0;i<N;i++)cnt+=t/time[i];
    if(cnt>=M)return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>M;

    time.resize(N);
    for(int i=0;i<N;i++)cin>>time[i];

    ll s=0,e=*min_element(time.begin(),time.end())*M,m;

    while(s<=e){
        m=(s+e)/2;

        if(is_possible(m)){
            e=m-1;
            answer=m;
        }
        else{
            s=m+1;
        }
    }
    cout<<answer;
}