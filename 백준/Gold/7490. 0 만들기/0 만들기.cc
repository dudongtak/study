#include<iostream>
#include<string>
#include<set>
using namespace std;

int T,N;
set<string> answer;

bool check(string str){
    string s;
    int v=0;
    for(int i=0;i<str.size();i++){
        if(str[i]==' '){
            continue;
        }
        else if(str[i]>'0'&&str[i]<='9'){
            s.push_back(str[i]);
        }
        else{
            int num=stoi(s);
            v+=num;
            s.clear();
            s.push_back(str[i]);
        }
    }
    int num=stoi(s);
    v+=num;
    return v==0;
}

void dfs(int num,string str){
    if(num==N){
        if(check(str)){
            answer.insert(str);
        }
        return;
    }
    dfs(num+1,str+"+"+to_string(num+1));
    dfs(num+1,str+" "+to_string(num+1));
    dfs(num+1,str+"-"+to_string(num+1));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>T;

    while(T--){
        cin>>N;
        answer.clear();
        
        dfs(1,"1");
        for(auto str:answer){
            cout<<str<<"\n";
        }
        cout<<"\n";
    }
}