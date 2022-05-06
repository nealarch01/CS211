#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>
#include <cstdlib>
template<class T> 
class MyVector {
friend std::ostream& operator<<(std::ostream& out, const MyVector<T>& vec) {
    int index = 0;
    out << vec.array[index];
    return out;
}
private:
    T *array;
    int num; // number of elements in the array
public:
    MyVector(); // default constructor
    ~MyVector(); // destructor 
    void push_back(const T& e);
    int size() const;
    void erase(int index);
    void insert(int index, const T& e);
    T& operator[](int index);
};
/*********************************************
Default constructor, when vector object is
instantitaed, there will be no array and the
number of elements / size of vector is 0
*********************************************/
template<class T>
MyVector<T>::MyVector() {
    array = NULL;
    num = 0;
}
/*********************************************
destructor to delete the entire array when
vector object goes out of scope
*********************************************/
template<class T>
MyVector<T>::~MyVector() {
    if(array != NULL) delete [] array; // if array is not pointing to NULL
    // delete the entire array
}
/*********************************************
Function is going to push back one element in
the vector and increment its size

e is the element we are going to push back
const since we are not changing it
pass by reference since it may be a large 
object
*********************************************/
template<class T>
void MyVector<T>::push_back(const T& e) {
    T *tempArray = new T[num + 1]; // 1 size
    for(int i = 0; i < num; i++) *(tempArray + i) = *(array + i); // copy over the elements // loop will not go through
    delete [] array; // delete old array
    array = tempArray; // point the array to the newly created array 
    tempArray = NULL; // point tempArray to null so we will only have one pointer
    array[num++] = e; // set current index to new element and increment the array size by one
}
/*********************************************
Function will return the current size
 of the array
*********************************************/
template<class T> 
int MyVector<T>::size() const{
    return num;
}
/*********************************************
This function is going to erase the element at 
a certain index
int index is the index of vector we are erasing
*********************************************/
template<class T> 
void MyVector<T>::erase(int index) {
    if(index >= num) { // >= because the size is +1 of the valid index therefore illegal index
        std::cout << "Illegal Index" << std::endl;
        return;
    }
    int j = 0; // counter for second (smaller array)
    T* tempArray = new T[num - 1]; // create new array with original size - 1
    // loop through and read the elements of the old array
    for(int i = 0; i < num; i++) { 
        if(i == index) continue; // skip reading the element at the certain index by breaking one loop iteration
        *(tempArray + j++) = *(array + i); // transfer the rest of the following contents to the new array
    }
    delete [] array; // delete the space associated with array
    array = tempArray;
    tempArray = NULL;
    num--; // decrement
}

/*********************************************
Function will insert two elemnts into the 
vector by traversing the original loop. Once
we encounter the index of the item we will 
increment the second loop counter which makes
new array larger by 1
If the index inserted is to the end, we will
just call push back function and return
**********************************************/
template<class T> 
void MyVector<T>::insert(int index, const T& e) {
    if(index > num) { // if index parameter is greater than the size of array
        std::cout << "Illegal Index." << std::endl; // send illegal index message
        return; // and return back to function
    }    
    else if(index == num) { // if the user wants to insert an element at the end of the vector just call the push_back function
        push_back(e); // push back the element
        return; // return
    }
    T* tempArray = new T [num + 1]; // create a new dynamic memory in heap and make it larger by one

    int j = 0; // tempArray index counter
    // Loop through the old array and copy its values. 
    // Once we reach the index insertion point, we will add the new element and increment j 
    // so we can access the right index of the larger array
    for(int i = 0; i < num; i++) {
        if(i == index) { // check if we are at the insertion point
            *(tempArray + j) = e; // assign e to index
            j++; // increment j so we can assign the right index of new array
        }
        *(tempArray + j) = *(array + i); // copy the values from old array to new array
        j++; // increment new array index counter by one
    }
    num++; // increment num after completing the function
    delete [] array; // delete the data in old array
    array = tempArray; // point old array to the new array
    tempArray = NULL; // point tempArray back to NULL so we will only have one pointer left
}
/*********************************************
This function is going to overloaded the index
operator function so we can access a certain
index of the vector

int index is the index of the array to be 
accessed
*********************************************/
template<class T> 
T& MyVector<T>::operator[](int index) {
    if(index < num) return *(array + index); // if the index is valid then we return whatever value
    std::cout << "Invalid Index" << std::endl; // otherwise its an invalid index
    exit(1); // exit with errors, not using throw because we need catch
}

#endif
