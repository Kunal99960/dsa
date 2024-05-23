#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long  cows[N];
long long n,c;
bool isw(long long h){
    long long cc=c,l=-1;
    for (int i = 0; i < n; i++)
    {
        if(((cows[i]-l)>=h) || l==-1){
            l=cows[i];
            cc--;
        }
        if(cc==0){
            break;
        }
    }
    return cc==0;
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
    cin>>n>>c;
    for (int i = 0; i < n; i++)
    {
        cin>>cows[i];
    }
    sort(cows,cows+n);
    long long  l=0,h=1e9,mid;
    while (h-l>1)
    {
        mid=(h+l)/2;
        if(isw(mid)){
            l=mid;
        }
        else{
            h=mid-1;
        }
    }
    if(isw(h)) cout<<h<<endl;
    else cout<<l<<endl;
    }
}