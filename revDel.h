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
		for (auto j = edges.begin(); j < edges.end();){
			if ((*curEdge).getNode1() == (*j).getNode2() && (*curEdge).getNode2() == (*j).getNode1()){
				temp.push_back(*j);
				j = edges.erase(j);
			}
			else j++;
		}
		curEdge = edges.erase(curEdge);
		
		AMGraph<T> testGraph = AMGraph<T>(vertices, edges);
		if(!testGraph.isConnected()) {
			edges.insert(edges.begin(), temp.begin(), temp.end());//does this work?
			temp.clear();
		}
	}
/*	for (auto i = edges.begin(); i != edges.end();){
		int erased = 0;
		Node<T> vertex1 = i.getNode1();
		Node<T> vertex2 = i.getNode2();
		
		//Remove vertices from adjacency matrix
		for (int j = 0; j <  graph->adjLists[vertex1.getID()].size();){
			if (graph->adjLists[vertex1.getID()][j].getID() == vertex2.getID()) j = graph->adjLists[vertex1.getID()].erase(j);
			else j++;
		}
		for (int j = 0; j <  graph->adjLists[vertex2.getID()].size();){
			if (graph->adjLists[vertex2.getID()][j].getID() == vertex1.getID()) j = graph->adjLists[vertex2.getID()].erase(j);
			else j++;
		}
		temp.push_back(edges[i]);
		for (auto j = edges.begin(); j < edges.end();){
			if (i.getNode1() == j.getNode2() && i.getNode2() == j.getNode1()){
				temp.push_back(j);
				j = edges.erase(j);
			}
			else j++;
		}
		i = edges.erase(i);
		
		if (!graph.isConnected()){
			//add each vertex to the other's in adjacency matrix
			graph->adjLists[i.getNode1().getID()].push_back(i.getNode2());
			graph->adjLists[i.getNode2().getID()].push_back(i.getNode1());
			edges.insert(edges.begin(), temp, temp+temp.size());//does this work?
			temp.clear();
		}
		
		//increments if not shifted
		i+=(erased==0)?1:0;
	}*/
//	for (auto i = discard.begin(); i < discard.end(); i++){
	//	for (auto j = edges.begin(); j < edges.end();){
		//	if (i.getNode1() == j.getNode1() && i.getNode2() == j.getNode2()) j = edges.erase(j);
			//else j++;
	//	}
	//}
	for (Edge<T> edge : edges) std::cout << " " << edge.getNode1().getID() << " " << edge.getNode2().getID() << " " << edge.getWeight() << std::endl;
	
}

#endif
