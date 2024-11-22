#ifndef VECTOR2_HPP
# define VECTOR2_HPP

#include <iostream>
#include <vector>
#include <iomanip>

class Vector2 {
	private:
		float _x;
		float _y;

	public:
		Vector2(void);
		Vector2(float x, float y);
		~Vector2(void);

	// Getters
		float getX() const;
		float getY() const;

	// Setters
		void setX(float x);
		void setY(float y);
};

#endif