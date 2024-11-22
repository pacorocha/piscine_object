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

	graph.display();
}
