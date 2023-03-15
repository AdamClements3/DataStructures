#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>

//Dynamic array implementation

template <typename T>
class DynamicArray{
    private:
        //array
        T* arr;
        //actual size
        int arrSize;
        //number of elements present
        int numElements;

        //function used to resize an array
        void resize(int option){
            if(option == 1){
                int newSize = arrSize*2;
                int *newArr = new T[newSize];
                for(int i=0;i<arrSize;i++){
                    newArr[i] = arr[i];
                }
                delete[] arr;
                arr = newArr;
                arrSize = newSize;
            }
            else{
                int newSize = arrSize/2;
                int *newArr = new T[newSize];
                for(int i=0;i<newSize;i++){
                    newArr[i] = arr[i];
                }
                delete[] arr;
                arr = newArr;
                arrSize = newSize;
            }
        }

        void mergeSort(T *A, int left, int right){
            if(left >= right){
                return;
            }
            int mid = (left + right)/2;
            mergeSort(A,left,mid);
            mergeSort(A,mid+1,right);
            merge(A, left, mid, right);
        }

        void merge(T *A, int left, int mid, int right){
            int i=left, k = left, j = mid + 1;
            T temp[numElements];
            while(i <= mid && j <= right){
                if(A[i] < A[j]){
                    temp[k] = A[i];
                    k++;
                    i++;
                }
                else{
                    temp[k] = A[j];
                    k++;
                    j++;
                }
            }
            while(i <= mid){
                temp[k] = A[i];
                k++;
                i++;
            }
            while(j <= right){
                temp[k] = A[j];
                k++;
                j++;
            }
            for(i = left;i<k;i++){
                A[i] = temp[i];
            }
        }

    public:

        //Constructor
        DynamicArray(){
            arr = new T[1];
            arrSize = 1;
            numElements = 0;
        }

        //Destructor
        ~DynamicArray(){
            delete[] arr;
        }

        //get number of elements in the array
        int size() const {
            return numElements;
        }

        //insert an element at the end of the array
        void insert(T element){
            if(numElements == arrSize){
                resize(1);
            }
            arr[numElements++] = element;
        }

        //remove an element (based on position)
        void remove(int pos){
            //create a new array and move all of the elements except for arr[pos] to the new array
            //don't worry about resizing on removal
            for(int i=0,j=0;i<numElements;i++,j++){
                if(i == pos){j++;}
                arr[i] = arr[j];
            }
            arr[numElements--] = 0;
            if(numElements == arrSize/2 && arrSize%2 == 0){
                resize(0);
            }
        }

        //performs a linear search to locate an element. Returns the index of the first instance of the element. if no instances are found, returns -1
        int find(T element){
            for(int i=0;i<numElements;i++){
                if(arr[i] == element){
                    return i;
                }
            }
            return -1;
        }

        //performs a linear search to locate an element. Returns a dynamic array of ALL indices of the instances of the element. If no instances are found, returns an empty dynamic array
        DynamicArray<int> findall(T element){
            DynamicArray<int> instances;
            for(int i=0;i<numElements;i++){
                if(arr[i] == element){
                    instances.insert(i);
                }
            }
            return instances;
        }

        //Merge sort
        void sort(){
            mergeSort(arr,0,numElements-1);
        }

        //get element at position
        T& operator[](int pos) const {
            if(pos > numElements){
                std::cerr << "The position entered is invalid: " << pos << 
                " is greater than the number of elements in the array (" 
                << numElements << ")" << std::endl;
            }
            else if(pos < 0){
                std::cerr << "The position entered is invalid: " << pos << " is less than 0";
            }
            return arr[pos];
        }

        DynamicArray<T>& operator=(const DynamicArray<T>& orig){
            for(int i=0;i<orig.size();i++){
                (*this).insert(orig[i]);
            }
            return *this;
        }

        //print out the values as a list
        friend std::ostream& operator<< (std::ostream& stream, const DynamicArray &array){
            stream << "{";
            for(int i=0;i<array.size();i++){
                if(i > 0){
                    stream << ", ";
                }
                stream << array[i];
            }
            stream << "}";
            return stream;
        }
};


#endif