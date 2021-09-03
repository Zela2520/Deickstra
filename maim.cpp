/*#include <iostream>
#include <vector>
#include <queue>
#define pb push_back

std::vector<bool> v;
std::vector<std::vector<int>> g;
void edge(int a, int b) {
    g[a].pb(b);
    // для неориентированного графа добавляем эту строку
    // g[b].pb(a);
}
void bfs(int u) {
    std::queue<int> q;
    q.push(u);
    v[u] = true;
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        // Ставим в очередь все соседние F и помечаем их как посещённые
        for (auto i = g[f].begin(); i != g[f].end(); i++) {
            if (!v[*i]) {
                q.push(*i);
                v[*i] = true;
            }
        }
    }
}


int main() {
    std::

	return 0;
}*/

/*#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
#include <utility>
const int Inf = 30000;


int main() { 
    setlocale(LC_ALL, "ru");
    int n, s, f;
    std::cout << "Введите количество вершин: ";
    std::cin >> n;
    std::cout << "\nВведите начальную вершину: ";
    std::cin >> s;  
    std::cout << "\nВедите конечную вершину: ";
    std::cin >> f;
    s--;
    f--;
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    // заполняем матрицу смежности
    for (int i = 0; i < n; ++i) { 
        for (int j = 0; j < n; ++j) {
            std::cin >> a[i][j];
        }
    }
    //создаём массив, в котором будут храгиться все кратчайшие расстояния до заданных вершин
    std::vector<int> d(n, Inf);
    d[s] = 0;
    // реализуем очередь где будут храниться наши пары чисел(первый элемент длина, второй сама вершина)
    std::priority_queue<std::pair <int, int>> q;
    q.push(std::make_pair(0, s));
    while (!q.empty()) {
        int len = -q.top().first;//вес вершины(таким образом минимальная длина окажется на первом месте на выход в очереди, поскольку очередь сортируется по убыванию)
        int v = q.top().second;// ключ вершины
        q.pop();//удаляем элемент из очереди
        if (len > d[v]) continue; // если вес очередной вершины больше предыдущего значения в массиве, то начиаем заново
        // иначе перебираем все вершины
        for (int i = 0; i < n; ++i) {
            int to = i;
            int length = a[v][i];
            if (d[to] > d[v] + length && length >= 0) {
                d[to] = d[v] + length;
                q.push(std::make_pair(-d[to], to));
            }
        }
    }
    if (d[f] == Inf) std::cout << "False";
    else std::cout << d[f];

    return 0;
}*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

const int inf = 4000;

int main() {
    int n, s, f;
    std::cin >> n >> s >> f;
    s--;
    f--;
    
    std::vector<std::vector<int>>matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<int> result(n, inf);
    result[s] = 0;

    std::priority_queue<std::pair<int, int>> q;
    q.push(std::make_pair(0, s));
    while (!q.empty()) {
        int len = -q.top().first;
        int v = q.top().second;
        q.pop();
        if (len > result[v]) continue;
        for (int i = 0; i < n; ++i) {
            int distancetoV = matrix[v][i];
            if (result[i] > result[v] + distancetoV) {
                result[i] = result[v] + distancetoV;
                q.push(std::make_pair(-result[i], i));
            }//result[v] в данной строчке это уже пройденная дистанция из стартовой вершины и её мы сравниваем с предыдущим кратчайшим расстоянием result[i]
        }
    }
    if (result[f] == inf) std::cout << "False";
    else std::cout << result[f];

    return 0;
}
