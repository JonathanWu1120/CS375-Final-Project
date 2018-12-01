#ifndef REVDEL_H
#define REVDEL_H
#include "ALGraph.h"
#include "AMGraph.h"
#include "Edge.h"
#include "Node.h"
#include <string>
#include <stdio.h>
#include <algorithm>

template <class T>
int compare(Edge<T>* a, Edge<T>* b){
	return a->getWeight() > b.getWeight();
}

template <class T>
void revDelMST(AMGraph<T>* graph){
	std::vector<Node<T>> vertices = graph->getVertexes();
	std::vector<Edge<T>> edges = graph->getEdges();
	std::vector<Edge<T>> temp;
	std::sort(edges.begin(),edges.end());
	std::reverse(edges.begin(),edges.end());
	std::cout << "initial: ";////////////////////////////////////////////////////////////////////////////////
	for (Edge<T> edge : edges) std::cout << edge.getNode1().getID() << "," << edge.getNode2().getID() << " ";////////////////
	std::cout << std::endl;///////////////////////////////////////////////////////////////////////////////////////
	for (auto curEdge = edges.begin(); curEdge != edges.end();){
		temp.push_back(*curEdge);
	std::cout << "temp: ";////////////////////////////////////////////////////////////////////////////////
	for (Edge<T> edge : temp) std::cout << edge.getNode1().getID() << "," << edge.getNode2().getID() << " ";////////////////
	std::cout << std::endl;///////////////////////////////////////////////////////////////////////////////////////
		for (auto j = edges.begin(); j < edges.end();){
			if ((*curEdge).getNode1() == (*j).getNode2() && (*curEdge).getNode2() == (*j).getNode1()){
				temp.push_back(*j);
				j = edges.erase(j);
				break;
			}
			else j++;
		}
	std::cout << "edges: ";////////////////////////////////////////////////////////////////////////////////
	for (Edge<T> edge : edges) std::cout << edge.getNode1().getID() << "," << edge.getNode2().getID() << " ";////////////////
	std::cout << std::endl;///////////////////////////////////////////////////////////////////////////////////////
	std::cout << "temp: ";////////////////////////////////////////////////////////////////////////////////
	for (Edge<T> edge : temp) std::cout << edge.getNode1().getID() << "," << edge.getNode2().getID() << " ";////////////////
	std::cout << std::endl;///////////////////////////////////////////////////////////////////////////////////////
		curEdge = edges.erase(curEdge);
		
		AMGraph<T> testGraph = AMGraph<T>(vertices, edges);
		std::cout << "Made it to just before \"if isConnected\"" << std::endl;///////////////////////////////////////////////////
		if(!testGraph.isConnected()) {
		std::cout << "Made it to just after \"if isConnected\"" << std::endl;///////////////////////////////////////////////////
			edges.insert(edges.begin(), temp.begin(), temp.end());
			temp.clear();
		}
	}
	//Print output
	for (Edge<T> edge : edges) std::cout << " " << edge.getNode1().getID() << " " << edge.getNode2().getID() << " " << edge.getWeight() << std::endl;	
}

#endif
