#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <utility>

using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const char dir[] = {'L', 'R', 'U', 'D'};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> labyrinth(n);
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m));

    pair<int, int> start, end;

    for (int i = 0; i < n; ++i)
    {
        cin >> labyrinth[i];
        for (int j = 0; j < m; ++j)
        {
            if (labyrinth[i][j] == 'A')
                start = {i, j};
            else if (labyrinth[i][j] == 'B')
                end = {i, j};
        }
    }

    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        if (cur == end)
            break;

        for (int k = 0; k < 4; ++k)
        {
            int nx = cur.first + dx[k];
            int ny = cur.second + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (labyrinth[nx][ny] == '#' || visited[nx][ny])
                continue;

            visited[nx][ny] = true;
            parent[nx][ny] = cur;
            q.push({nx, ny});
        }
    }

    if (!visited[end.first][end.second])
    {
        cout << "NO";
    }
    else
    {
        cout << "YES" << endl;

        vector<char> path;
        pair<int, int> cur = end;

        while (cur != start)
        {
            pair<int, int> prev = parent[cur.first][cur.second];
            for (int k = 0; k < 4; ++k)
            {
                int nx = prev.first + dx[k];
                int ny = prev.second + dy[k];

                if (nx == cur.first && ny == cur.second)
                {
                    path.push_back(dir[k]);
                    break;
                }
            }
            cur = prev;
        }

        cout << path.size() << endl;
        for (int i = path.size() - 1; i >= 0; --i)
            cout << path[i];
    }

    return 0;
}
Share code to others