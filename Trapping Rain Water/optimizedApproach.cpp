#include<iostream>
#include<vector>
using namespace std;

int findArea(vector<int> heights){
    int n = heights.size();
    int l=0 , r=n-1;
    int leftMax = 0 , rightMax=0;
    int res = 0;
    while(l<r){
        if(heights[l] <= heights[r]){
            if(heights[l]>=leftMax) leftMax = heights[l];
            else res += (leftMax-heights[l]); 
            l++;
        }else{
            if(heights[r]>=rightMax) rightMax=heights[r];
            else res+= rightMax-heights[r];
            r--;
        }
    }
    return res;
}

int main(){
    int arr[12]={0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> heights;
    for(int i=0 ; i<12 ; i++)heights.push_back(arr[i]);
    cout<<findArea(heights);
    return 0;
}
