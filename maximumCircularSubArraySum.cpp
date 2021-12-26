#include<bits/stdc++.h>
using namespace std;

int kadanes(int arr[] , int n){
    int currSum = 0;
    int maxSum = INT_MIN;
    for(int i=0 ; i<n ; i++){
        currSum += arr[i];
        if(currSum < 0){
            currSum = 0;
        }
        maxSum = max(maxSum , currSum);
    }
    return maxSum;
}


int circularSumOfSubArray(int arr[] , int n){

    //sum of element in arr
    int arrSum = 0;
    for(int i = 0 ; i<n ; i++){
        arrSum += arr[i];
    }

    //inverted arr
    int negArr[n];
    for(int i=0 ; i<n ; i++){
        negArr[i] = arr[i] * (-1);
    }

    //sum of non contributing arr
    int maxSum = kadanes(negArr , n);


    cout<<"Array Sum = "<<arrSum<<endl;
    cout<<"Max inverted sum = "<<maxSum<<endl;
    int circularSum = arrSum - maxSum*(-1);
    return circularSum;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    int circularSum = circularSumOfSubArray(arr , n);//O(n)
    cout<<"Max circular sum = "<<circularSum<<endl;
}
