#include "Node.h"
#include "Edge.h"
#include "ALGraph.h"
#include "AMGraph.h"
#include <vector>
#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

int main() {
	// TEST: Node creation
	cout << "---TEST: Creating 10 nodes---" << endl;
		vector<Node<int>> nodes = vector<Node<int>>();
		for(int i=0; i<10; i++) {
			Node<int> node = Node<int>(i);
			nodes.push_back(node);
			cout << "Node " << node.getID() << " created" << endl;
		}
	cout << "---TEST PASSED---" << endl;
		
	// TEST: Node equivalency
		
	// TEST: Edge creation
	cout << "---TEST: Creating edges---" << endl;
		vector<Edge<int>> edges = vector<Edge<int>>();
		for(int i=0; i<5; i++) {
			Edge<int> edge = Edge<int>(nodes[i], nodes[i+5]);
			edges.push_back(edge);
			cout << "Edge from node " << edge.getNode1().getID() << " to node " << edge.getNode2().getID() << " created" << endl;
		}
	cout << "---TEST PASSED---" << endl;

	// TEST: Graph creation
		// ALGraph
	cout << "---TEST: Creating adjacency list graph---" << endl;
		ALGraph<int> listGraph = ALGraph<int>(nodes, edges);
	cout << "---TEST PASSED---" << endl;
		// AMGraph
	cout << "---TEST: Creating adjacency matrix graph---" << endl;
		AMGraph<int> matGraph = AMGraph<int>(nodes, edges);
	cout << "---TEST PASSED---" << endl;
		
	// TEST: listAdjacents
		// ALGraph
	cout << "---TEST: ALGraph listAdjacents---" << endl;
		string str = listGraph.listAdjacents(nodes[0]);
		cout << str << endl;
		assert(str.compare(
			"Nodes adjacent to 0: 0\n\tNode 5: 5\n\t\tEdge weight: 0\n") == 0);
	cout << "---TEST PASSED---" << endl;
		// AMGraph
	cout << "---TEST: AMGraph listAdjacents---" << endl;
		string str2 = matGraph.listAdjacents(nodes[0]);
		cout << str2 << endl;
		assert(str2.compare(
			"Nodes adjacent to 0: 0\n\tNode 5: 5\n\t\tEdge weight: 0\n") == 0);
	cout << "---TEST PASSED---" << endl;
	// TEST: listGraph
		// ALGraph
	cout << "---TEST: ALGraph listGraph---" << endl;
		cout << listGraph.listGraph();
	cout << "---------------------" << endl;
		// AMGraph
	cout << "---TEST: AMGraph listGraph---" << endl;
		cout << matGraph.listGraph();
	cout << "---------------------" << endl;
}
