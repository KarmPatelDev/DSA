#include <iostream>
#include <vector>
using namespace std;

#define N 4

bool isPossible(vector<vector<int>> & m, vector<vector<int>> visited, int newX, int newY){

    if((newX >= 0 && newX < N) && (newY >= 0 && newY < N) && (m[newX][newY] == 1) && (m[newX][newY] == 1)){
        return true;
    }
    else{
        return false;
    }

}

void ratInMaze(vector<vector<int>> & m, vector<vector<int>> visited, vector<string> & ans, int pointX, int pointY, string path){
     
     if(pointX == N - 1 && pointY == N - 1){
        ans.push_back(path);
        return ;
     }

     visited[pointX][pointY] = 1;

     //Down
     int newX = pointX + 1;
     int newY = pointY;
     if(isPossible(m, visited, newX, newY)){
        path.push_back('D');
        ratInMaze(m, visited, ans, newX, newY, path);
        path.pop_back();
     }

     //Right
     newX = pointX;
     newY = pointY + 1;
     if(isPossible(m, visited, newX, newY)){
        path.push_back('R');
        ratInMaze(m, visited, ans, newX, newY, path);
        path.pop_back();
     }

     //Up
     newX = pointX - 1;
     newY = pointY;
     if(isPossible(m, visited, newX, newY)){
        path.push_back('U');
        ratInMaze(m, visited, ans, newX, newY, path);
        path.pop_back();
     }

     //L
     newX = pointX;
     newY = pointY - 1;
     if(isPossible(m, visited, newX, newY)){
        path.push_back('L');
        ratInMaze(m, visited, ans, newX, newY, path);
        path.pop_back();
     }

     visited[pointX][pointY] = 0;

}

int main(){
    
    vector<vector<int>> m;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> m[i][j];
        }
    }
    
    if(m[0][0] == 0){return 0;}

    vector<vector<int>> visited = m;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            visited[i][j] = 0;
        }
    }

    int pointX= 0;
    int pointY = 0;
    string path = "";
    vector<string> ans;

    ratInMaze(m, visited, ans, pointX, pointY, path);

    string i;
    for(auto i : ans){
        cout << i << " ";
    }


    return 0;
}  