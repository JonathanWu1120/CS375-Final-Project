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
	for (auto curEdge = edges.begin(); curEdge != edges.end();){
		temp.push_back(*curEdge);
		for (auto j = edges.begin(); j < edges.end(); j++){
			if ((*curEdge).getNode1() == (*j).getNode2() && (*curEdge).getNode2() == (*j).getNode1()){
				temp.push_back(*j);
				j = edges.erase(j);
				break;
			}
		}
		curEdge = edges.erase(curEdge);
		AMGraph<T> testGraph = AMGraph<T>(vertices, edges);
		if(!testGraph.isConnected()) {
			edges.insert(edges.begin(), temp.begin(), temp.end());
			curEdge += 2;
		}
		temp.clear();
	}
	//Print output
	Edge<T> edge;
	for(unsigned int i=1; i < edges.size(); i+=2) {
		edge = edges[i];
		std::cout << edge.getNode1().getID() << " " << edge.getNode2().getID() << " " << edge.getWeight() << std::endl;
	}
}

template <class T>
void revDelMST(ALGraph<T>* graph){
	std::vector<Node<T>> vertices = graph->getVertexes();
	std::vector<Edge<T>> edges = graph->getEdges();
	std::vector<Edge<T>> temp;
	std::sort(edges.begin(),edges.end());
	std::reverse(edges.begin(),edges.end());
	for (auto curEdge = edges.begin(); curEdge != edges.end();){
		temp.push_back(*curEdge);
		for (auto j = edges.begin(); j < edges.end(); j++){
			if ((*curEdge).getNode1() == (*j).getNode2() && (*curEdge).getNode2() == (*j).getNode1()){
				temp.push_back(*j);
				j = edges.erase(j);
				break;
			}
		}
		curEdge = edges.erase(curEdge);
		ALGraph<T> testGraph = ALGraph<T>(vertices, edges);
		if(!testGraph.isConnected()) {
			edges.insert(edges.begin(), temp.begin(), temp.end());
			curEdge += 2;
		}
		temp.clear();
	}
	//Print output
	Edge<T> edge;
	for(unsigned int i=1; i < edges.size(); i+=2) {
		edge = edges[i];
		std::cout << edge.getNode1().getID() << " " << edge.getNode2().getID() << " " << edge.getWeight() << std::endl;
	}
}

#endif
