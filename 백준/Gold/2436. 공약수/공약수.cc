#include<iostream>
#include<math.h>
using namespace std;

typedef long long ll;
ll g,l,resA=0,resB=0;

ll getGCD(ll a,ll b){
    if(b==0)return a;
    return getGCD(b,a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>g>>l;

    ll d=l/g;
    for(int i=1;i<=sqrt(d);i++){
        if(d%i==0){
            ll a=i,b=d/i;

            if(getGCD(a,b)==1){
                resA=a;
                resB=b;
            }
        }
    }

    cout<<resA*g<<' '<<resB*g;
}