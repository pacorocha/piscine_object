#include "Graph.hpp"

Graph::Graph(void) : _size(0,0) {}

Graph::Graph(float width, float height) : _size(width, height) {}

Graph::~Graph(void) {}

void Graph::addPoint(const Vector2& point) {
	if (point.getX() >= 0 && point.getX() <= _size.getX() && point.getY() >= 0
	&& point.getY() <= _size.getY()) {
		_points.push_back(point);
	}
	else {
		std::cout << "Point \e[0;31m(" << point.getX() << ", " << point.getY()
		<< ")\033[0m is out of range and can't be added to the graph."
		<< std::endl;
		std::cout << std::endl;
	}
}

void Graph::addLine(const Vector2& start, const Vector2& end) {
	_lines.push_back(std::make_pair(start, end));
}

void Graph::display(void) const {
	for (int y = static_cast<int>(_size.getY()) - 1; y >= 0; --y) {
		std::cout << std::setw(1) << y << " ";
		for (int x = 0; x < static_cast<int>(_size.getX()); ++x) {
			bool isPoint = false;
			for (size_t i = 0; i < _points.size(); ++i) {
				if (static_cast<int>(_points[i].getX()) == x
				&& static_cast<int>(_points[i].getY()) == y) {
					isPoint = true;
					break;
				}
			}
			if (isPoint) {
				std::cout << " X ";
			}
			else {
				std::cout << " . ";
			}
		}
		std::cout << std::endl;
	}

    std::cout << "  ";
    for (int x = 0; x < static_cast<int>(_size.getX()); ++x) {
        std::cout << " " << x << " ";
    }
    std::cout << "\n";
}
