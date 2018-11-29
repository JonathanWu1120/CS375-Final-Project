#include "Node.h"
#include "Edge.h"
#include "ALGraph.h"
#include "AMGraph.h"
#include <vector>
#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

int main(/*int argc, char** argv*/) {
	// TEST: Node creation
	cout << "TEST: Creating 10 nodes" << endl;
		vector<Node<int>> nodes = vector<Node<int>>();
		Node<int> node;
		for(int i=0; i<10; i++) {
			node = Node<int>(i);
			cout << "Node " << node.getID() << " created" << endl;
		}
	cout << "TEST PASSED" << endl;
		
	// TEST: Node equivalency
		
	// TEST: Edge creation
	cout << "TEST: Creating edges" << endl;
		vector<Edge<int>> edges = vector<Edge<int>>();
		for(int i=0; i<5; i++) {
			Edge<int> edge = Edge<int>(nodes[i], nodes[i+5]);
			cout << "Edge from node " << edge.getNode1().getID() << " to node " << edge.getNode2().getID() << " created" << endl;
		}
	cout << "TEST PASSED" << endl;

	// TEST: Graph creation
		// ALGraph
	cout << "TEST: Creating adjacency list graph" << endl;
		ALGraph<int> listGraph = ALGraph<int>(nodes, edges);
	cout << "TEST PASSED" << endl;
		// AMGraph
	cout << "TEST: Creating adjacency matric graph" << endl;
		AMGraph<int> matGraph = AMGraph<int>(nodes, edges);
	cout << "TEST PASSED" << endl;
		
	// TEST: listAdjacents
		// ALGraph
	cout << "TEST: ALGraph listAdjacents" << endl;
		string str = listGraph.listAdjacents(nodes[0]);
		assert(str.compare(
			"Nodes adjacent to 0: 0\n\tNode 5: 5\n\t\tEdge Weight: 0\n"));
	cout << str << endl;
		// AMGraph
	cout << "TEST: AMGraph listAdjacents" << endl;
		string str2 = matGraph.listAdjacents(nodes[0]);
		assert(str2.compare(
			"Nodes adjacent to 0: 0\n\tNode 5: 5\n\t\tEdge Weight: 0\n"));
	cout << str2 << endl;
		
	// TEST: listGraph
		// ALGraph
	cout << "TEST: ALGraph listGraph" << endl;
		cout << listGraph.listGraph() << endl;
	cout << "---------------------" << endl;
		// AMGraph
	cout << "TEST: AMGraph listGraph" << endl;
		cout << matGraph.listGraph() << endl;
	cout << "---------------------" << endl;
		
}
