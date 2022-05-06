#include <iostream> // print message
#include "myVector.h"

void print(const MyVector<int>& numbers) {
    for(int i = 0; i < 1; i++) std::cout << numbers[i] <<  " ";
    std::cout << std::endl;
    std::cout << std::endl;
}

int main() {
    MyVector<int> numbers;
    numbers.push_back(2);
    numbers.push_back(4);
    numbers.push_back(6);
    std::cout << numbers[0] << std::endl;
    std::cout << numbers[1] << std::endl;
    std::cout << numbers[2] << std::endl;
    return 0;
}

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
    delete [] array; // delete old slot
    array = tempArray;
    tempArray = nullptr;
    array[num++] = e;
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
    T* newArray = new T[--num];
    for(int i = 0; i < num; i++) newArray[i] = array[i];
    delete [] array; // delete the space associated with array
    array = newArray;
    newArray = nullptr;
}

template<class T> 
void MyVector<T>::insert(int index, const T& e) {
    if(index > num) {
        std::cout << "Invalid Index." << std::endl;
        return;
    }
    T temp;
    push_back(e);
    for(int i = num - 1; i > index; i--) {
        temp = array[i];
        array[i - 1] = array[i];
    }
   //for(int i = index + 1; i < num - 1; i++) *(tempArray + i + 1) = *(array + i);
}

template<class T> 
T MyVector<T>::displayElem(int index) const {
    return array[index];
}

template<class T> 
std::ostream& operator<<(std::ostream& out, const MyVector<T>& vec) {
    int index = 0;
    out << vec.array[index];
    return out;
}
template<class T> 
T& MyVector<T>::operator[](int index) const {
    return array[index];
}