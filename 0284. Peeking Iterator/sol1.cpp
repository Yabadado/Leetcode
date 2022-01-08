/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    peaked = false;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        int ret ;
        if(!peaked){
            num = Iterator::next();
            ret = num;
        }
        ret = num;
        peaked = true;
        
        return ret;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int ret;
	    if(peaked)
            ret = num;
        else
            num = Iterator::next();
        peaked = false;
        return ret;
	}
	
	bool hasNext() const {
	    return peaked || Iterator::hasNext();
	}
private:
    int num;
    bool peaked;
};