// e07_10.cpp
// Inheritance and composition
// Constructors and destructors

#include <iostream>
using std::cout;
using std::endl;

// *** Part Class for Parent
// Defines objects that belong to Parent
class PartForParent {
public:
	PartForParent(int in_data) :m_data{ in_data } {		// Constructor of the Part for Parent
		cout << "PartForParent constructor" << endl;
	} 
	~PartForParent() { cout << "PartForParent destructor" << endl; }; // Destructor of the Part for Parent. Unnecessary
	void print() const { cout << "Data of PartForParent = " << m_data << endl; }
private:
	int m_data{};                                     // data of the part
};

// *** Base Class
class Parent {								
public:
	Parent(int in_data1, int in_data2) : m_part{in_data1}, m_data{ in_data2 } {				// Constructor of the Parent
		cout << "Parent constructor" << endl; }
	~Parent() { cout << "Parent destructor" << endl; }					// Destructor of the Parent. Unnecessary
	void print() const { 
		 m_part.print();
	     cout << "Data of Parent = " << m_data << endl; }
private:
	PartForParent m_part;				// Parent contains (has) a part 
	int m_data{};					    // data of Parent
};


// *** Part Class for Child
// Defines objects that belong to Child
class PartForChild {
public:
	PartForChild(int in_data) :m_data{ in_data } {				// Constructor of the Part for Child
		cout << "PartForChild constructor" << endl; }
	~PartForChild() { cout << "PartForChild destructor" << endl; }; // Destructor of the Part for Child. Unnecessary
	void print() const { cout << "Data of PartForChild = " << m_data << endl; }
private:
	int m_data{};		// data of the part
};


// *** The Derived Class
class Child : public Parent {
public:
	Child(int in_data1, int in_data2, int in_data3, int in_data4)      // Constructor of the Child
		: Parent{ in_data1, in_data2 }, m_part{ in_data3 }, m_data{ in_data4 }
	{ cout << "Child constructor" << endl; }; 
	~Child() { cout << "Child destructor" << endl; };        // Destructor of the Child. Unnecessary
	void print() const {
		Parent::print();
		m_part.print();
		cout << "Data of Child = " << m_data << endl;
	}
private:
	PartForChild m_part;         // Child contains (has) a part 
	int m_data{};				 // data of Child
};

// -------- Main Program -------------
int main()
{
	Child child_object{ 1, 2, 3, 4 };				  // An object of the Child
	child_object.print();
	return 0;
}