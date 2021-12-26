// time complexity O(n)
//given input a sorted array

#include<bits/stdc++.h>
using namespace std;

int pairSumPattern(int a[] , int n , int k){
    int low = 0;
    int high =n-1;

    while(low<high){
        if( a[low] + a[high] == k){
            cout<<low<<" "<<high<<endl;
            return 1;
        }else if( a[low]+a[high] > k){
            high--;
        }else{
            low++;
        }
    }
    return 0;
}

int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i = 0 ; i<n; i++){
        cin >> a[i];
    }
    pairSumPattern(a , n , k);
    return 0;
}
