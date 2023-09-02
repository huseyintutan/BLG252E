// e07_13.cpp
// COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR UNDER INHERITANCE
// DoubleString is a kind of String

#include <iostream>         // for IO operations 
#include <cstring>			// for old string functions inherited from C
// The new header for strings is <string>
using std::cout;
using std::endl;

/*
The standard library of C++ contains a std::string class.
Programmers do not need to write their own String classes.
We write this class using old string functions inherited from C, only to show some concepts.
*/

//*** String
// A class to define strings
// contents of strings terminate with a null character '\0'
class String {
public:
	String();         			                // Default constructor
	String(const char*);						// Constructor
	String(const String&);						// Copy Constructor
	const String& operator=(const String&);		// Copy assignment operator
	void print() const;							// A member function to print the string
	//void setContents(const char*);				// Setter
	~String();									// Destructor
private:
	size_t size;					// length of a string
	char* contents;					// pointer to the character array
};

// Default Constructor
String::String()           							
{
	cout << "String Default" << endl;
	size = 0; contents = new char[1];
	strcpy_s(contents,1, "");		// Empty string
	//strcpy(contents, "");                                     // If your compiler does not support strcpy_s

}
// Constructor
// Allocates memory 
// copies the input character array that terminates with null character
// to the contents of the string
String::String(const char* inData)
{
	cout << "String Constructor" << endl;
	size = strlen(inData);
	contents = new char[size + 1];   // +1 for null character
	strcpy_s(contents, size + 1, inData);		// input_data is copied to the contents
	//strcpy(contents, inData);											// If your compiler does not support strcpy_s
}

// Copy Constructor
// Allocates memory 
// copies the contents of the existing object to the newly constructed object
String::String(const String& originalString)
{
	cout << "String Copy Constructor" << endl;
	size = originalString.size;
	contents = new char[size + 1];   // Memory allocation. +1 for null character
	strcpy_s(contents, size + 1, originalString.contents);	 // copy between two contents
	//strcpy(contents, inData);											// If your compiler does not support strcpy_s
}

// Copy Assignment operator
const String& String::operator=(const String& in_object)
{
	cout << "String Assignment operator" << endl;
	if (this != &in_object) {					// checking for self-assignment
		if (size != in_object.size) {			// if the sizes of the source and destination are different
			size = in_object.size;				
			delete[] contents;					// The old contents is deleted
			contents = new char[size + 1];		// Memory allocation for the new contents
		}
		// Copy the contents of the sourse to the destination
		strcpy_s(contents, size+1,in_object.contents);
		//strcpy(contents, inData);											// If your compiler does not support strcpy_s
	}
	return *this;  								// returns a reference to the object
}

void String::print() const
{
	cout << contents << " " << size << endl;
}

// Destructor
// Memory pointed to by the pointer contents is given back to the heap
String::~String()
{
	cout << "String Destructor" << endl;
	delete[] contents;
}


// **** DoubleString is derived from String
// we will write its own constructors and assignment operator
//
class DoubleString : public String {
public:
	DoubleString();         			                     // default constructor
	DoubleString(const char*, const char*);					// constructor
	DoubleString(const DoubleString&); 			             // copy constructor
	const DoubleString& operator=(const DoubleString&);		// assignment operator
	void print() const;										// an ordinary member function
	~DoubleString();										// destructor
private:
	size_t m_size2;
	char* m_contents2;
};

// Default Constructor
DoubleString::DoubleString()           		         // Default Constructor
{
	cout << "DoubleString Default constructor" << endl;
	m_size2 = 0; m_contents2 = new char[1];
	strcpy_s(m_contents2, 1, "");			// Empty string
	//strcpy(m_contents2, "");

}

// Constructor 
DoubleString::DoubleString(const char* in_data1, const char* in_data2) : String{ in_data1 }   // initialize String
{
	cout << "DoubleString Constructor" << endl;
	m_size2 = strlen(in_data2);
	m_contents2 = new char[m_size2 + 1];
	strcpy_s(m_contents2, m_size2 + 1, in_data2);		// input_data is copied to the contents
	//strcpy(m_contents2, in_data2);											    // If your compiler does not support strcpy_s
}
//** Copy Constructor of DoubleString **
DoubleString::DoubleString(const DoubleString& in_object) : String{ in_object }
{
	cout << "DoubleString Copy constructor" << endl;
	m_size2 = in_object.m_size2;
	m_contents2 = new char[m_size2 + 1];
	strcpy_s(m_contents2, m_size2 + 1, in_object.m_contents2);		// input_data is copied to the contents
	//strcpy(m_contents2, in_object.m_contents2);
}
//** Assignment operator **
const DoubleString& DoubleString::operator=(const DoubleString& in_object)
{
	if (this != &in_object) {					// checking for self-assignment
		String::operator=(in_object);					// call thpe operator of the String
		cout << "DoubleString Assignment operator" << endl;
		m_size2 = in_object.m_size2;
		delete[] m_contents2;               // delete old contents
		m_contents2 = new char[m_size2 + 1];
		strcpy_s(m_contents2, m_size2 + 1, in_object.m_contents2);		// input_data is copied to the contents
		//strcpy(m_contents2, in_object.m_contents2);
	}
	return *this;
}

void DoubleString::print() const
{
	String::print();
	cout << m_contents2 << " " << m_size2 << endl;
}

DoubleString::~DoubleString()
{
	cout << "DoubleString Destructor" << endl;
	delete[] m_contents2;
}


int main()
{
	DoubleString double_string1{ "First Part" , "This is the second part" };
	double_string1.print();
	cout << "---------------" << endl;
	
	DoubleString double_string2{ double_string1 };    // Copy constructor is invoked
	double_string2.print();
	cout << "---------------" << endl;

	DoubleString double_string3;              // Default constructor is invoked
	double_string3 = double_string2;            // Assignment
	double_string3.print();
	cout << "---------------" << endl;
	
	return 0;
}