#include <ALGraph.h>
#include <AMGraph.h>
#include <Edge.h>
#include <Node.h>
#include <string>
#include <stdio.h>
#include <algorithm>

int compare(Edge* a, Edge* b){
	return a->getWeight() > b.getWeight();
}

void revDelMST(AMGraph* graph){
	std::vector<Edge<int>> edges = graph->getEdges();
	std::vector<Edge<int>> temp;
	std::sort(edges.begin(),edges.end(),compare);
	for (auto i = edges.begin(); i != edges.end();){
		int erased = 0;
		Node<int> vertex1 = edges[i].getNode1();
		Node<int> vertex2 = edges[i].getNode2();
		
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
		
		if (//isn't connected){
			//add each vertex to the other's in adjacency matrix
			graph->adjLists[i.getNode1().getID()].push_back(i.getNode2());
			graph->adjLists[i.getNode2().getID()].push_back(i.getNode1());
			edges.insert(edges.begin(), temp, temp+temp.size());//does this work?
			temp.clear();
		}
		
		//increments if not shifted
		i+=(erased==0)?1:0;
	}
	for (auto i = discard.begin(); i < discard.end(); i++){
		for (auto j = edges.begin(); j < edges.end();){
			if (i.getNode1() == j.getNode1() && i.getNode2() == j.getNode2()) j = edges.erase(j);
			else j++;
		}
	}
	for (Edge edge : edges) std::cout << " " << e.getNode1().getID() << " " <<e.getNode2().getID() << " " <<e.getWeight() << std::endl;
}
