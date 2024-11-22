#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Vector2.hpp"
#include <fstream>
#include <png.h>

class Graph {
	private:
		Vector2 _size;
		std::vector<Vector2> _points;
		std::vector<std::pair<Vector2, Vector2> > _lines;

	public:
		Graph(void);
		Graph(float width, float height);
		~Graph(void);

		void addPoint(const Vector2& point);
		void addLine(const Vector2& start, const Vector2& end);
		void display(void) const;
};

#endif
