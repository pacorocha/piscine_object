#include "Vector2.hpp"
#include "Graph.hpp"

int main() {
	Graph graph(10, 10);

	graph.addPoint(Vector2(0, 0));
	graph.addPoint(Vector2(2, 2));
	graph.addPoint(Vector2(4, 2));
	graph.addPoint(Vector2(2, 4));
	try {
		graph.addPoint(Vector2(12, 10));
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	Graph graph2(100, 100);
    graph2.addPoint(Vector2(20, 30));
    graph2.addPoint(Vector2(40, 50));
	graph2.addLine(Vector2(20, 30), Vector2(40, 50));

	graph.display();

}
