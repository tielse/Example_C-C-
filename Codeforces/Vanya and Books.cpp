#include<iostream>

using namespace std;

int main()
{
    long long n,dem=0;
    cin>>n;
    for(long long i=1;i<=n;i*=10)
        dem+=n-i+1;
    cout<<dem;
    return 0;
}
