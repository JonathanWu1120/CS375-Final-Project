#ifndef AMGRAPH_H
#define AMGRAPH_H

#include <vector>
#include "Node.h"
#include "Edge.h"
#include <sstream>
#include <string>
#include <iostream>

template <class T>
class AMGraph {
	private:
		std::vector<std::vector<int>> adjMatrix;
		std::vector<Node<T>> vertexes;
		std::vector<Edge<T>> edges;
		//int directed=0;
	public:
		AMGraph();
		AMGraph(std::vector<Node<T>> &V, std::vector<Edge<T>> &E);
		std::string listAdjacents(Node<T>);
		std::string listGraph();
		std::vector<Edge<T>> getEdges();
		std::vector<Node<T>> getAdjacents(Node<T>);
		std::vector<Node<T>> getVertexes();
		/* DEPRECATED
		AMGraph(vector<Node<T>> V, vector<Edge<T>> E), int directed);
		*/
};

template <class T>
AMGraph<T>::AMGraph() {
	this->adjMatrix = std::vector<std::vector<Node<T>>>();
	this->vertexes = std::vector<Node<T>>();
}

/* Construct Graph in O(|V|*|E|) time */
template <class T>
AMGraph<T>::AMGraph(std::vector<Node<T>> &V, std::vector<Edge<T>> &E) {
	this->adjMatrix = std::vector<std::vector<int>>(V.size(), std::vector<int>(V.size(), -1));
	this->vertexes = std::vector<Node<T>>(V.size());
	this->edges = std::vector<Edge<T>>();
	// Set local IDs of all involved nodes
	for(unsigned int i=0; i < V.size(); i++) {
		V[i].setID(i);
		for(auto &j : E) {
			
			if(j.getNode1() == V[i]) {
				j.getNode1().setID(i);
			}
			if(j.getNode2() == V[i]) {
				j.getNode2().setID(i);
			}
		}
		vertexes[i] = V[i];
	}
	
	// Insert all adjacencies based on edges
	for(auto &i : E) {
		this->edges.push_back(i);
		this->adjMatrix[i.getNode1().getID()][i.getNode2().getID()] = i.getWeight();
	}
		
}

template <class T>
std::string AMGraph<T>::listAdjacents(Node<T> node) {
	int id=-1;
	for(auto i : vertexes) {
		if(node == i) {
			id=i.getID();
			break;
		}
	}
	
	std::string retVal;
	std::stringstream strStream;
	strStream << "Nodes adjacent to " << id << ": " << vertexes[id].getData() << "\n";
	std::stringstream strStream2;
	for(unsigned int i=0; i < adjMatrix[id].size(); i++) {
		if(adjMatrix[id][i] != -1)
			strStream2 << "\tNode " << i << ": " << vertexes[i].getData() << "\n\t\tEdge weight: " << adjMatrix[id][i] << "\n";
	}
	
	retVal = strStream.str();
	std::string retVal2 = strStream2.str();
	if(retVal2.empty()) 
		retVal.append("\tNo adjacent nodes\n");
	else
		retVal.append(retVal2);
	return retVal;
}

template <class T>
std::string AMGraph<T>::listGraph() {
	std::string retVal;
	std::stringstream list;
	list << "Listing entire graph\n--------------------------\n";
	for(auto i : vertexes) {
		list << listAdjacents(i);
	}
	retVal = list.str();
	return retVal;
}

template <class T>
std::vector<Node<T>> AMGraph<T>::getVertexes() {
	return std::vector<Node<T>>(vertexes);
}

template <class T>
std::vector<Edge<T>> AMGraph<T>::getEdges() {
	return std::vector<Edge<T>>(edges);
}

template <class T>
std::vector<Node<T>> AMGraph<T>::getAdjacents(Node<T> node) {
	std::vector<Node<T>> returnVal = std::vector<Node<T>>();
	for(auto i : this->adjMatrix[node.getID()]) {
		if(*i != -1)
			returnVal.push_back(vertexes[*i]);
	}
	return returnVal;
}


/* DEPRECATED
template <class T>
ALGraph<T>::ALGraph(vector<Node<T>> V, vector<Edge<T>> E, int directed) {
	this->directed = directed;
	this->adjMatrix = vector<vector<Node<T>>>(V.size(), vector<Node<T>>(V.size(), -1));
	// Set local IDs of all involved nodes
	for(unsigned int i=0; i < V.size(); i++) {
		V[i].setID(i);
		for(auto j : E) {
			if(j.getNode1() == V[i])
				j.getNode1().setID(i);
			if(j.getNode2() == V[i])
				j.getNode2().setID(i);
		}
	}
	
	// Insert all adjacencies based on edges
	for(auto i : E) {
		this->adjMatrix[i.getNode1()][i.getNode(2)] = i.getWeight();
	}
		
};
*/

#endif
