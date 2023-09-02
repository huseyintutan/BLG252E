// e06_5.cpp
// Parameter visibility
// Sending this pointer as an argument to establish visibility.

#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

class Point;		// Declaration only for GraphicTools

// A class that contains Point-related tools 
class GraphicTools {
public:
	double distanceFromZero(const Point&) const;	//calculates and returns the distance of a point from(0, 0)
};

class Point {				         // Declaration/definition of the Point Class with low-limits
public:
	Point(int, int, GraphicTools*);			// Constructor to initialize coordinates and the pointer to GraphicTools for visibility
	double distanceFromZero() const;		// const method uses GraphicTools to calculate the distance of a point from (0,0)
	void print() const;						// const method prints coordinates on the screen
	// Getters are const:
	int getX() const { return m_x; }         // Accessor for x coordinate
	int getY() const { return m_y; }         // Accessor for y coordinate
	int getMIN_x() const { return MIN_x; }   // Accessor for the limit of the x coordinate
	int getMIN_y() const { return MIN_y; }   // Accessor for the limit of the y coordinate
	// Setters are NOT const:
	void setX(int);
	void setY(int);
	bool operator()(int, int);					// Function call operator to move points
	// Static public constants
	// Lower Limits of x and y coordinates
	static inline const int MIN_x{};            // Zero initialization
	static inline const int MIN_y{};
private:
	int m_x{ MIN_x }, m_y{ MIN_y };			// x and y coordinates are initialized 
	GraphicTools * m_toolPtr;				// Visibility to GrpahicsTool
};

// ***** Methods of the Point class *****

// Constructor with two parameters to initialize x and y coordinates
Point::Point(int firstX, int firstY, GraphicTools * toolPtr): m_toolPtr{toolPtr}     // Visibility
{
	cout << "Constructor is called..." << endl;
	// It can call its methods
	setX(firstX); // Accepts only valid values 
	setY(firstY); // Accepts only valid values 
}

// A const method calculates and returns the distance of a point from (0,0)
double Point::distanceFromZero() const {
	return m_toolPtr->distanceFromZero(*this);         // using the GraphicTools, sending this for visiblity
}

// A const method to print the coordinates on the screen
void Point::print() const
{
   cout << "X= " << m_x << ", Y= " << m_y << endl;
}

// Setters
void Point::setX(int new_x) {
	if (new_x >= MIN_x) m_x = new_x;  // Accepts only valid values 
}
void Point::setY(int new_y) {
	if (new_y >= MIN_y) m_y = new_y;  // Accepts only valid values 
}

// Overloading the function call operator to move the points 
// It checks the input values.
// If the values fall within the limits they are accepted, the point moves, and the function returns true.
// If the values are not within the limits, the point does not move, and the function returns false.
bool Point::operator()(int new_x, int new_y)
{
	if (new_x >= MIN_x &&  // if new_x is within the limits
		new_y >= MIN_y)    // if new_x is within the limits
	{
		m_x = new_x;						// assigns new value to x coordinate
		m_y = new_y;						// assigns new value to y coordinate 
		return true;
	}
	return false;						     // new values are not accepted
}

// ***** Methods of the GraphicTools class *****

// Calculates and returns the distance of a point from(0, 0)
// Paremeter visibility. The method can "see" the point object
double GraphicTools::distanceFromZero(const Point& in_point) const {
	double local_x = in_point.getX();					// Can call methods of the Point becauese there is a paremeter visibility
	double local_y = in_point.getY();
	return sqrt(local_x * local_x + local_y * local_y);   // distance from (0,0)
}

// -------- Main Program -------------
int main()
{
	GraphicTools gtool;						// A GraphicTools object
	Point point1{ 10, 20, &gtool };			// Visibility from Point to GaraphicTools				 
	cout << "Distance of the point1 from Zero is " << point1.distanceFromZero() << endl;  // Point uses GraphiğcsTool for calculoation
	return 0;
}