#include<iostream>
#include<vector>
using namespace std;

int findArea(vector<int> hights){
    int n = hights.size();
    int leftMax = 0 , rightMax = 0 , res = 0;
    for(int i=0 ; i<n ; i++){
        leftMax = 0 , rightMax = 0;
        for(int j=0 ; j<i ; j++){
            leftMax = max(leftMax , hights[j]);
        }
        for(int j=i+1 ; j<n ; j++){
            rightMax = max(rightMax , hights[j]);
        }
        if(min(leftMax , rightMax) > hights[i]){
            res += (min(leftMax , rightMax) - hights[i]);
        }
        
    }
    return res;
}

int main(){
    int arr[12]={0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> hights;
    for(int i=0 ; i<12 ; i++)hights.push_back(arr[i]);
    cout<<findArea(hights);
    return 0;
}
