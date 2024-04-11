#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include "LinkedListElem.h"

using namespace std;

struct Edge {
    string u, v;
    int weight;
};

bool compareEdge(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

void showComponent(LinkedListElem* e) {
    while (e != nullptr) {
        cout << e->id << ' ';
        e = e->next;
    }
    cout << endl;
}

int main() {
    string line, a, b;
    int weight;
    map<string, LinkedListElem*> elem;
    vector<Edge> edges;

    if (getline(cin, line)) {
        istringstream iss(line);
        while (iss >> a) {
            elem[a] = LinkedListElem::MakeSet(a);
        }
    }

    while (cin >> a >> b >> weight) {
        edges.push_back({a, b, weight});
    }

    sort(edges.begin(), edges.end(), compareEdge);

    int totalWeight = 0;
    cout << "Un MST al grafului este:";
    for (const auto& edge : edges) {
        if (LinkedListElem::FindSet(elem[edge.u]) != LinkedListElem::FindSet(elem[edge.v])) {
            LinkedListElem::Union(elem[edge.u], elem[edge.v]);
            cout << " (" << edge.u << " " << edge.v << ")";
            totalWeight += edge.weight;
        }
    }
    cout << " cu greutatea minimă " << totalWeight << "." << endl;

    return 0;
}
