#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Vector2.hpp"

class Graph {
	private:
		Vector2 _size;
		std::vector<Vector2> _points;

	public:
		Graph(void);
		Graph(float width, float height);
		~Graph(void);

		void addPoint(const Vector2& point);
		void display(void) const;
};

#endif
