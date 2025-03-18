#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int l,c;
char v[5]={'a','e','i','o','u'};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>l>>c;

    vector<char> password(c);
    vector<int> temp(c,0);

    for(int i=0;i<c;i++){
        cin>>password[i];
        if(i<l){
            temp[i]=1;
        }
    }

    sort(password.begin(),password.end());

    do{
        string str="";
        for(int i=0;i<password.size();i++){
            if(temp[i]==1){
                str+=password[i];
            }
        }
        int cnt=0;
        for(int i=0;i<5;i++){
            if(find(str.begin(),str.end(),v[i])!=str.end()){
                cnt++;
            }
        }
        if(l-cnt>=2&&cnt>=1)cout<<str<<"\n"; 
    }while(prev_permutation(temp.begin(),temp.end()));
}