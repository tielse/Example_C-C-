#include<iostream>
using namespace std;
int main() {
    int n,x,rot=0,i; cin>>n;
    cin>>x;rot=n-x;
    for(i=1;i<n;++i) {
        cin>>x;
        if(i&1) {if(((x-rot+n)%n)!=i)break;}
        else if(((x+rot)%n)!=i)break;
    }
    if(i==n)cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
