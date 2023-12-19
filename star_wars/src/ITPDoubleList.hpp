#pragma once
#include <ostream>
#include <sstream>
#include <stdexcept>

template <typename T>
class ITPDoubleList
{
private:
    
    // Node only used internally to list
    struct Node
    {
        // Data in this node
        T mData;
        // Link to previous node
        Node* mPrev;
        // Link to next node
        Node* mNext;
    };
    
    // Pointer to the head node
    Node* mHead;
    // Pointer to the tail node
    Node* mTail;
    // Number of nodes currently in the list
    unsigned mSize;
    
public:
    // Iterator helper class...
    class Iterator
    {
    private:
        Node* mCurr;
    public:
        // Needed for List access
        friend class ITPDoubleList;
        // Constructors
        Iterator()
        {
            mCurr = nullptr;
        }
        
        Iterator(Node* inCurr)
        {
            mCurr = inCurr;
		}
        
        Iterator(const Iterator& src)
        {
            mCurr = src.mCurr;
        }
        
        // Assignment
        Iterator& operator=(const Iterator& src)
        {
            mCurr = src.mCurr;
            return *this;
        }
        
        // Incrementors / Decrementors
        // ++i
        Iterator& operator++()
        {
            mCurr = mCurr->mNext;
            return *this;
		}
        
        // i++
        Iterator operator++(int)
        {
            //overall implmentation goes like this: save the state before the return and return the old thing
            // increment item and return the old item
            
            // calling the copy constructor
			Iterator retval(*this);
            mCurr = mCurr->mNext;
            return retval;
		}
        
        // --i
        Iterator& operator--()
        {
			mCurr = mCurr->mPrev;
            return *this;
		}
        
        // i--
        Iterator operator--(int)
        {
			Iterator retval(*this);
            mCurr = mCurr->mPrev;
            return retval;
		}
        
        // Dereference
        T& operator*() const
        {
			return mCurr->mData;
		}
        
        Node* operator->() const
        {
            return mCurr;
        }
        
        // Comparison
        bool operator==(const Iterator& rhs) const
        {
            return mCurr == rhs.mCurr;
        }
        
        bool operator!=(const Iterator& rhs) const
        {
			return mCurr != rhs.mCurr;
        }
    };
    
    // List functions...
    
    // Function: Default Constructor
    // Purpose: Initializes size to 0 and head/tail to null
    // Input: None
    // Returns: Nothing
    ITPDoubleList()
    {
        mSize = 0;
        mHead = nullptr;
        mTail = nullptr;
    }
    
    // Function: Copy Constructor
    // Purpose: Initializes this list as a deep copy of other
    // Input: Other list to copy (const reference)
    // Returns: Nothing
    ITPDoubleList(const ITPDoubleList& other)
    {
        //set size to 0, head to null, tail to null
        mSize = 0;
        mHead = nullptr;
        mTail = nullptr;
        
        //Create a temp that points to the head node in “other”
        Node* temp = other.mHead;
        
        //while temp is not null
        while(temp != nullptr){
            //push_back temp’s data into this list
            push_back(temp->mData);
            //Advance temp to the next node
            temp = temp->mNext;
        }
	}
    
    // Function: Destructor
    // Purpose: Calls the clear function to delete the list
    // Input: None
    // Returns: Nothing
    ~ITPDoubleList()
    {
        clear();
	}
    
    // Function: clear
    // Purpose: Deletes every node in this list, sets size to 0, and head/tail to null
    // Input: None
    // Returns: Nothing
    void clear()
    {
        while(mSize > 0) {
            pop_front();
        }
	}
    
    // Assignment Operator
    // Function: Assignment Operator
    // Purpose: Clear this list, and then make a deep copy of other
    // Input: Other list to copy (const reference)
    // Returns: *this
    ITPDoubleList& operator=(const ITPDoubleList& other)
    {
        //Call clear (to clear out any values already in this list)
        clear();
        
        //Create a temp that points to the head node in “other”
        Node* temp = other.mHead;
               
        //while temp is not null
        while(temp != nullptr){
            //push_back temp’s data into this list
            push_back(temp->mData);
            //Advance temp to the next node
            temp = temp->mNext;
        }
        
        //By convention, operator= returns *this
        return *this;
    }
    
    // Function: size
    // Purpose: Gets the current size of the linked list
    // Input: None
    // Returns: size of the list
    unsigned size() const
    {
		return mSize;
    }
    
    // Function: push_front
    // Purpose: Inserts a node at the front of the linked list
    // Input: Value to store in the new node
    // Returns: Nothing
    void push_front(const T& value)
    {
        //dynamically allocating a new node;
        Node* newNode = new Node;
        //Set its data to the value
        newNode->mData = value;
        //Set its previous to null (since this will be the new head)
        newNode->mPrev = nullptr;
        // Set its next to the current head
        newNode->mNext = mHead;
        
        // If the size is 0…The tail is the new node
        if(mSize == 0) {
            mTail = newNode;
        }
        // Otherwise …set the previous of the current head to the new node
        else {
            mHead->mPrev = newNode;
        }
        
        // Set the head to the new node
        mHead = newNode;
        
        // Increment the size
        mSize += 1;
            
    }
    
    // Function: front
    // Purpose: Gets the value of the node at the front of the list
    // Input: None
    // Returns: Value of the node at the front of the list
    T& front()
    {
        //if size is 0, error!
        if (mSize == 0) {
            throw std::out_of_range( "There's nothing in the list!" );
        }
        // return data at the head node
        return mHead->mData;
    }
    
    // Function: pop_front
    // Purpose: Removes the node at the front of the list
    // Input: None
    // Returns: None
    void pop_front()
    {
        //if size is 0, error!
        if (mSize == 0) {
            throw std::out_of_range( "There's nothing in the list!" );
        }
        //otherwise if the size is 1...
        else if(mSize == 1) {
            // Delete the head node
            delete mHead;
            
            // Set head and tail to null, size to 0
            mHead = nullptr;
            mTail = nullptr;
            mSize = 0;
        }
        else {
            // Set a temp equal to the next node after head
            Node* temp = mHead->mNext;
            
            //delete the head node
            delete mHead;
            
            //The new head is temp
            mHead = temp;
            
            //The new head previous is now null
            mHead->mPrev = nullptr;
            
            //decrement size
            mSize -= 1;
        }
    }
    
    // Function: push_back
    // Purpose: Inserts a node at the end of the linked list
    // Input: Value to store in the new node
    // Returns: Nothing
    void push_back(const T& value)
    {
        //dynamically allocate a new node
        Node* newNode = new Node;
        //set its data to the value
        newNode->mData = value;
        //set its previous to the current tail
        newNode->mPrev = mTail;
        // Set the next to null (since this will be the new tail)
        newNode->mNext = nullptr;
        
        //If the size is 0… The head is the new node
        if(mSize == 0) {
            mHead = newNode;
        }
        // Otherwise …set the next of the current tail to the new node
        else{
            mTail->mNext = newNode;
        }
        
        //set the tail to the new node
        mTail = newNode;
        
        //Increment the size
        mSize += 1;
    }
    
    // Function: back
    // Purpose: Gets the value of the node at the back of the list
    // Input: None
    // Returns: Value of the node at the back of the list
    T& back()
    {
        //if size is 0, error!
        if (mSize == 0) {
            throw std::out_of_range( "There's nothing in the list!" );
        }
        // Return the data at the tail node
		return mTail->mData;
    }
    
    // Function: pop_back
    // Purpose: Removes the node at the end of the list
    // Input: None
    // Returns: None
    void pop_back()
    {
        //if size is 0, error!
        if (mSize == 0) {
            throw std::out_of_range( "There's nothing in the list!" );
        }
        //otherwise if the size is 1...
        else if(mSize == 1) {
            // Delete the tail node
            delete mTail;
            
            // Set head and tail to null, size to 0
            mHead = nullptr;
            mTail = nullptr;
            mSize = 0;
        }
        else {
            // Set a temp equal to the previous node before the tail
            Node* temp = mTail->mPrev;
            
            //delete the tail node
            delete mTail;
            
            //The new tail is temp
            mTail = temp;
            
            //The new tail next is now null
            mTail->mNext = nullptr;
            
            //decrement size
            mSize -= 1;
        }
	}
    
    // Function: begin
    // Purpose: Gets an iterator for the start of the list
    // Input: None
    // Returns: Iterator pointing to beginning of list
    Iterator begin() const
    {
        return Iterator (mHead);
    }
    
    // Function: end
    // Purpose: Gets an iterator for the end of the list
    // Input: None
    // Returns: Iterator pointing to end of list
    Iterator end() const
    {
        //go one past the last element
        return Iterator (mTail->mNext);
    }

	// Function: erase
	// Purpose: Removes the item at the node pointed to by i
	// Input: Iterator pointing to a valid node to remove before
	// Returns: A new iterator pointing to the node after the removed item
    Iterator erase(Iterator& i)
    {
        // If the iterator is invalid … error!
        if (i == nullptr) {
            throw std::out_of_range( "Error: not within bounds!" );
        }
        
        // If the iterator is at begin: 1.pop_front, 2.Return begin
        else if (i.mCurr == mHead) {
            pop_front();
            return begin();
            }

        //If the iterator is at tail: 1.pop_back, 2.Return end
        else if (i.mCurr == mTail) {
            pop_back();
            return end();
        }
        
        //otherwise
        else {
            // Make “before” and “after” pointers
            Node* toDel = i.mCurr;
            Node* before = toDel->mPrev;
            Node* after = toDel->mNext;
            
            //delete toDel
            delete toDel;
            
            //Set before’s next to after
            before->mNext = after;
            
            //Set after’s previous to before
            after->mPrev = before;
            
            //decrement size
            mSize -= 1;
            
            //Return an iterator to after
            return Iterator(after);
            
        }
    }

	// Function: insert
	// Purpose: Inserts a list item before node pointed to by i
	// Input: Iterator pointing to a valid node to insert before
	// Returns: A new iterator pointing to the inserted value
    Iterator insert(Iterator& i, const T& val)
    {
        Node* position = i.mCurr;

        // If the iterator is invalid … error!
        if (position == nullptr) {
            throw std::out_of_range( "Error: not within bounds!" );
        }

        // If the iterator is at begin: 1.push_front, 2.Return begin
        else if (position == mHead) {
            push_front(val);
            return begin();
        }

        //If the iterator is at end: 1.push_back, 2.Return iterator to last element (not end!)
        else if (position == mTail->mNext) {
            push_back(val);
            return --end();
        }

        else {
            // Make “before” and “after” pointers
            Node* before = position->mPrev;
            Node* after = position;

            //dynamically allocate a new node
            Node* newNode = new Node;
            //Set its data to the value
            newNode->mData = val;
            //Set its previous to before
            newNode->mPrev = before;
            //Set its next to after
            newNode->mNext = after;

            //Set before’s next to the new node
            before->mNext = newNode;
            after->mPrev = newNode;

            //Increment size
            mSize += 1;

            //Return an iterator pointing to the inserted node
            return Iterator(newNode);
        }

	}
    
public:
    // Function: Output Stream Operator
    // Purpose: Prints the contents of the list to the provided stream
    // Written in the format of {x, y, ..., z}
    // Input: Stream to write to, list to write
    // Output: Stream after values are written
    friend std::ostream& operator<<(std::ostream& os, const ITPDoubleList<T>& list)
    {
        Node* curr = list.mHead;
        // until we reach the tail, add the data
        while(curr != nullptr) {
            os << curr->mData;
            curr = curr->mNext;
        }
        return os;
    }
    
    // Function: toString
    // Purpose: Converts list to a string
    // Input: None
    // Output: String (in the format as the ostream)
    std::string toString() const
    {
        //use ostringstream so we can convert the stream to a string
        std::ostringstream os;

        os << "{";
        
        //start from the beginning
        Node* curr = mHead;
        // until we reach the tail, add the data
        while(curr != nullptr) {
            os << curr->mData;
            //until we reach the tail, we can add commas in between the values
            if(curr != mTail) {
                os << ",";
            }
            curr = curr->mNext;
        }
        
        os << "}";

		return os.str();
    }
    
    // Function: toReverseString
    // Purpose: Outputs the list in reverse
    // Input: None
    // Output: String in reverse
    std::string toReverseString() const
    {
        //use ostringstream so we can convert the stream to a string
        std::ostringstream os;
        
        os << "{";
        
        //start from the end
        Node* curr = mTail;
        // until we reach the head, add the data
        while(curr != nullptr) {
            os << curr->mData;
            //until we reach the head, we can add commas in between the values
            if(curr != mHead) {
                os << ",";
            }
            curr = curr->mPrev;
        }
        
        os << "}";
        
        return os.str();
    }
};
