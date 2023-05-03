#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray {

public:

	//Constructors
	//Default
	DynamicArray();

	//Copy Constructor
	DynamicArray(const DynamicArray&);

	//Destructor
	~DynamicArray();


	//Class Memeber Functions

	//Get size
	unsigned int size() const;

	//Check if empty
	bool empty() const;

	//Add unsigned int to end of array
	void pushBack(unsigned int);

	//Remove last item from array
	void popBack();


	//Operator Overloads

	//Deep Copy Overload
	const DynamicArray& operator = (const DynamicArray&);

	//Subscript operator (lvalue)
	unsigned int& operator [] (size_t);

	//Subscript operator (rvalue)
	const unsigned int& operator [] (size_t) const;


private:

	//Data Fields
	static const size_t DEFAULTCAPACITY;
	unsigned int capacity;
	unsigned int numOfItems;
	unsigned int* data;


	//Class Member Functions

	//increase size of array when needed
	void resize();

};
#endif
