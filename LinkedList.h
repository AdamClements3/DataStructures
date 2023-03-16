#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//2 node classes (1 with just a pointer to next, one with pointer to prev)

//2 list classes (single and doubly linked)

//doubly needs a permanent head and tail node with no data

/* Methods
    insert front
    insert back
    remove front
    remove back
    swap nodes
    print
    deep copy
    comparison operators (nodes and full lists)
*/
template <typename T>
class singleNode{
    private:
        T data;
    public:
        singleNode* next;
        int pos;
        Node(T element){
            data = element;
        }
        void setData(T element){
            data = element
        }
        T getData(){
            return data;
        }
};

class SinglyLinkedList{
    private:
        singleNode* head;
        int length;
    public:
        SinglyLinkedList(){
            head = new singleNode(NULL);
            head->next = nullptr;
            head->pos = -1;
        }
        ~SinglyLinkedList(){

        }
        void insert(T element, int pos){

        }
        void remove(T element, int pos){

        }
        T get(int pos){

        }
        int size(){
            return length;
        }
}

#endif