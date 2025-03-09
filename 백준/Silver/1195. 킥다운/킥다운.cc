#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string str1,str2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>str1>>str2;
    int str1_l=str1.length();
    int str2_l=str2.length();//무조건 str2 length 작게
    int Min=str1_l+str2_l;

    if(str1_l<str2_l){
        swap(str1,str2);
        swap(str1_l,str2_l);
    }

    //1. str2가 str1에 포함 되는지
    //2. str2가 str1 오른쪽으로 튀어나오는지
    //3. str2가 str1 왼쪽으로 튀어나오는지
    bool flag=true;

    for(int i=0;i<=str1_l-str2_l;i++){
        for(int j=0;j<str2_l;j++){
            if(str2[j]=='2'&&str1[i+j]=='2'){
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<str1_l;
            return 0;
        }
        flag=true;
    }
    for(int i=str1_l-1;i>str1_l-str2_l;i--){
        for(int j=0;j<str1_l-i;j++){
            if(str2[j]=='2'&&str1[i+j]=='2'){
                flag=false;
                break;   
            }
        }
        if(flag){
            Min=min(i+str2_l,Min);
        }
        flag=true;
    }
    for(int i=str2_l-1;i>0;i--){
        for(int j=0;j<str2_l-i;j++){
            if(str2[i+j]=='2'&&str1[j]=='2'){
                flag=false;
                break;
            }
        }
        if(flag){
            Min=min(Min,i+str1_l);
        }
        flag=true;
    }
    cout<<Min;
}