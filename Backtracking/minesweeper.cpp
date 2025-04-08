#include <bits/stdc++.h>
using namespace std;

struct Robot{
    string nombre = "R";
    int posx;
    int posy;
};

void printMap(vector<vector<char>> &map){
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            cout<<"["<<map[i][j]<<"]";
        }
        cout<<endl;
    }
}

void solve(vector<vector<char>> &map, Robot &robot){
    //if the robot finds the goal
    if(robot.posx == 3 and robot.posy == 3){
        printMap(map);
        return;
    }
    if(robot.posx > 3 or robot.posx < 0 or robot.posy > 3 or robot.posy < 0){
        return;
    }

    while(!(robot.posx > 3 or robot.posx < 0 or robot.posy > 3 or robot.posy < 0)){
        
        break;
    }


}

int main(){

    vector<vector<char>> map = {
        {' ', '*', ' ', ' '},
        {' ', ' ', '*', ' '},
        {'*', ' ', ' ', '*'},
        {' ', '*', ' ', ' '}
    };

    Robot robot;
    robot.posx = 0;
    robot.posy = 0;
    
    solve(map, robot);

    return 0;
}