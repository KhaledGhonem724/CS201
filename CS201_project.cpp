#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
struct dnode {
    int data;
    dnode* next;
    dnode* pre;
};
class Array {
    int size;
    int length;
    int* arr;
public:
    Array(int a) {
        if (a <= 0) {
            size = 10;
            length = 0;
            arr = new int[size];
            cout << "invalid size : size was set to defaulte value of 10\n";
        }
        else {
            size = a;
            length = 0;
            arr = new int[size];
        }
    }
    bool isempty() {
        return length == 0;
    }
    bool isfull() {
        return length >= size;
    }
    int getlength() {
        return length;
    }
    int getsize() {
        return size;
    }
    void Enlarge(int added_size) {
        int* temp = new int[size + added_size];
        for (int i = 0; i < length; i++) {
            temp[i] = arr[i];
        }
        arr = temp;
        size = size + added_size;
    }
    void Sort() {
        for (int i = 0; i < length; i++)
        {
            for (int j = i + 1; j < length; j++)
            {
                if (arr[i] > arr[j]) {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
    void Display() {
        for (int i = 0; i < length; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    void insert(int newitem) {
        if (isfull())
        {
            cout << "Array is Full\n";
            exit(1);
        }
        else {
            arr[length] = newitem;
            length++;
        }
    }
    void insertByindex(int newitem, int index) {
        if (isfull()) {
            cout << "Array is Full\n";
            exit(1);
        }
        else if(index >= 0 && index <= length) {
            for (int i = length; i > index; i--) {
                arr[i] = arr[i - 1];
            }
            arr[index] = newitem;
            length++;
        }
        else if (index > length)
        {
            insert(newitem);
        } else {
            cout << "out of range" << endl;
            exit(1);
        }
    }
    void DeletionByIndex(int index) {
        if (index >= 0) {
            for (int i = index; i < length - 1; i++) {
                arr[i] = arr[i + 1];
            }
            length--;
        }
        else {
            cout << "out of range" << endl;
            exit(1);
        }
    }
    void DeletionByValue(int val) {//added
        for (int i = 0; i < length; i++) {
            if (arr[i] == val)
            {
                for (int j = i; j < length - 1; j++)
                {
                    arr[j] = arr[j + 1];
                }
                length--;
                return;
            }
        }
    }
};
class Stack {
private:
    node* top;
public:
    Stack() {
        top = NULL;
    }
    void Push(int val) {
        node* temp = new node();
        temp->data = val;
        top == NULL ? temp->next = NULL : temp->next = top;
        top = temp;
    }
    void Pop() {
        if (IsEmpyt()) {
            cout << "Stack empty before Pop\n";
            exit(1);
        }
        node* temp = top;
        top = top->next;
        free(temp);
    }
    int Peek() {
        if (IsEmpyt()) {
            cout << "Stack empty before Peek\n";
            exit(1);
        }
        return top->data;
    }
    bool IsEmpyt() {
        return top == NULL;
    }
    void Display() {
        if (IsEmpyt())
        {
            cout << "\n";
            return;
        }
        node* i = top;
        while (i->next != NULL) {
            cout << i->data << " ";
            i = i->next;
        }
        cout << i->data << "\n";
    }
};
class Queue {
private:
    node* front;
    node* rear;
public:
    Queue() {
        front = NULL;// like head
        rear = NULL;// like tail
    }
    void enqueue(int val) {
        node* temp = new node();
        temp->data = val;
        temp->next = NULL;
        if (IsEmpty()) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    void dequeue() {
        if (IsEmpty())
        {
            cout << "Queue empty before dequeue\n";
            exit(1);
        }
        if (front->next == NULL)
        {
            front = rear = NULL;
            return;
        }
        node* temp = front;
        front = front->next;
        free(temp);
    }
    int getfront() {
        if (IsEmpty()) {
            cout << "Queue empty before getfront\n";
            exit(0);
        }
        return front->data;
    }
    bool IsEmpty() {
        return front == NULL;
    }
    void display() {
        if (IsEmpty())
        {
            cout << "\n";
            return;
        }
        node* i = front;
        while (i->next != NULL) {
            cout << i->data << " ";
            i = i->next;
        }
        cout << i->data << "\n";
    }
};
class DoubleQueue {
private:
    dnode* front;
    dnode* rear;
public:
    DoubleQueue() {
        front = NULL;// like head
        rear = NULL;// like tail
    }
    void enqueue(int val) {
        dnode* temp = new dnode();
        temp->data = val;
        temp->next = NULL;
        temp->pre = NULL;
        if (isEmpty())
        {
            front = rear = temp;
            return;
        }
        temp->pre = rear;
        rear->next = temp;
        rear = temp;
    }
    void dequeue() {
        if (isEmpty())
        {
            cout << "doubleQueue empty before dequeue\n";
            exit(1);
        }
        if (front->next == NULL)
        {
            front = rear = NULL;
            return;
        }
        dnode* temp = front;
        front = front->next;
        front->pre = NULL;
        free(temp);
    }
    int getfront() {
        if (isEmpty()) {
            cout << "doubleQueue empty before getfront\n";
            exit(1);
        }
        return front->data;
    }
    bool isEmpty() {
        return front == NULL;
    }
    void display() {
        if (isEmpty()) {
            cout << "\n";
            return;
        }
        dnode* i = front;
        while (i->next != NULL) {
            cout << i->data << " ";
            i = i->next;
        }
        cout << i->data << "\n";
    }
};
class CircularQueue {
private:
    node* front;
    node* rear;
public:
    CircularQueue() {
        front = NULL;// like head
        rear = NULL;// like tail
    }
    void enqueue(int val) {
        node* temp = new node();
        temp->data = val;
        temp->next = front;
        if (IsEmpty()) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    void dequeue() {
        if (IsEmpty())
        {
            cout << "circularQueue empty before dequeue\n";
            exit(1);
        }
        if (front->next == front)
        {
            front = rear = NULL;
            return;
        }
        node* temp = front;
        rear->next = front->next;
        front = front->next;
        free(temp);
    }
    int getfront() {
        if (IsEmpty()) {
            cout << "circularQueue empty before getfront\n";
            exit(0);
        }
        return front->data;
    }
    bool IsEmpty() {
        return front == NULL;
    }
    void display() {
        if (IsEmpty())
        {
            cout << "\n";
            return;
        }
        node* i = front;
        while (i->next != front) {
            cout << i->data << " ";
            i = i->next;
        }
        cout << i->data << "\n";
    }
};
class LinkedList {
private:
    node* head, * tail;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }
    void insert_first(int value)
    {
        node* temp = new node;
        temp->data = value;
        if (IsEmpty())
        {
            temp->next = NULL;
            head = tail = temp;
            return;
        }
        temp->next = head;
        head = temp;
    }
    void insert_last(int value) {
        node* temp = new node;
        temp->data = value;
        temp->next = NULL;
        if (IsEmpty())
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    void insertByPosition(int value, int pos) {
        if (pos == 0 || IsEmpty())
        {
            insert_first(value);
            return;
        }
        node* prev = new node;
        node* current = new node;
        node* temp = new node;
        current = head;
        for (int i = 1; i <= pos; i++) {
            if (current == tail)
            {
                insert_last(value);
                return;
            }
            prev = current;
            current = current->next;
        }
        temp->data = value;
        prev->next = temp;
        temp->next = current;
    }
    void delete_first() {
        node* temp = new node;
        temp = head;
        head = head->next;
        delete temp;
    }
    void delete_last() {
        node* current = new node;
        node* prev = new node;
        current = head;
        while (current != tail)
        {
            prev = current;
            current = current->next;
        }
        tail = prev;
        prev->next = NULL;
        free(current);
    }
    void deleteByPosition(int pos) {
        if (pos == 0)
        {
            delete_first();
            return;
        }
        node* current = new node;
        node* prev = new node;
        current = head;
        for (int i = 0; i < pos; i++)
        {
            if (current == tail)
            {
                delete_last();
                return;
            }
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
    }
    void display() {
        node* temp = new node;
        temp = head;
        while (temp != tail) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << "\n";
    }
    bool IsEmpty() {
        return head == NULL;
    }
};
class CircularLinkedList {
private:
    node* head, * tail;
public:
    CircularLinkedList() {
        head = NULL;
        tail = NULL;
    }
    void insert_last(int value) {
        node* temp = new node;
        temp->data = value;
        if (IsEmpty()) {
            temp->next = temp;
            tail = head = temp;
        }
        else {
            temp->next = head;
            tail->next = temp;
            tail = temp;
        }
    }
    void insert_first(int value) {
        node* temp = new node;
        temp->data = value;
        if (IsEmpty()) {
            temp->next = temp;
            tail = head = temp;
        }
        else {
            temp->next = head;
            tail->next = temp;
            head = temp;
        }
    }
    void insertByPosition(int value, int pos) {
        if (pos == 0 || IsEmpty()) {
            insert_first(value);
            return;
        }
        node* prev = new node;
        node* current = new node;
        node* temp = new node;
        current = head;
        for (int i = 1; i <= pos; i++) {
            if (current == tail)
            {
                insert_last(value);
                return;
            }
            prev = current;
            current = current->next;
        }
        temp->data = value;
        prev->next = temp;
        temp->next = current;
    }
    bool IsEmpty() {
        return head == NULL;
    }
    void deleteByValue(int value) {
        node* temp = new node;
        node* i = new node;
        i = head;
        if (tail->next == tail && tail->data == value)
        {
            temp = tail;
            tail = NULL;
            free(temp);
            return;
        }
        if (i->data == value && i == head)
        {
            temp = i;
            tail->next = i->next;
            free(temp);
            return;
        }
        while (i->next != tail)
        {
            if (i->next->data == value)
            {
                temp = i->next;
                i->next = temp->next;
                free(temp);
                return;
            }
            i = i->next;
        }
        if (i->next->data == value)
        {
            temp = i->next;
            i->next = tail->next;
            free(temp);
            tail = i;
            return;
        }
    }
    void display() {
        if (IsEmpty())
        {
            cout << "\n";
            return;
        }
        node* i = new node;
        i = head;
        while (i != tail)
        {
            cout << i->data << " ";
            i = i->next;
        }
        cout << i->data << "\n";
    }
};
class DoubleLinkedList {
private:
    dnode* head;
    dnode* tail;
public:
    DoubleLinkedList() {
        head = NULL;// like head
        tail = NULL;// like tail
    }
    void insert_last(int val) {
        dnode* temp = new dnode();
        temp->data = val;
        temp->next = NULL;
        temp->pre = NULL;
        if (IsEmpty())
        {
            head = tail = temp;
            return;
        }
        temp->pre = tail;
        tail->next = temp;
        tail = temp;
    }
    void insert_first(int val) {
        dnode* temp = new dnode();
        temp->data = val;
        temp->next = NULL;
        temp->pre = NULL;
        if (IsEmpty())
        {
            head = tail = temp;
            return;
        }
        temp->next = head;
        head->pre = temp;
        head = temp;
    }
    void insertByPosition(int value, int pos) {
        if (pos == 0 || IsEmpty()) {
            insert_first(value);
            return;
        }
        dnode* prev = new dnode;
        dnode* current = new dnode;
        dnode* temp = new dnode;
        current = head;
        for (int i = 1; i <= pos; i++) {
            if (current == tail)
            {
                insert_last(value);
                return;
            }
            prev = current;
            current = current->next;
        }
        temp->data = value;
        temp->next = current;
        temp->pre = prev;
        current->pre = temp;
        prev->next = temp;

    }
    void deleteByValue(int value) {
        if (IsEmpty())
        {
            cout << "doubly Linked List empty before dequeue\n";
            exit(1);
        }
        dnode* temp = new dnode;
        if (head->next == NULL && head->data == value)
        {
            temp = head;
            free(temp);
            head = tail = NULL;
            return;
        }
        if (tail->data == value)
        {
            temp = tail;
            tail = tail->pre;
            tail->next = NULL;
            free(temp);
            return;
        }
        dnode* i = new dnode;
        i = head;
        while (i->next != tail)
        {
            if (i->next->data == value)
            {
                temp = i->next;
                temp->next->pre = i;
                i->next = temp->next;
                free(temp);
                return;
            }
            i = i->next;
        }

    }
    bool IsEmpty() {
        return head == NULL;
    }
    void display() {
        if (IsEmpty()) {
            cout << "\n";
            return;
        }
        dnode* i = head;
        while (i->next != NULL) {
            cout << i->data << " ";
            i = i->next;
        }
        cout << i->data << "\n";
    }
};
class DoubleCircularLinkedList {
private:
    dnode* head;
    dnode* tail;
public:
    DoubleCircularLinkedList() {
        head = NULL;// like head
        tail = NULL;// like tail
    }
    void insert_last(int val) {
        dnode* temp = new dnode();
        temp->data = val;
        temp->next = NULL;
        temp->pre = NULL;
        if (IsEmpty())
        {
            head = tail = temp;
            return;
        }
        temp->pre = tail;
        tail->next = temp;
        temp->next = head;
        head->pre = temp;
        tail = temp;
    }
    void insert_first(int val) {
        dnode* temp = new dnode();
        temp->data = val;
        temp->next = NULL;
        temp->pre = NULL;
        if (IsEmpty())
        {
            head = tail = temp;
            return;
        }
        temp->pre = tail;
        tail->next = temp;
        temp->next = head;
        head->pre = temp;
        head = temp;
    }
    void insertByPosition(int value, int pos) {
        if (pos == 0 || IsEmpty()) {
            insert_first(value);
            return;
        }
        dnode* prev = new dnode;
        dnode* current = new dnode;
        dnode* temp = new dnode;
        current = head;
        for (int i = 1; i <= pos; i++) {
            if (current == tail)
            {
                insert_last(value);
                return;
            }
            prev = current;
            current = current->next;
        }
        temp->data = value;
        temp->next = current;
        temp->pre = prev;
        current->pre = temp;
        prev->next = temp;
    }
    void deleteByValue(int value) {
        if (IsEmpty())
        {
            cout << "doubly Linked List empty before dequeue\n";
            exit(1);
        }
        dnode* temp = new dnode;
        if (head->next == NULL && head->data == value)
        {
            temp = head;
            free(temp);
            head = tail = NULL;
            return;
        }
        if (tail->data == value)
        {
            temp = tail;
            tail = tail->pre;
            tail->next = head;
            free(temp);
            return;
        }
        dnode* i = new dnode;
        i = head;
        while (i->next != tail)
        {
            if (i->next->data == value)
            {
                temp = i->next;
                temp->next->pre = i;
                i->next = temp->next;
                free(temp);
                return;
            }
            i = i->next;
        }

    }
    bool IsEmpty() {
        return head == NULL;
    }
    void display() {
        if (IsEmpty()) {
            cout << "\n";
            return;
        }
        dnode* i = head;
        while (i->next != head) {
            cout << i->data << " ";
            i = i->next;
        }
        cout << i->data << "\n";
    }
};
int main() {

}




