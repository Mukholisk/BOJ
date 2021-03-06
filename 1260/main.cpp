#include <iostream>
#include <queue>
using namespace std;

void DFS(int** g, int n, int v);
void BFS(int** g, int n, int v);
int search_dfs[1000];
int search_bfs[1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // �������� 1������ N�������̳�, �ڵ�� 0������ N-1��������.
    int N, M, V;
    cin >> N >> M >> V;
    V -= 1; // ��ȯ

    // �����Ҵ�
    int** graph = new int* [N];
    for (int i = 0; i < N; i++)
        graph[i] = new int[N];
    
    // �ʱ�ȭ
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            graph[i][j] = 0;

    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;

        // �����
        graph[s-1][e-1] = 1;
        graph[e-1][s-1] = 1;
    }

    DFS(graph, N, V);
    cout << '\n';
    BFS(graph, N, V);
    cout << '\n';

    return 0;
}

// ����ó�� ����
void DFS(int** g, int n, int v) {
    search_dfs[v] = 1;
    cout << v+1 << " ";
    for (int i = 0; i < n; i++) {
        int next = g[v][i];
        if (next == 1)
            if (search_dfs[i] == 0)
                DFS(g, n, i);
    }
}

// ť ���
void BFS(int** g, int n, int v) {
    queue<int> q;
    q.push(v);
    search_bfs[v] = 1;

    while(!q.empty()){
        int current = q.front();
        q.pop();
        cout << current+1 << " ";

        for (int i = 0; i < n; i++) {
            int next = g[current][i];
            if (next == 1)
                if (search_bfs[i] == 0){
                    search_bfs[i] = 1;
                    q.push(i);
                }
        }
    }
}
