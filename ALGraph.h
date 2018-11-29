#ifndef ALGRAPH_H
#define ALGRAPH_H

#include <vector>
#include "Node.h"
#include "Edge.h"
#include <sstream>
#include <string>

template <class T>
class ALGraph {
	private:
		std::vector<Node<T>> vertexes;
		std::vector<std::vector<Node<T>>> adjLists;
		std::vector<std::vector<int>> weights;
		std::vector<Edge<T>> edges;
		//int directed=0;
	public:
		ALGraph();
		ALGraph(std::vector<Node<T>> V, std::vector<Edge<T>> E);
		std::string listAdjacents(Node<T>);
		std::string listGraph();
		std::vector<Edge<T>> getEdges();
		/* DEPRECATED
		ALGraph(vector<Node<T>> V, vector<Edge<T>> E), int directed);
		*/
};

template <class T>
ALGraph<T>::ALGraph() {
	this->adjLists = std::vector<std::vector<Node<T>>>();
	this->weights = std::vector<std::vector<int>>();
	this->vertexes = std::vector<Node<T>>();
	this->edges = std::vector<Edge<T>>();
}

/* Construct Graph in O(|V|*|E|) time */
template <class T>
ALGraph<T>::ALGraph(std::vector<Node<T>> V, std::vector<Edge<T>> E) {
	this->adjLists = std::vector<std::vector<Node<T>>>(V.size(), std::vector<Node<T>>());
	this->weights = std::vector<std::vector<int>>(V.size(), std::vector<int>());
	this->vertexes = std::vector<Node<T>>(V.size());
	this->edges = std::vector<Edge<T>>();
	
	// Set local IDs of all involved nodes
	for(unsigned int i=0; i < V.size(); i++) {
		V[i].setID(i);
		for(auto j : E) {
			if(j.getNode1() == V[i])
				j.getNode1().setID(i);
			if(j.getNode2() == V[i])
				j.getNode2().setID(i);
		}
		vertexes[i] = V[i];
	}
	
	// Insert all adjacencies based on edges
	for(auto i : E) {
		this->edges.push_back(i);
		this->adjLists[i.getNode1().getID()].push_back(i.getNode2());
		this->weights[i.getNode1().getID()].push_back(i.getWeight());
	}		
}

template <class T>
std::string ALGraph<T>::listAdjacents(Node<T> node) {
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
	for(unsigned int i=0; i < adjLists[id].size(); i++) {
		strStream << "\tNode " << i << ": " << adjLists[id][i].getData() << "\n";
		strStream << "\t\tEdge weight: " << weights[id][i] << "\n";
	}
	
	retVal = strStream.str();
	return retVal;
}

template <class T>
std::string ALGraph<T>::listGraph() {
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
std::vector<Edge<T>> ALGraph<T>::getEdges() {
	return std::vector<Edge<T>>(edges);
}

/* DEPRECATED
template <class T>
ALGraph<T>::ALGraph(vector<Node<T>> V, vector<Edge<T>> E, int directed) {
	this->directed = directed;
	this->adjLists = vector<vector<Node<T>>>(V.size());
	this->weights = vector<vector<int>>(V.size());
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
		adjLists[i.getNode1()].push_back(i.getNode(2));
		weights[i.getNode1()].push_back(i.getWeight());
	}
	
};
*/

#endif
