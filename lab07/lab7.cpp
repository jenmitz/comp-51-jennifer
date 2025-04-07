#include <iostream>
#include <string>
using namespace std;


const int MAX = 10;
const int rows = 4;
const int cols = 4;


// Step 1: Define movement directions for Right, Down, Left, Up
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0 , -1, 0};
string dir[] = {"Right", "Down", "Left", "Up"};


// Step 2: Implement isSafe()
bool isSafe(int x, int y, char maze[MAX][MAX], bool visited[MAX][MAX]) {

    if (x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] != '#' && !visited[x][y]) {
        return true;
    } else {
        return false;
    }

}


// Step 3: Implement the recursive backtracking function
void findPaths(char maze[MAX][MAX], int x, int y, string pathSoFar, bool visited[MAX][MAX], int& pathCount) {

    if (maze[x][y] == 'E') {
        cout << "Path " << pathCount + 1 << ": " << pathSoFar << endl;
        pathCount++;
        return;
    }

    visited [x][y] = true;

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isSafe(newX, newY, maze, visited)) {
            string newPath;

            if (pathSoFar == "") {
                newPath = dir[i];
            } else {
                newPath = pathSoFar + ", " + dir[i];
            }

            findPaths(maze, newX, newY, newPath, visited, pathCount);

        }

    }

    visited[x][y] = false;

}


// Step 4: Implement the solveMaze() function
void solveMaze(char maze[MAX][MAX]) {

    int startX = -1;
    int startY = -1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == 'S') {
                startX = i;
                startY = j;
                break;
            }
        }
        if (startX != -1) {
            break;
        }
    }

    if (startX == -1 || startY == -1) {
        cout << "Start position not found." << endl;
        return;
    }

    bool visited[MAX][MAX];
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            visited[i][j] = false;
        }
    }

    int pathCount = 0;

    findPaths(maze, startX, startY, "", visited, pathCount);

    if (pathCount == 0) {
        cout << "No paths found from S to E." << endl;
    }

}


int main() {

    char maze[MAX][MAX] = {
        {'S', ' ', ' ', '#'},
        {'#', ' ', '#', ' '},
        {'#', ' ', ' ', ' '},
        {'#', '#', ' ', 'E'}
    };

    solveMaze(maze);

    return 0;
}