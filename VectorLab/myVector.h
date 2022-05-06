#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>
template<class T> 
class MyVector {
friend std::ostream& operator<<(std::ostream& out, const MyVector<T>& vec) {
    int index = 0;
    out << vec.array[index] << " ";
    out << endl;
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
    T displayElem(int index) const;
    //std::ostream& operator<<(std::ostream& out);
    T operator[](int index) const;
};

template<class T>
MyVector<T>::MyVector() {
    array = NULL;
    num = 0;
}

template<class T>
MyVector<T>::~MyVector() {
    if(array != NULL) delete [] array;
}

template<class T>
void MyVector<T>::push_back(const T& e) {
    T *tempArray = new T[num + 1]; // 1 size
    for(int i = 0; i < num; i++) *(tempArray + i) = *(array + i); // copy over the elements // loop will not go through
    delete [] array; // clear the memory block of array
    array = tempArray; 
    tempArray = NULL; // 
    array[num++] = e; // set the new value and increment the number of elements
}

template<class T> 
int MyVector<T>::size() const{
    return num;
}

template<class T> 
void MyVector<T>::erase(int index) {
    if(index >= num) { // >= because the size is +1 of the valid index
        std::cout << "Illegal Index" << std::endl;
        return;
    }
    int j = 0;
    T* tempArray = new T[num - 1]; // create new array with original size - 1
    for(int i = 0; i < num; i++) {
        if(i == index) continue; // break one loop iteration
        *(tempArray + j++) = *(array + i);
    }
    delete [] array; // delete the space associated with array
    array = tempArray;
    tempArray = NULL;
    num--; // decrement
}

template<class T> 
void MyVector<T>::insert(int index, const T& e) {
    if(index > num) {
        std::cout << "Illegal Index." << std::endl;
        return;
    }
    else if(index == num) {
        push_back(e);
        return;
    } // if we are inserting element to the last index then we just push it back
    T* tempArray = new T [num + 1];

    int j = 0;
    for(int i = 0; i < num; i++) {
        if(i == index) {
            *(tempArray + j) = e;
            j++;
        }
        *(tempArray + j) = *(array + i);
        j++;
    }
    num++; // increment num after completing the function
    delete [] array;
    array = tempArray;
    tempArray = NULL;
}

template<class T> 
T MyVector<T>::displayElem(int index) const {
    return array[index];
}
template<class T> 
T MyVector<T>::operator[](int index) const {
    if(index < num) return *(array + index);
    exit(1);
}

#endif