#include "Node.h"
#include "Edge.h"
#include "ALGraph.h"
#include "AMGraph.h"
#include "Kurskal.h"
#include <vector>
#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

vector<Edge<int>> getUndirectedEdges(Node<int> a, Node<int> b, int weight) {
	vector<Edge<int>> pair = vector<Edge<int>>();
	pair.push_back(Edge<int>(a, b, weight));
	pair.push_back(Edge<int>(b, a, weight));
	return pair;
}

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
	
	
	// TEST: Kruskal's Algorithm
		// AMGraph
	cout << "---TEST: Kruskal's algorithm---" << endl;
		// Generate nodes
		vector<Node<int>> nodes2 = vector<Node<int>>();
		for(int i=0; i < 10; i++) {
			Node<int> n = Node<int>(i);
			nodes2.push_back(n);
		}
		// Generate edges
		vector<Edge<int>> e2 = vector<Edge<int>>();
		vector<Edge<int>> pair = vector<Edge<int>>();
		pair = getUndirectedEdges(nodes2[0], nodes2[1], 4);
		e2.push_back(pair[0]);
		e2.push_back(pair[1]);
		pair = getUndirectedEdges(nodes2[0], nodes2[2], 3);
		e2.push_back(pair[0]);
		e2.push_back(pair[1]);
		pair = getUndirectedEdges(nodes2[0], nodes2[8], 5);
		e2.push_back(pair[0]);
		e2.push_back(pair[1]);
		pair = getUndirectedEdges(nodes2[0], nodes2[3], 1);
		e2.push_back(pair[0]);
		e2.push_back(pair[1]);
		pair = getUndirectedEdges(nodes2[1], nodes2[3], 3);
		e2.push_back(pair[0]);
		e2.push_back(pair[1]);
		pair = getUndirectedEdges(nodes2[2], nodes2[7], 100);
		e2.push_back(pair[0]);
		e2.push_back(pair[1]);
		pair = getUndirectedEdges(nodes2[2], nodes2[3], 2);
		e2.push_back(pair[0]);
		e2.push_back(pair[1]);
		pair = getUndirectedEdges(nodes2[3], nodes2[4], 23);
		e2.push_back(pair[0]);
		e2.push_back(pair[1]);
		pair = getUndirectedEdges(nodes2[3], nodes2[9], 9);
		e2.push_back(pair[0]);
		e2.push_back(pair[1]);
		pair = getUndirectedEdges(nodes2[4], nodes2[9], 8);
		e2.push_back(pair[0]);
		e2.push_back(pair[1]);
		pair = getUndirectedEdges(nodes2[4], nodes2[6], 300);
		e2.push_back(pair[0]);
		e2.push_back(pair[1]);
		pair = getUndirectedEdges(nodes2[5], nodes2[9], 10);
		e2.push_back(pair[0]);
		e2.push_back(pair[1]);
		pair = getUndirectedEdges(nodes2[6], nodes2[7], 33);
		e2.push_back(pair[0]);
		e2.push_back(pair[1]);
		pair = getUndirectedEdges(nodes2[7], nodes2[8], 47);
		e2.push_back(pair[0]);
		e2.push_back(pair[1]);
		AMGraph<int> matGraph2 = AMGraph<int>(nodes2, e2);
		cout << matGraph2.listGraph() << endl;
		KruskalMST<int>(&matGraph2);
		// ALGraph
	
}
