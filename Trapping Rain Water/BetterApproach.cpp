#include<iostream>
#include<vector>
using namespace std;

int findArea(vector<int> hights){
  
    int n = hights.size();
    int prefix[n],sufix[n];
    prefix[0]=hights[0] , sufix[n-1]=hights[n-1];

    for (int i = 1; i < n; i++)  prefix[i] = max(prefix[i-1] , hights[i]);
    for (int i = n-2; i >0; i--) sufix[i] = max(sufix[i+1] , hights[i]);

    int res=0;
    for(int i=0 ; i<n ; i++){
        if(min(prefix[i] , sufix[i])>hights[i]) 
          res += min(prefix[i],sufix[i]) - hights[i];
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
