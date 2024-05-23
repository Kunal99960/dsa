#include<bits/stdc++.h>
using namespace std;
int sum(int a){
    int s=0;
    while(a>10){
        s+=a%10;
        a/=10;
    }
    s+=a;
    return s;
}
int checkprime(int a){
    if(a==1) return 0;
    for (int i = 2; i < a; i++)
    {
        if(a%i==0) return 0;
    }
    return a;
    
}
int main(){
    int a,b;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        if(checkprime(i) & checkprime(sum(i))){
            cout<<i<<" ";
        }
    }
    return 0;
}