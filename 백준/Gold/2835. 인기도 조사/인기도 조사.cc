#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int Max=24*60*60;
typedef long long ll;
vector<ll> tree(Max*4,0),lazy(Max*4,0);
int n,q;
string str;

void update_lazy(int node, int s,int e){
    if(lazy[node]!=0){
        tree[node]+=(ll)(e-s+1)*lazy[node];
        if(s!=e){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
}

void update(int s,int e,int node, int l,int r){
    update_lazy(node,s,e);
    if(r<s||e<l)return;
    if(l<=s&&e<=r){
        tree[node]+=(ll)(e-s+1);
        if(s!=e){
            lazy[node*2]+=1;
            lazy[node*2+1]+=1;
        }
        return;
    }
    int m=(s+e)/2;
    update(s,m,node*2,l,r);
    update(m+1,e,node*2+1,l,r);
    tree[node]=tree[node*2]+tree[node*2+1];
}

ll sum(int s,int e,int node, int l,int r){
    update_lazy(node,s,e);
    if(l>e||s>r)return 0;
    if(l<=s&&e<=r)return tree[node];

    int m=(s+e)/2;
    return sum(s,m,node*2,l,r)+sum(m+1,e,node*2+1,l,r);
}

int parseTime(const string& t){
    return stoi(t.substr(0,2)) * 3600 +
           stoi(t.substr(3,2)) * 60 +
           stoi(t.substr(6,2));
}

pair<int,int> parseLine(string str){
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    int mid = str.find('-');
    string s = str.substr(0, mid);
    string e = str.substr(mid+1);
    return {parseTime(s), parseTime(e)};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);

    cin >> n;
    cin.ignore();
    ll total=0;

    for(int i=0; i<n; i++){
        getline(cin, str);
        auto [start, end] = parseLine(str);
        if(start>end){
            update(0,Max-1,1,0,end);
            update(0,Max-1,1,start,Max-1);
            total+=(Max-start+end+1);
        }
        else{
            update(0,Max-1,1,start,end);
            total+=(end-start+1);
        }
    }


    cin >> q;
    cin.ignore();

    while(q--){
        getline(cin, str);
        auto [start, end] = parseLine(str);
        long double avg;
        if(start > end){
            ll ex=sum(0,Max-1,1,end+1,start-1);
            long double Sum=total-ex;
            avg=Sum/(Max-start+end+1);
        } else {
            long double Sum=sum(0,Max-1,1,start,end);
            avg=Sum/(end-start+1);
        }

        cout << avg << "\n";
    }
}
