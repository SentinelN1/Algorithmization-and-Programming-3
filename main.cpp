#include "Graph.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    Matrix<double> matrix = {{0, 1, 0, 1},
                             {0, 0, 1, 0},
                             {1, 0, 0, 1},
                             {0, 0, 0, 0}};

    Graph<string, double> graph(matrix);

    cout << graph.Nodes() << endl;
    cout << graph.Edges() << endl;

    auto edges = graph.EdgesWeights();

    for (auto i : edges) {
        cout << i.Weight() << " ";
    }

    return 0;
}
