﻿// point.h for e07_19
// Definition of Point class
#pragma once

// *** The Point Class (Base Class)
class Point {				
public:
	Point(int, int);						// Constructor to initialize coordinates 
	// Getters are const:
	int getX() const { return m_x; }         // Accessor for x coordinate
	int getY() const { return m_y; }         // Accessor for y coordinate
	// Setters
	void setX(int);
	void setY(int);
	// Lower Limits of x and y coordinates
	static inline const int MIN_x{};            // Zero initialization
	static inline const int MIN_y{};
private:
	int m_x{ MIN_x }, m_y{ MIN_y };			   // x and y coordinates are initialized 
};