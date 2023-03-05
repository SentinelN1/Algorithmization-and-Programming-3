#include "Graph.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    Matrix<double> matrix1 = {{0, 1, 0, 1},
                              {0, 0, 1, 0},
                              {1, 0, 0, 1},
                              {0, 0, 0, 0}};

//    Matrix<double> matrix2 = {{1, 1, 0, 0, 1, 0},
//                              {1, 0, 1, 0, 1, 0},
//                              {0, 1, 0, 1, 0, 0},
//                              {0, 0, 1, 0, 1, 1},
//                              {1, 1, 0, 1, 0, 0},
//                              {0, 0, 0, 1, 0, 0}};

//    Graph<string, double> g1(matrix1);
//    cout << g1.AdjacencyMatrix() << endl;
//
//    Graph<string, double> g2(matrix2);
//    cout << g2.AdjacencyMatrix() << endl;

    Node<string> n1("Node 1");

    Node<string> n2("Node 2");
    Node<string> n3("Node 3");

    Edge<string, double> e11(n1, n1, 0);
    Edge<string, double> e12(n1, n2, 1.2);
    Edge<string, double> e13(n1, n3, 1.3);

    Edge<string, double> e21(n2, n1, 2.1);
    Edge<string, double> e22(n2, n2, 2.2);
    Edge<string, double> e23(n2, n3, 2.3);

    Edge<string, double> e31(n3, n1, 3.1);
    Edge<string, double> e32(n3, n2, 3.2);
    Edge<string, double> e33(n3, n3, 3.3);

    map<Node<string>, list<Edge<string, double>>, NodeCompare<string>> mapping;

    mapping[n1] = {e11, e12, e13};
    mapping[n2] = {e21, e22, e23};
    mapping[n3] = {e31, e32, e33};
    mapping[n1] = {e13};

    for (auto p: mapping) {
        cout << p.first.GetData() << " ---> [ ";
        for (auto j: p.second) {
            cout << j.ToNode()->GetData() << " (" << j.GetWeight() << "), ";
        }
        cout << " ]\n";
    }

    return 0;
}
