#include "Vector2.hpp"

Vector2::Vector2() : _x(0.0f), _y(0.0f) {}

Vector2::Vector2(float x, float y) : _x(x), _y(y) {}

Vector2::~Vector2() {}

// Getters
float Vector2::getX() const {
    return _x;
}

float Vector2::getY() const {
    return _y;
}

// Setters
void Vector2::setX(float x) {
    this->_x = x;
}

void Vector2::setY(float y) {
    this->_y = y;
}
