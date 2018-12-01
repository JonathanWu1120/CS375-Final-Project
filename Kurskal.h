#ifndef KURSKAL_H
#define KURSKAL_H
#include <vector>
#include "Node.h"
#include "Edge.h"
#include "AMGraph.h"
#include "ALGraph.h"
#include "Kurskal.h"
#include <string>
#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <iostream>

class union_find{
	public:
		union_find(int n){
			size = n;
			sets = new int[size];
			rank = new int[size];
			for(int i = 0; i < size; i++){
				sets[i] = i;
				rank[i] = 0;
			}
		}
		~union_find(){
			delete [] sets;
			delete [] rank;
		}
		int find(int target){
			assert(target >= 0 && target < this->size);
			std::vector<int> ancestors;
			while(target != sets[target]){
				ancestors.push_back(target);
				target = sets[target];
			}
			for(unsigned int i = 0; i < ancestors.size(); i++){
				sets[ancestors[i]] = target;
			}
			return target;
		}
		bool merge(int a, int b){
			assert(a >= 0 && a < this->size);
			assert(b >= 0 && b < this->size);
			int a1 = find(a);
			int b1 = find(b);
			if(a1 == b1){
				return false;
			}
			if(rank[a1] > rank[b1]){
				sets[b1] = a1;
			}else if(rank[a1] < rank[b1]){
				sets[a1] = b1;
			}else{
				sets[b1] = a1;
				rank[a1] += 1;
			}
			return true;
		}
	private:
		int size = 0;
		int* sets;
		int* rank;
};

template <class T>
int compare(Edge<T>* a, Edge<T>* b){
	return a->getWeight() > b->getWeight();
}

template <class T>
void KruskalMST(AMGraph<T>* graph){
	std::vector<Edge<T>> edges = graph->getEdges();
	std::vector<Node<T>> nodes = graph->getVertexes();
	std::sort(edges.begin(),edges.end());
	std::vector<Edge<T>> result;
	int e = 0;
	int i = 0;
	union_find subsets = union_find(nodes.size());
	while(e < (int)nodes.size()-1){
		Edge<T> next_edge = edges[i++];
		Node<T> n1 = next_edge.getNode1();
		Node<T> n2 = next_edge.getNode2();
		int i1,i2;
		int count = 0;
		for(Node<T> &n : nodes){
			if(n == n1){
				i1 = count;
			}
			if(n == n2){
				i2 = count;
			}
			count ++;
		}
		int x = subsets.find(i1);
		int y = subsets.find(i2);
		if(x != y){
			e++;
			result.push_back(next_edge);
			subsets.merge(x,y);
		}
	}
	for(Edge<T> ed : result){
		std::cout << ed.getNode1().getID() << " "  << ed.getNode2().getID() << " "  << ed.getWeight() << std::endl;
	}

}

template <class T>
void KruskalMST(ALGraph<T>* graph){
	std::vector<Edge<T>> edges = graph->getEdges();
	std::vector<Node<T>> nodes = graph->getVertexes();
	std::sort(edges.begin(),edges.end());
	std::vector<Edge<T>> result;
	int e = 0;
	int i = 0;
	union_find subsets = union_find(nodes.size());
	while(e < (int)nodes.size()-1){
		Edge<T> next_edge = edges[i++];
		Node<T> n1 = next_edge.getNode1();
		Node<T> n2 = next_edge.getNode2();
		int i1,i2;
		int count = 0;
		for(Node<T> &n : nodes){
			if(n == n1){
				i1 = count;
			}
			if(n == n2){
				i2 = count;
			}
			count ++;
		}
		int x = subsets.find(i1);
		int y = subsets.find(i2);
		if(x != y){
			e++;
			result.push_back(next_edge);
			subsets.merge(x,y);
		}
	}
	for(Edge<T> ed : result){
		std::cout << ed.getNode1().getID() << " "  << ed.getNode2().getID() << " "  << ed.getWeight() << std::endl;
	}

}

#endif
