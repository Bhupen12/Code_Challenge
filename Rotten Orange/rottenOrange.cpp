#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int rottenOrange(vector<vector <int>>& grid){
    if(grid.empty()) return 0;
    int tot=0 , days=0 , count=0 , m=grid.size() , n=grid[0].size();
    queue<pair<int , int>> rotten;
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            if(grid[i][j] != 0) tot++;
            if(grid[i][j] == 2) rotten.push({i,j});
        }
    }
    
    int dx[4]={0 , 0 , 1,-1};
    int dy[4]={1,-1,0,0};
    while(!rotten.empty()){
        int k = rotten.size();
        count+=k;
        while(k--){
            int x = rotten.front().first , y = rotten.front().second;
            rotten.pop();
            for(int i=0 ; i<4 ; i++){
                int nx = x+dx[i] , ny = y+dy[i];
                if(nx<0 ||ny<0 || nx>=m || ny>=n || grid[nx][ny]!=1)continue;
                grid[nx][ny] = 2;
                rotten.push({nx,ny});
            }
        }
        if(!rotten.empty())days++;
    }
    return count==tot?days:-1;
}

int main(){
    int arr1[5]={2,1,0,0,1};
    int arr2[5]={1,1,0,0,1};
    int arr3[5]={0,1,0,1,2};
    vector<int> vt1 , vt2 , vt3;
    for(int i=0 ; i<5 ; i++) vt1.push_back(arr1[i]);
    for(int i=0 ; i<5 ; i++) vt2.push_back(arr2[i]);
    for(int i=0 ; i<5 ; i++) vt3.push_back(arr3[i]);
    vector<vector <int>> vt;
    vt.push_back(vt1);
    vt.push_back(vt2);
    vt.push_back(vt3);
    cout<<rottenOrange(vt);
    return 0;
}
