//************************************************************
// Program #4 IntegerSet
// due 2/13/2025
// This program implements various set manipulation functions:
// - insert: Adds an element to the set
// - remove: Removes an element from the set
// - operator +: Union of two sets
// - operator *: Intersection of two sets
// - operator ==: Checks if two sets are equal
// - operator <: Checks if one set is a subset of another
// - operator <<: Prints the set
//************************************************************

#include <iostream>
using namespace std;

class IntegerSet {
private:
    // Using separate arrays to track what is in the set and total numbers
    bool* setArray;         // array showing numbers we have
    int* actualNumbers;     // array holding the actual numbers for easy printing
    int currentSize;        // how many numbers we actually have
    int arraySize;          // max size of our array
    
    // helper to count numbers in a set
    int countNumbers() {
        int count = 0;
        for(int i = 0; i < arraySize; i++) {
            if(setArray[i] == true) {
                count++;
            }
        }
        return count;
    }

public:
    // constructor 
    IntegerSet(int n) {
        arraySize = n + 1;
        currentSize = 0;
        setArray = new bool[arraySize];
        actualNumbers = new int[arraySize];
        
        // set everything to empty
        for(int i = 0; i < arraySize; i++) {
            setArray[i] = false;
            actualNumbers[i] = 0;
        }
    }

    // copy another set
    IntegerSet(const IntegerSet& other) {
        arraySize = other.arraySize;
        currentSize = other.currentSize;
        
        setArray = new bool[arraySize];
        actualNumbers = new int[arraySize];
        
        // copy both arrays
        for(int i = 0; i < arraySize; i++) {
            setArray[i] = other.setArray[i];
            actualNumbers[i] = other.actualNumbers[i];
        }
    }

    // cleanup
    ~IntegerSet() {
        delete[] setArray;
        delete[] actualNumbers;
    }

    // combine sets (union)
    IntegerSet operator+(const IntegerSet& other) {
        // make new set size of bigger array
        int maxSize = (arraySize > other.arraySize) ? arraySize : other.arraySize;
        IntegerSet combined(maxSize - 1);
        
        // first add all numbers from this set
        for(int i = 0; i < arraySize; i++) {
            if(setArray[i]) {
                combined.insert(i);
            }
        }
        
        // then add all numbers from other set
        for(int i = 0; i < other.arraySize; i++) {
            if(other.setArray[i]) {
                combined.insert(i);
            }
        }
        
        return combined;
    }

    // find shared numbers
    IntegerSet operator*(const IntegerSet& other) {
        // make new set size of smaller array we can not have more matches than smaller set
        int minSize = (arraySize < other.arraySize) ? arraySize : other.arraySize;
        IntegerSet shared(minSize - 1);
        
        // only add numbers that are in both sets
        for(int i = 0; i < minSize; i++) {
            if(setArray[i] && other.setArray[i]) {
                shared.insert(i);
            }
        }
        
        return shared;
    }

    // copy assignment
    IntegerSet& operator=(const IntegerSet& other) {
        if(this != &other) {
            // delete old arrays
            delete[] setArray;
            delete[] actualNumbers;
            
            // copy everything from other set
            arraySize = other.arraySize;
            currentSize = other.currentSize;
            
            setArray = new bool[arraySize];
            actualNumbers = new int[arraySize];
            
            for(int i = 0; i < arraySize; i++) {
                setArray[i] = other.setArray[i];
                actualNumbers[i] = other.actualNumbers[i];
            }
        }
        return *this;
    }

    // check if sets are equal
    bool operator==(const IntegerSet& other) {
        // if different sizes, not equal
        if(arraySize != other.arraySize) return false;
        if(currentSize != other.currentSize) return false;
        
        // check if all same numbers are present
        for(int i = 0; i < arraySize; i++) {
            if(setArray[i] != other.setArray[i]) {
                return false;
            }
        }
        return true;
    }

    // check if this set is inside another set
    bool operator<(const IntegerSet& other) {
        // get count of matching numbers
        int matches = 0;
        
        // check each number in our set
        for(int i = 0; i < arraySize; i++) {
            if(setArray[i]) {  // if we have this number
                // make sure other set has it too
                if(i >= other.arraySize || !other.setArray[i]) {
                    return false;
                }
                matches++;
            }
        }
        
        // we're a subset if all our numbers matched
        return matches == currentSize;
    }

    // add number to set
    void insert(int num) {
        if(num >= 0 && num < arraySize && !setArray[num]) {
            setArray[num] = true;
            actualNumbers[currentSize] = num;
            currentSize++;
        }
    }

    // remove number from set
    void remove(int num) {
        if(num >= 0 && num < arraySize && setArray[num]) {
            setArray[num] = false;
            
            // need to remove from actualNumbers too
            for(int i = 0; i < currentSize; i++) {
                if(actualNumbers[i] == num) {
                    // shift everything down
                    for(int j = i; j < currentSize - 1; j++) {
                        actualNumbers[j] = actualNumbers[j + 1];
                    }
                    break;
                }
            }
            currentSize--;
        }
    }

    // print the set
    friend ostream& operator<<(ostream& out, const IntegerSet& set) {
        if(set.currentSize == 0) {
            out << "---";
            return out;
        }
        
        // print using actualNumbers array for easier access
        for(int i = 0; i < set.currentSize; i++) {
            if(i > 0) {
                out << ", ";
            }
            out << set.actualNumbers[i];
        }
        return out;
    }
};

int main() {
    // make some test sets
    IntegerSet mySet1(5);   // can hold 0-5
    IntegerSet mySet2(3);   // can hold 0-3
    
    // test adding numbers
    mySet1.insert(1);
    mySet1.insert(3);
    mySet1.insert(5);
    cout << "Set1: " << mySet1 << endl;
    
    mySet2.insert(1);
    mySet2.insert(2);
    cout << "Set2: " << mySet2 << endl;
    
    // test operations
    cout << "Union (set1 + set2): " << (mySet1 + mySet2) << endl;
    cout << "Intersection (set1 * set2): " << (mySet1 * mySet2) << endl;
    
    // test subset
    cout << "\nIs set2 is subset of set1: ";
    if(mySet2 < mySet1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    // test remove
    mySet1.remove(1);
    cout << "Set1 after remove: " << mySet1 << endl;
    
    return 0;
}