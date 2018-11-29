#ifndef EDGE_H
#define EDGE_H

#include "Node.h"

template <class T>
class Edge {
	private:
		Node<T> * node1;
		Node<T> * node2;
		int weight;
	public:
		Edge(){this->node1=Node<T>(); this->node2=Node<T>(); this->weight=-1};
		Edge(Node<T> A, Node<T> B){this->node1=A; this->node2=B; this->weight=-1};
		Edge(Node<T> A, Node<T> B, int weight){this->node1=A; this->node2=B; this->weight=weight;};
		T getNode1(){return node1;};
		T getNode2(){return node2;};
		int getWeight(){return weight;};
};

#endif
