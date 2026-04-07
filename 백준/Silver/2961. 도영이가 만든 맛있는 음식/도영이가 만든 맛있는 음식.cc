#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

typedef long long ll;
int n;
vector<ll> acd;
vector<ll> ace;
ll Min=1e18;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    for(int i=0;i<n;i++){
        int d,e;
        cin>>d>>e;
        acd.push_back(d);
        ace.push_back(e);
    }

    for(int mask=1;mask<(1<<n);mask++){
        long long s=1;
        long long b=0;

        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                s*=acd[i];
                b+=ace[i];
            }
        }

        Min=min(Min,llabs(s-b));
    }
    cout<<Min;
}