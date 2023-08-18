#include <iostream>
#include <stdexcept>

template <typename T>
class MyVector {
public:
    MyVector();
    ~MyVector();

    const T& back() const;
    int getSize() const;
    bool isEmpty() const;

    void add(const T& value);

    MyVector(const MyVector& vec);
    MyVector& operator=(const MyVector& vec);

private:
    T* arr;
    int capacity;
    int vectorSize;
};

template <typename T>
MyVector<T>::MyVector() : arr(nullptr), capacity(0), vectorSize(0) {}

template <typename T>
MyVector<T>::~MyVector() {
    delete[] arr;
}

template <typename T>
const T& MyVector<T>::back() const {
    if (vectorSize > 0) {
        return arr[vectorSize - 1];
    }
    throw std::out_of_range("Vector is empty");
}

template <typename T>
int MyVector<T>::getSize() const {
    return vectorSize;
}

template <typename T>
bool MyVector<T>::isEmpty() const {
    return vectorSize == 0;
}

template <typename T>
void MyVector<T>::add(const T& value) {
    if (vectorSize >= capacity) {
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        T* newArr = new T[newCapacity];
        for (int i = 0; i < vectorSize; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }
    arr[vectorSize++] = value;
}

template <typename T>
MyVector<T>::MyVector(const MyVector& vec) : capacity(vec.capacity), vectorSize(vec.vectorSize) {
    arr = new T[capacity];
    for (int i = 0; i < vectorSize; ++i) {
        arr[i] = vec.arr[i];
    }
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& vec) {
    if (this != &vec) {
        delete[] arr;
        capacity = vec.capacity;
        vectorSize = vec.vectorSize;
        arr = new T[capacity];
        for (int i = 0; i < vectorSize; ++i) {
            arr[i] = vec.arr[i];
        }
    }
    return *this;
}

int main() {
    MyVector<int> myVec;
    myVec.add(5);
    myVec.add(10);
    myVec.add(15);

    std::cout << "Vector size: " << myVec.getSize() << std::endl;
    std::cout << "Last element: " << myVec.back() << std::endl;

    MyVector<int> myVecCopy = myVec;
    std::cout << "Copied vector size: " << myVecCopy.getSize() << std::endl;
    std::cout << "Last element of copied vector: " << myVecCopy.back() << std::endl;

    std::cout << "Is original vector empty? " << (myVec.isEmpty() ? "Yes" : "No") << std::endl;
    

    return 0;
}