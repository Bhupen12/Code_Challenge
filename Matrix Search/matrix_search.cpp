// brute force approach -- Time complexity O(nm)

// for i in [0....N]
//     for j in [0...M]
//         if matrix[i][j] == target
//             return true

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1 , n2 ;
    cin >> n1 >> n2;
    int target ;
    cin>>target;

    int arr[n1][n2];

    for(int i=0 ; i<n1 ; i++){
        for(int j=0 ; j<n2 ; j++){
            cin >> arr[i][j];
        }
    }

    
    int r = 0 , c = n2-1;
    while(r<n1 && c>=0){
        if(arr[r][c] == target){
            cout<<"Elment found";
            return 0;
        }else if(target < arr[r][c]){
            c--;
        }else{
            r++;
        }
    }
    cout<<"element not found"<<" ";

    return 0 ;
}
