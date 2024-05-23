#include<bits/stdc++.h>
using namespace std;
int main() 
{ 
    int arr[]={1,2,4,6,8,9,11};
    int l=0,h=6;
    int s;
    cin>>s;
    while(h>=l){
        int m=(h+l)/2;
        if(arr[m]==s){
            cout<<m;
            break;
        }
        else if(s>arr[m]){
            l=m+1;
        }
        else{
            h=m-1;
        }
    }
}