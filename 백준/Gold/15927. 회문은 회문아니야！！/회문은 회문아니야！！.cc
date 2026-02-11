#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


bool is_palindrome(string str){
    int l=0;
    int r=str.size()-1;

    while(l<r){
        if(str[l]!=str[r])return false;
        r--;l++;
    }
    return true;
}

bool all_same(string str){
    for(int i=1;i<str.size();i++)if(str[i]!=str[0])return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin>>str;
    
    if(is_palindrome(str)){
        if(all_same(str))cout<<-1;
        else cout<<str.size()-1;
    }
    else{
        cout<<str.size();
    }
}