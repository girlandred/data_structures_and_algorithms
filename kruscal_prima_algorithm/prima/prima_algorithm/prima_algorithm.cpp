#include<iostream>

using namespace std;

// кількість вершин в графа
const int V = 6;

/* функція, що знаходить вершину з найменшим значенням */ 
int min_e(int key[], bool visited[])
{
    int min = 999, min_index;

    for (int v = 0; v < V; v++) {
        if (visited[v] == false && key[v] < min) {
            // вершина не відвідується
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

/* функція, що відповідає за виведення фінального графа */
int print_MST(int parent[], int cost[V][V])
{
    int minCost = 0;
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << cost[i][parent[i]] << " \n";
        minCost += cost[i][parent[i]];
    }
    cout << "Total cost is" << minCost;
}

/* функція, що будує мінімальний каркас */
void sel_e(int cost[V][V])
{
    int parent[V], key[V];
    bool visited[V];

    // наповнення масива 
    for (int i = 0; i < V; i++) {
        key[i] = 999;
        visited[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;  // встановлює значення вершини, як 0
    parent[0] = -1; // First node is always root of MST  

    for (int x = 0; x < V - 1; x++)
    {
        // мінімальний ключ
        int u = min_e(key, visited);

        visited[u] = true;  // додавання елемента до мінімального каркасу 

        // оновлення масивів
        for (int v = 0; v < V; v++)
        {
            if (cost[u][v] != 0 && visited[v] == false && cost[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = cost[u][v];
            }
        }
    }

    // виведення фінального каркасу
    print_MST(parent, cost);
}

int main()
{
    int cost[V][V];
    cout << "Enter the vertices for a graph: ";
    for (int i = 0;i < V;i++)
    {
        for (int j = 0;j < V;j++)
        {
            cin >> cost[i][j];
        }
    }
    sel_e(cost);

    return 0;
}