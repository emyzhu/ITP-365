#pragma once
#include <sstream>
#include <ostream>
#include <stdexcept>

template <typename T>
class ITPVector
{
    const unsigned INITIAL_CAPACITY = 10;
    const unsigned CAPACITY_MULTIPLIER = 2;
public:
    // Function: Default constructor
    // Purpose: Initializes the ITP vector to have a
    // capacity of INITIAL_CAPACITY and a size of 0.
    // It also dynamically allocates the underlining array data
    // Input: None
    // Returns: Nothing
    ITPVector()
    {
        mCapacity = INITIAL_CAPACITY;
        mSize = 0;
        mData = new T[mCapacity];

    }
    
    // Function: Parameterized constructor
    // Purpose: Initializes the ITP vector to have a
    // capacity of inCapacity and a size of 0.
    // It also dynamically allocates the underlining array data
    // Input: Initial vector capacity
    // Returns: Nothing
    ITPVector(unsigned inCapacity)
    {
        mCapacity = inCapacity;
        mSize = 0;
        mData = new T[mCapacity];

    }
    
    // Function: Copy constructor
    // Purpose: Initializes the ITP vector to have a
    // Copy of the other vector.
    // It also dynamically allocates the underlining array data
    // Input: Other vector to copy
    // Returns: Nothing
    ITPVector(const ITPVector<T>& other)
    {
        mSize = 0;
        mCapacity = other.size();
        mData = new T[mCapacity];
        for(int i =0; i < other.size(); i++) {
            push_back(other[i]);
        }
        
    }
    
    // Function: Assignment operator
    // Purpose: Does a deep copy from other to this vector
    // Input: Other vector to copy
    // Returns: Reference to this vector
    ITPVector<T>& operator=(const ITPVector<T>& other)
    {
        clear();
        // need to delete twice!
        delete [] mData;
        mCapacity = other.size();
        mData = new T[mCapacity];
        for(int i = 0; i < other.size(); i++){
            push_back(other[i]);
        }
        // Return a reference
        return *this;
    }
    
    // Function: Destructor
    // Purpose: Deletes the underlying array and
    // sets size/capacity to zero
    // Input: None
    // Returns: Nothing
    ~ITPVector()
    {
        delete[] mData;
        // set data to null so there's not just a pointer pointing to something that's been deleted!
        mData = nullptr;
        mSize = 0;
        mCapacity = 0;
    }
    
    // Function: clear
    // Purpose: Deletes the underlying array
    // Then creates a new underlying array of the old capacity
    // And sets size to 0
    // Input: None
    // Returns: Nothing
    void clear()
    {
        delete[] mData;
        mData = new T[mCapacity];
        mSize = 0;
    }
    
    
    // Function: capacity
    // Purpose: Returns the current capacity of the underlying array data
    // Input: None
    // Returns: Capacity of underlying array data
    unsigned capacity() const
    {
        return mCapacity;
    }
    
    // Function: size
    // Purpose: Returns the current size of the vector
    // Input: None
    // Returns: Size of vector
    unsigned size() const
    {
        return mSize;
    }
    
    // Function: data
    // Purpose: Returns a pointer to the underlying array
    // Input: None
    // Returns: A pointer to the underlying array
    T* data() const
    {
        return mData;
    }
    
    // Function: Subscript operator (read/write version)
    // Purpose: Grabs the specified index from vector
    // Throws an exception if the index is out of bounds
    // Input: Index to access
    // Returns: Value at index, by reference
    T& operator[](unsigned index)
    {
        if(index < 0 || index >= mSize) {
            throw std::out_of_range (("Index is out of bounds!"));
        }
        return mData[index];
        
    }
    
    // Function: Subscript operator (read-only version)
    // Purpose: Grabs the specified index from vector
    // Throws an exception if the index is out of bounds
    // Input: Index to access
    // Returns: Value at index, by reference
    const T& operator[](unsigned index) const
    {
        if(index < 0 || index >= mSize) {
            throw std::out_of_range (("Index is out of bounds!"));
        }
        return mData[index];
    }
    
    // Function: insert_back
    // Purpose: Adds the specified element to the end of the ITPVector
    // It automatically reallocates the underlying array if we are
    // going over capacity
    // Input: Value to add (by const reference)
    // Returns: Nothing
    void push_back(const T& value)
    {
        if(mSize == mCapacity) {
            //increases capacity
            mCapacity *= CAPACITY_MULTIPLIER;
            T* newData = new T[mCapacity];
            for(int i = 0; i < mSize; i++) {
                newData[i] = mData[i];
            }
            delete [] mData;
            mData = newData;
        }
        mData[mSize] = value;
        mSize += 1;
    }
    
    // Function: get_back
    // Purpose: Returns the current last element in the vector
    // Does not remove this element from the vector
    // Throws an exception if there are no elements in the vector
    // Input: Nothing
    // Returns: Value at back of vector, by reference
    T& back()
    {
        if (mSize == 0) {
            throw std::out_of_range (("No elements in the vector."));
        }
        return mData[mSize - 1];
    }
    
    // Function: remove_back
    // Purpose: Removes the last element from the ITPVector
    // Throws an exception if there are no elements in the vector
    // Input: Nothing
    // Returns: Nothing
    void pop_back()
    {
        if (mSize == 0) {
            throw std::out_of_range (("No elements in the vector."));
        }
        mSize -= 1;
    }
    
    // Function: Output Stream Operator
    // Purpose: Prints the contents of the vector to the provided stream
    // Written in the format of {x, y, ..., z}
    // Input: Stream to write to, vector to write
    // Output: Stream after values are written
    friend std::ostream& operator<<(std::ostream& os, const ITPVector<T>& vector)
    {
        os << "{";
        for(int i = 0; i < vector.size(); i++) {
            if(i == vector.size() - 1) {
                os << vector[i];
            }
            os << vector[i] << ",";
        }
        os << "}";
        return os;
    }
    
private:
    unsigned mCapacity;
    unsigned mSize;
    T* mData;
};
