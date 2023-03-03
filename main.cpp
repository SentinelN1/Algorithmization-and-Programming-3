#include "Graph.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    Matrix<double> matrix = {{0, 1, 0, 1},
                             {0, 0, 1, 0},
                             {1, 0, 0, 1},
                             {0, 0, 0, 0}};

    Graph<string, double> graph;
    cout << graph.Nodes() << endl;
    cout << graph.Edges() << endl;

    return 0;
}
