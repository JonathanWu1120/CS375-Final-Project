#ifndef EDGE_H
#define EDGE_H

#include "Node.h"

template <class T>
class Edge {
	private:
		Node<T> node1;
		Node<T> node2;
		int weight;
	public:
		Edge(){this->node1=Node<T>(); this->node2=Node<T>(); this->weight=0;};
		Edge(Node<T> A, Node<T> B){this->node1=A; this->node2=B; this->weight=0;};
		Edge(Node<T> A, Node<T> B, int weight){this->node1=A; this->node2=B; this->weight=weight;};
		Node<T> & getNode1(){return node1;};
		Node<T> & getNode2(){return node2;};
		int getWeight(){return weight;};
		bool operator <(Edge<T> other){return this->weight < other.weight;};
		bool operator ==(Edge<T> other){return this->node1 == other.node1 && this->node2 == other.node2 && this->weight == other.weight;};
};

#endif
