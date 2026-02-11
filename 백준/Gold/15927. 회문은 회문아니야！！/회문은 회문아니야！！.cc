#include<iostream>
#include<string>
using namespace std;

int what_status(string str){
    int l=0,r=str.size()-1;
    while(l<r){
        if(str[l]!=str[r])return 3;
        l++;
        r--;
    }
    for(int i = 1; i < str.size(); i++){
        if(str[i] != str[0]) return 2;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin>>str;
    
    int status=what_status(str);
    if(status==1)cout<<-1;
    else if(status==2)cout<<str.size()-1;
    else cout<<str.size();
}