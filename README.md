# Data Structures

 An all-in-one package of Data structures and algorithms for navigating them

 Developer's Note: Now I know that this project isn't a super exciting web app or game that can be interacted with, but as a programmer who is focused on backend development I thought that I would take some time to really learn and understand some of the most commonly used data structures and their respective navigation algorithms. All Data structures are built using template types so that they can be used with any data type or even custom types. 
 
 (To ensure that custom types work, it is reccommended that the comparison operators are overloaded)
 

 The structures present include the following:

 Dynamic Array
 Linked List
 Doubly-Linked-List
 Skip List

 Stack (list and array based)
 Queue (list and array based)
 Deque (list and array based)

 Hash Table (all collision methods: linear probing, quadratic probing, double hashing)

 Binary Tree
 AVL Tree
 Splay Tree
 Red-Back Tree

 Min Heap
 Max Heap

 Graphs (depth-first search, breadth first search, A*, Djikstra's)

## Dynamic Array

 A dynamic array is an array that will vary its size as elements are inserted and removed. By doubling the size of the array any time that too many elements are inserted, the dynamic array is able to run with an average time complexity of O(1). If the array did not double in size and instead simply grew 1 additional spot for each entry, the time complexity would be O(n) since every exisiting element would need to be copied every single time a new element was inserted.

 ### Methods for the Dynamic array
 
 Insert (void insert(T element)) - inserts an element at the end of the Dynamic Array. Resizes the array if the element would overflow the array

 Remove (void remove(int position)) - removes an element at a given position. Resizes the array if the number of elements decreases to 1/2 the size allocated

 Find (int find(T element)) - Finds the first instance of a given element. Returns the index of the first instance (requires data type T to have an overloaded == operator)

 Findall (DynamicArray\<int> findall(T element))- Finds all instances of a given element. Returns a Dynamic Array of the indices where the element is located (requires data type T to have an overloaded == operator)

 Access (via overloaded [] operator) - returns the value at a given position

 Print (via overloaded << operator) - prints all of the elements of the array in the format "{a, b, c}" (requires data type T to have an overloaded << operator)

 Copy (via overloaded = operator) - creates a deep copy of a Dynamic Array

 
 
