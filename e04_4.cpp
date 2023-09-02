// e04_4.cpp
// const objects, const methods, mutable varaibles

#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

class Point {				         // Declaration/definition of the Point Class with low-limits
public:
	Point(int, int);				 // Constructor with two parameters to initialize x and y coordinates
	double distanceFromZero() const; // const method calculates and returns the distance of a point from (0,0)
	void print() const;			     // const method prints coordinates on the screen
	// Getters are const:
	int getX() const { return m_x; }         // Accessor for x coordinate
	int getY() const { return m_y; }         // Accessor for y coordinate
	int getMIN_x() const { return MIN_x; }   // Accessor for the limit of the x coordinate
	int getMIN_y() const { return MIN_y; }   // Accessor for the limit of the y coordinate
	unsigned int getPrintCount() const { return m_printCount; }
	// Setters are NOT const:
	void setX(int);
	void setY(int);
	bool move(int, int);					// A non-constant method to move points
	
private:
	// Lower Limits of x and y
	//Constants are usually defined as static members! (See static members)
	const int MIN_x{};						// Zero initialization
	const int MIN_y{};
	int m_x{ MIN_x }, m_y{ MIN_y };			// x and y coordinates are initialized 
	mutable unsigned int m_printCount{};	// A mutable variable to count how many times a point object is printed
};

// ***** Bodies of Member Functions *****

// Constructor with two parameters to initialize x and y coordinates
Point::Point(int firstX, int firstY)
{
	cout << "Constructor is called..." << endl;
	// It can call its methods
	setX(firstX); // Accepts only valid values 
	setY(firstY); // Accepts only valid values 
}

// A const method calculates and returns the distance of a point from (0,0)
double Point::distanceFromZero() const {
	return sqrt(m_x * m_x + m_y * m_y);   // distance from (0,0)
}

// A const method to print the coordinates on the screen
// It also increments and prints the mutable printCount
void Point::print() const
{
	std::cout << "X= " << m_x << ", Y= " << m_y << std::endl;
	std::cout << "Print count= " << ++m_printCount << std::endl;  // increment and print the mutable printCount
}

// Setters
void Point::setX(int new_x) {
	if (new_x >= MIN_x) m_x = new_x;  // Accepts only valid values 
}
void Point::setY(int new_y) {
	if (new_y >= MIN_y) m_y = new_y;  // Accepts only valid values 
}

// A function to move the points 
// It checks the input values.
// If the values fall within the limits they are accepted, the point moves, and the function returns true.
// If the values are not within the limits, the point does not move, and the function returns false.
bool Point::move(int new_x, int new_y)
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

// -------- Main Program -------------
int main()
{
	const Point fixedPoint{ 10, 20 };			// Constant object
	cout << "Distance from Zero = " << fixedPoint.distanceFromZero() << endl;
	fixedPoint.print();							// Print the constant point
	fixedPoint.print();							// Print the constant point again
	//fixedPoint.move(15, 25);					// ERROR! fixedPoint is constant cannot move   

	Point nonFixedPoint{ 30, 40 };				// Non-constant object 
	cout << "Distance from Zero = " << nonFixedPoint.distanceFromZero() << endl;
	nonFixedPoint.print();						// Print the non-constant point
	nonFixedPoint.move(100, 200);	// non-constant object can move  
	nonFixedPoint.print();						// Print the non-constant point again
	return 0;
}