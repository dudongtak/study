#include<iostream>
#include<math.h>
using namespace std;

int t,s,e;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;

    while(t>0){
        t--;
        cin>>s>>e;

        int size=e-s;
        int s=sqrt(size);
        int m=(pow(s,2)+pow(s+1,2))/2;
        if(s*s==size){
            cout<<s*2-1<<"\n";
        }
        else if(m>=size){
            cout<<s*2<<"\n";
        }
        else{
            cout<<s*2+1<<"\n";
        }
    }
}