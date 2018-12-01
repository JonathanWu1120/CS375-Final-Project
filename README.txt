How to run this program:
	"make test" will run the test program which will demonstrate the functionality of the program and algorithms
	The test cases and datasets are all included in graphTest.cpp which is also the driver for all of our tests

To run other test cases, please do the following:
	1. Generate a vector of Node<T> with the format Node<T> node = Node<T>(T data)
	2. Using the vector of nodes, generate an array of edges. Edges are constructed as Edge<T> edge = Edge<T>(Node<T> node1, Node<T> node2, int weight) where node1 is the start of the edge and node2 is the end of the edge.
	3. To create an undirected graph, for each edge you create also create an edge Edge<T> edge2 = Edge<T>(edge.getNode2(), edge.getNode1(), edge.getWeight())
	4. Create a graph from the arrays of nodes and edges by using AMGraph<T>(vector<Node<T>> V, vector<Edge<T>> E) or ALGraph<T>(vector<Node<T>> V, vector<Edge<T>> E)
	5. Run Kruskals algorithm by using KruskalMST<T>(AMGraph<T> G) or KruskalMST<T>(ALGraph<T> G)
	6. Run Reverse-Delete algorithm by using revDelMST<T>(AMGraph<T> G) or revDelMST<T>(ALGraph<T> G)
