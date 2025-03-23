#include<iostream>
#include<vector>
using namespace std;

long long Min,Max;
vector<bool> N(1000001,true);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>Min>>Max;

    for(long long i=2;i*i<=Max;i++){
        long long num=Min/(i*i);
        if(num*i*i<Min)num++;

        while(num*i*i<=Max){
            if(N[num*i*i-Min])N[num*i*i-Min]=false;
            num++;
        }
    }

    long long cnt=Max-Min+1;
    for(long long i=Min;i<=Max;i++){
        if(!N[i-Min])cnt--;
    }
    cout<<cnt;
}