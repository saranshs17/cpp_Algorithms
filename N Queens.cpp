#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
int n;
bool isSafe(vector<vector<int>> &board,int row,int col){
    for(int i=0;i<col;++i){
        if(board[row][i]==1)return false;
    }
    for(int i=row,j=col;i>=0 && j>=0;--i,--j){
        if(board[i][j]==1)return false;
    }
    for(int i=row,j=col;j>=0 && i<n;++i,--j){
        if(board[i][j]==1)return false;
    }
    return true;
}
bool solve(vector<vector<int>> &board,int col){
    if(col>=n)return true;
    for(int i=0;i<n;++i){
        if(isSafe(board,i,col)){
            board[i][col]=1;
            if(solve(board,col+1)){
                return true;
            }
            board[i][col]=0;
        }
    }
    return false;
}
int main()
{
    cin>>n;
    vector<vector<int>> board(n,vector<int> (n,0));
    if(solve(board,0)==false){
        cout<<"Not Possible\n";
        return 0;
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(board[i][j]==1){
                cout<<"Q ";
            }else{
                cout<<". ";
            }
        }
        cout<<'\n';
    }
}
