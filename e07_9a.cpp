// e07_9a.cpp
// The constructor of the derived class must call the constructor of the base class
// In this example the Point class does not have a default constructor. It has only a constructor with parameters.

#include <iostream>
using std::cout;
using std::endl;

// *** The Point Class (Base Class)
// This class does not contain a default constructor
class Point {								
public:
	Point(int, int);						// Constructor to initialize x and y coordinates
	void print() const;			            // prints coordinates on the screen
	// Getters are const:
	int getX() const { return m_x; }         // Accessor for x coordinate
	int getY() const { return m_y; }         // Accessor for y coordinate
	// Setters are NOT const:
	void setX(int);
	void setY(int);
	// Static public constants
	// Lower Limits of x and y coordinates
	static inline const int MIN_x{};            // Zero initialization
	static inline const int MIN_y{};
private:
	int m_x{MIN_x}, m_y{MIN_y};						 // x and y coordinates are initialized 
};

// ***** Bodies of Member Functions of the Point class *****

// Constructor to initialize x and y coordinates
Point::Point(int in_x, int in_y)
{
	cout << "Constructor of the Point (Base)" << endl;
	if (in_x >= MIN_x &&  // if in_x is within the limits
		in_y >= MIN_y)    // if in_y is within the limits
	{
		m_x = in_x;						// assigns new value to x coordinate
		m_y = in_y;						// assigns new value to y coordinate 
	}
}

// A const method to print the coordinates on the screen
void Point::print() const
{
	std::cout << "X= " << m_x << ", Y= " << m_y << std::endl;
}

// Setters
void Point::setX(int new_x) {
	if (new_x >= MIN_x) m_x = new_x;  // Accepts only valid values 
}
void Point::setY(int new_y) {
	if (new_y >= MIN_y) m_y = new_y;  // Accepts only valid values 
}

// Enumeration to define colors
enum class Color {Blue, Purple, Green, Red};  

// *** The ColoredPoint Class (Derived Class)
class ColoredPoint : public Point {
public:
	//ColoredPoint(Color in_color) : m_color{ in_color } { }  // Error! The base class Point does not have a defaut constructor
	ColoredPoint (int, int, Color);						// Constructor to initialize the colored point
	void print() const;									// ColoredPoint overrides (redefines) the print function
	Color getColor() const { return m_color; }			// Getter returns color of the point
	void setColor(Color in_color) { m_color = in_color; }// Setter modifies the color of the point
private:
	Color m_color;										// Color of the point
};

// ***** Bodies of Member Functions of the ColoredPoint class *****
// Constructor 
// It calls the constructor of the Point
ColoredPoint::ColoredPoint(int in_x, int in_y, Color in_color) : Point{in_x, in_y}, m_color{in_color}
{
	cout << "Constructor of the ColoredPoint (Derived)" << endl;
}

// ColoredPoint overrides (redefines) the print function of the Point
// This function prints the color as well
void ColoredPoint::print() const
{
	Point::print();       // calls print inherited from Point to print x and y coordinates
	// prints the color
	switch (m_color)
	{
	case Color::Blue: cout << "Color = Blue" << endl;
		break;
	case Color::Purple: cout << "Color = Purple" << endl;
		break;
	case Color::Green: cout << "Color = Green" << endl;
		break;
	case Color::Red:  cout << "Color = Red" << endl;
		break;
	default: cout << "Not a standard color" << endl;
		break;
	}
}
// -------- Main Program -------------
int main()
{
	ColoredPoint col_point1{10, 20, Color::Green };		// A green point
	col_point1.print();								// print function of the ColoredPoint
		
	return 0;
}