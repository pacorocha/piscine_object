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

void Graph::saveAsPNG(const std::string& filename) const {
	const int width = static_cast<int>(_size.getX());
	const int height = static_cast<int>(_size.getY());

	// Allocate image
	png_bytep* row_pointers = new png_bytep[height];
	for (int y = 0; y < height; ++y) {
		row_pointers[y] = new png_byte[width * 3];
	}

	// Draw points
	for (size_t i = 0; i < _points.size(); ++i) {
		const int x = static_cast<int>(_points[i].getX());
		const int y = static_cast<int>(_points[i].getY());
		if (x >= 0 && x < width && y >= 0 && y < height) {
			row_pointers[height - y - 1][x * 3] = 255;
			row_pointers[height - y -1][x * 3 + 1] = 0;
			row_pointers[height - y -1][x * 3 + 2] = 0;
		}
	}

	// Draw lines
	for (size_t i = 0; i < _lines.size(); ++i) {
		Vector2 start = _lines[i].first;
		Vector2 end = _lines[i].second;

		int x1 = static_cast<int>(start.getX());
		int y1 = static_cast<int>(start.getY());
		int x2 = static_cast<int>(end.getX());
		int y2 = static_cast<int>(end.getY());

		// Bresenham's line algorithm
		int dx = abs(x2 - x1);
		int dy = abs(y2 - y1);
		int sx = (x1 < x2) ? 1 : -1;
		int sy = (y1 < y2) ? 1 : -1;
		int err = (dx > dy ? dx : -dy) / 2;
		int e2;

		while (true) {
			if (x1 >= 0 && x1 < width && y1 >= 0 && y1 < height) {
				row_pointers[height - y1 - 1][x1 * 3] = 0;
				row_pointers[height - y1 - 1][x1 * 3 + 1] = 0;
				row_pointers[height - y1 - 1][x1 * 3 + 2] = 255;
			}
			if (x1 == x2 && y1 == y2) {
				break;
			}
			e2 = 2 * err;
			if (e2 > -dy) {
				err -= dy;
				x1 += sx;
			}
			if (e2 < dx) {
				err += dx;
				y1 += sy;
			}
		}

		FILE* fp = fopen(filename.c_str(), "wb");
		if (!fp) {
			std::cerr << "Could not open file for writing: "
			<< filename << std::endl;
			return;
		}

		png_structp png = png_create_write_struct(
			PNG_LIBPNG_VER_STRING, NULL, NULL, NULL
		);
		if (!png) {
			std::cerr << "Could not create PNG write structure" << std::endl;
			fclose(fp);
			return;
		}

		png_infop info = png_create_info_struct(png);
		if (!info) {
			std::cerr << "Could not create PNG info structure" << std::endl;
			png_destroy_write_struct(&png, NULL);
			fclose(fp);
			return;
		}

		// Error handling
		if (setjmp(png_jmpbuf(png))) {
			std::cerr << "Error during PNG creation" << std::endl;
			png_destroy_write_struct(&png, &info);
			fclose(fp);
			return;
		}

		png_init_io(png, fp);
		png_set_IHDR(
			png, info, width, height, 8, PNG_COLOR_TYPE_RGB,
			PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT,
			PNG_FILTER_TYPE_DEFAULT
		);
		png_write_info(png, info);
		png_write_image(png, row_pointers);
		png_write_end(png, NULL);

		// Clean up
		for (int y = 0; y < height; ++y) {
			delete[] row_pointers[y];
		}
		delete[] row_pointers;

		png_destroy_write_struct(&png, &info);
		fclose(fp);
	}
}

void Graph::readFromFile(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file) {
		std:: cerr << "Could not open file " << filename
		<< " for reading: " << std::endl;
		return;
	}
	float x, y;
	while (file >> x >> y) {
		addPoint(Vector2(x, y));
	}

	file.close();
}

