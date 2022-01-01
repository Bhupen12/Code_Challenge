#include<iostream>
using namespace std;

int unicNum(int arr[] , int n){

    int xorSum = 0;
    for(int i=0 ; i<n ; i++){
        xorSum = xorSum ^ arr[i];
    }
    return xorSum;

}

int main(){

    int arr[7] = {1,2,4,3,2,3,1};
    cout<<unicNum( arr , 7);
    return 0;
}
