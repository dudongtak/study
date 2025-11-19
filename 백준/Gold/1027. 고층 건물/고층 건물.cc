#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> b;

 
int watch(int idx){
    int cnt=0;
    for(int i=0;i<n;i++){
        if(idx==i)continue;
        double s=(double)(b[idx]-b[i])/(idx-i);
        bool flag=true;
        if(i<idx){
            for(int j=i+1;j<idx;j++){
                double tmp=(double)(b[idx]-b[j])/(idx-j);
                if(tmp<=s){
                    flag=false;
                    break;
                }
            }
        }
        else{
            for(int j=idx+1;j<i;j++){
                double tmp=(double)(b[idx]-b[j])/(idx-j);
                if(tmp>=s){
                    flag=false;
                    break;
                }
            }
        }
        if(flag)cnt++;
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    b.resize(n);

    for(int i=0;i<n;i++)cin>>b[i];

    int answer=0;
    for(int i=0;i<n;i++)answer=max(answer,watch(i));
    cout<<answer;
}