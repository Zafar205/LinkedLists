#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int val = 0)
    {
        next = nullptr;
        value = val;
    }
};
class SLL
{
public:
    Node *head = nullptr;
    Node *tail = nullptr;

    void insert(int index, int val)
    {

        Node *node = new Node(val);

        if (index == 0)
        {
            node->next = head;
            head = node;
            return;
        }

        if (head == nullptr)
        {
            head = node;
            tail = node;
            return;
        }

        int i = 0;
        Node *temp = head;

        while (temp != nullptr && i < index - 1)
        {
            temp = temp->next;
            ++i;
        }

        node->next = temp->next;
        temp->next = node;

        if (node->next == nullptr)
            tail = node;
    }

    void remove(int index)
    {
        if (head == nullptr)
        {
            cout << "EMPTY";
            return;
        }

        if (index == 0)
        {
            Node *temp = head;
            head = head->next;
            delete temp;

            return;
        }

        int i = 0;
        Node *temp = head;
        while (temp != nullptr && i < index - 1)
        {
            temp = temp->next;
            ++i;
        }

        Node *to_delete = temp->next;
        temp->next = to_delete->next;

        if (to_delete == tail)
        {
            tail = temp;
        }

        delete to_delete;
    }

    void print()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << '\n';
    }
};

void reverse(SLL& list) {
    if (list.head == nullptr || list.head->next == nullptr) {
        // Empty list or single node - no need to reverse
        return;
    }
    
    Node* prev = nullptr;
    Node* current = list.head;
    Node* next = nullptr;
    
    // Save original head to become new tail
    Node* new_tail = list.head;
    
    while (current != nullptr) {
        // Store next node
        next = current->next;
        
        // Reverse the link
        current->next = prev;
        
        // Move pointers one step forward
        prev = current;
        current = next;
    }
    
    // Update head and tail
    list.tail = new_tail;
    list.head = prev;
}

int main()
{
    SLL list;
    list.insert(0, 1);
    list.insert(0, 2);
    list.insert(0, 3);
    list.insert(0, 4);
    list.insert(1, 999);
    list.print();
    list.remove(1);
    list.print();
    list.remove(3);
    list.print();

    return 0;
}