//Jade Pearl
//Created: 9/20/2022
//Modified: 9/21/2022

//ALTERATION/UPDATE of the original IntegerList.h code from the Lab04Files.

#ifndef INTEGERLIST_H
#define INTEGERLIST_H

class IntegerList
{
  private:
    int *list;                 // Pointer to the array.
    int numElements;           // Number of elements.
    bool isValid(int) const;   // Validates subscripts.

  public:
    IntegerList(int);          // Constructor
    ~IntegerList();            // Destructor
    void setElement(int, int); // Sets an element to a value
    int getElement(int) const; // Returns an element
    void displayList() const;  // Display list

    IntegerList(const IntegerList &obj);
	  const IntegerList operator=(const IntegerList &right);
	  int& operator[](const int &); //edited function; deleted sub

    //added functions
    const IntegerList operator+ (const IntegerList &right); //concatenates two lists
    IntegerList(); //Default constructor that is made for when l3 is declared
    void resize(int); //resizes the array
    const IntegerList sublist(int, int); //returns a new IntegerList of the segment between the first and second input positions.
    const IntegerList sublist(int); //returns a new IntegerList of the segment from the input position to the end of the list
    const IntegerList sort(); //sort into ascending order and return it
};

#endif