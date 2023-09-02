﻿// colored_point.h for e07_19
// Definition of ColoredPoint class
#pragma once

#include "point.h"

// Enumeration to define colors
enum class Color { Blue, Purple, Green, Red };

// *** The ColoredPoint Class (Derived Class)
class ColoredPoint : public Point {						// Public inheritance
public:
	ColoredPoint(int, int, Color);
	Color getColor() const { return m_color; }			// Getter returns color of the point
	void setColor(Color in_color) { m_color = in_color; }// Setter modifies the color of the point
private:
	Color m_color{ Color::Red };										// Color of the point
};