#include<iostream>
#include<algorithm>
#include<set>
#include<string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,n;
    cin>>N;
    set<string> s;
    while(N--){
        string tmp,str;
        cin>>n;

        while(n--){
            cin>>tmp;
            str+=' '+tmp;
            s.insert(str);
        }
    }
    for(const auto& str:s){
        int cnt=count(str.begin(),str.end(),' ');
        int idx=str.find_last_of(' ');
        string answer=str.substr(idx+1);

        for(int i=0;i<2*(cnt-1);i++)cout<<'-';
        cout<<answer<<"\n";
    }
}