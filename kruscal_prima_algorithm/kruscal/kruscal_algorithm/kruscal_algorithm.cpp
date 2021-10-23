#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int previous[100];

/* функція, що рекурсивно шукає корінь дерева
починаючи від заданого елемента */
int set_find(int v) {

	//повертаємо значення елемента, яка він є коренем
	if (previous[v] == v) {
		return v;
	}
	// рекурсивне повернення виклику
	return set_find(previous[v]);
};

/* функція, що об'єднує вузли */
void set_unite(int v, int u) {
	int fv = set_find(v);
	int fu = set_find(u);
	previous[fv] = fu;
};

int main() {
	for (int i = 0; i < 100; i++)
	{
		previous[i] = i;
	}

	int v, e;
	int first, sec, weight;
	vector < pair < int, pair < int, int > > > edges;
	cout << "Enter quantity of verticles and edges: " << endl;
	cin >> v >> e;
	
	cout << "Elements: " << endl;
	// введення елементів графа
	for (int i = 0; i < e; i++)
	{
		cin >> first >> sec >> weight;
		edges.push_back(make_pair(weight, make_pair(first, sec)));//
	}

	cout << endl;
	cout << "After Kruskal algorithm: \n";
	int mst_weight = 0, mst_edges = 0, mst_n = 0;
	// сортування ребер за зростанням ваг
	sort(edges.begin(), edges.end());
	while ((mst_edges < v -2) || (mst_n < e))
	{
		first = edges[mst_n].second.first;
		sec = edges[mst_n].second.second;
		weight = edges[mst_n].first;
		// якщо перший і другий елемент є різними
		// то об'єднуємо їх
		if (set_find(first) != set_find(sec)) {
			set_unite(first, sec);
			mst_weight += weight;
			cout << first << " " << sec
				<< " -> " << weight << endl;
			mst_edges++;
		}
		// виведення всіх пар
		mst_n++;
	}
}