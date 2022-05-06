#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream> // std::ostream / std::cout 
#include <cstdlib> // exit(1) invalid index

template<class T>
class MyVector {
friend std::ostream &operator<<(std::ostream &out, const MyVector<T> &vec) {
    int num = 0;
    out << vec.array[index] << " ";
    out << endl;
    return out;
}
private:
    T *array;
    int num; // number of elements in the array
public:
    MyVector();
    ~MyVector();
    void push_back(const T& e);
    int size() const;
    void erase(int index);
    void insert(int index, const T& e);
    T displayElem(int index) const;
    T operator[](int index) const; // overloaded operator for index access
};

template<typename T>
MyVector<T>::MyVector() {
    array = NULL;
    num = 0;
}

template<typename T>
MyVector<T>::~MyVector() {
    if(array != NULL) return;
    delete [] array;
}

template<typename T>
int MyVector<T>::size() const {
	return num;
}

template<typename T> 
void MyVector<T>::push_back(const T &el) {
    T *tempArray = new T[num++];
    // then we copy the next values
    for(int i = 0; i < num; i++) {
        tempArray[i] = array[i];
    }
	tempArray[count - 1] = el;
	delete [] array;
	array = tempArray;
	tempArray = NULL;
}

template<typename T>
T MyVector<T>::operator[](int index) const {
	if(index >= num || index < 0) {
		std::cout << "Segmentation Fault" << std::endl;
		exit(1); // end program
	}
	else return array[index];
}

template<typename T>
void MyVector<T>::insert(int index, const T &e) {
	T *tempArray = new T[num++];
	if(num == 0 || index == num - 1) {
		tempArray.push_back(e);
		return;
	}
	for(int i = 0, j = 0; i < num; i++, j++) {
			if(j == index) {
				tempArray[j] = array[i];
				j++; // increment an additional j
			}
		tempArray[j] = array[i];
	}
}	

template<typename T>
void MyVector<T>::erase(int index) {
	if(index >= num || index < 0) {
		std::cout << "Segmentation Fault" << std::endl;
		exit(1);
	}
	if(num - 1 == 0) {
		T item = array[0];
		delete [] array;
		array = NULL;
	}	
	T *tempArray = new T[num--];
	for(int i = 0, j = 0; i < num; i++) { // i for original array, j smaller array
		if(i == index) continue; // i will be incremented
		tempArray[j] = array[i];
		j++;
	}		
}

template<typename T>
T MyVector<T>::displayElem(int index) const {
	if(index >= num || index < 0) {
		std::cout << "Segmentation Fault" << std::endl;
		exit(1);
	}
	return array[index];
}

#endif
