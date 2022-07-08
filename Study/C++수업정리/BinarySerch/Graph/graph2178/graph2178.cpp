// **********************  BFS  ****************************
#include <iostream>
#include <queue>

using namespace std;

int X, Y; // 높이, 폭 입력받을 변수                     
int map[101][101]; // 미로 맵            
bool isVisited[101][101]; // 방문여부 확인 할 booltype 배열         
int Generation[101][101]; // 정점과 인접한 정점을 만났을때, 인접한 정점을 모두 +1씩 카운트 하기위한 배열,             
// pair형식의 큐 선언
queue<pair<int, int> > q;

// 미로 경로 탐색
void bfs() 
{
    // 서쪽, 북쪽, 동쪽, 남쪽 체크할 룩업테이블 생성
    static int dx[4] = { 1, 0, -1, 0 }; 
    static int dy[4] = { 0,-1, 0, 1 };

    int x = 0; int y = 0; // 과거 좌표, 초기값은 0, 0

    isVisited[y][x] = true; // (0,0) 방문했으니 true;

    q.push(make_pair(y, x)); // 0,0 일단 페어큐에 저장한다.

    Generation[y][x] = 1; // root는 1부터 시작한다 (점점 카운트 시키는거임) // 개울가에 돌맹이를 처음 떨어트린다.(BFS 너비우선 탐색방식이므로 넓게 퍼지면서 탐색한다)              


    // 큐 안에있는 내용물이 비어있을 때 까지 반복한다.
    while (!q.empty()) 
    {
        // 대기열에있는 좌표들을 front를 통해 참조해서 변수에 담는다, 초기좌표의 q.front = (0,0)
        int y = q.front().first;
        int x = q.front().second;

        q.pop(); // 참조가 끝났으면 pop을 통해 큐의 첫번째 항목을 제거한다.

        for (int i = 0; i < 4; ++i) 
        {
            int newX = x + dx[i]; 
            int newY = y + dy[i]; 

            // 새롭게 이동할 좌표가 범위를 벗어났을경우
            if (0 > newX || newX >= X || 0 > newY || newY >= Y)
            {
                continue; // 이번 인덱스를 건너뛰고 다음인덱스로 이동
            }

            // 이미 방문을 완료했거나, 맵에 1이 찍혀있는경우
            if (!isVisited[newY][newX] && map[newY][newX] == 1) 
            {
                isVisited[newY][newX] = true; // 방문을 완료한다.          
                q.push(make_pair(newY, newX));// 큐에 대기열에 추가한다.
                Generation[newY][newX] = Generation[y][x] + 1; // 인접한 정점 모두 +1 씩 카운트한다.
            }
        }
    }
    cout << Generation[Y - 1][X - 1]; // 결과물을 출력한다.
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 1. 입력
    cin >> Y >> X;                            

    // 2. 처리
    for (int i = 0; i < Y; ++i) 
    {                                          
        string row;                           
        cin >> row;

        for (int j = 0; j < X; ++j) 
        {                                       
            map[i][j] = row[j] - '0';         
        }
    }

    // 3. 처리 & 출력
    bfs();                                  
}