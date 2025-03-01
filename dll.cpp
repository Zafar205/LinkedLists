#include <bits/stdc++.h>
using namespace std;

class DLLNode
{
public:
    int value;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int x = 0)
    {
        next = nullptr;
        prev = nullptr;
        value = x;
    }
};

class DLL
{
public:
    DLLNode *head = nullptr;
    DLLNode *tail = nullptr;

    void insert(int index, int val)
    {
        DLLNode *new_node = new DLLNode(val);

        // If the list is empty
        if (head == nullptr)
        {
            head = tail = new_node;
            return;
        }

        // If inserting at the beginning
        if (index == 0)
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
            return;
        }

        // If inserting at the end
        if (index == size())
        {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
            return;
        }

        // Find the position for insertion
        int i = 0;
        DLLNode *temp = head;
        while (temp != nullptr && i < index)
        {
            temp = temp->next;
            ++i;
        }

        // If temp is null, the index is out of bounds
        if (temp == nullptr)
        {
            delete new_node;
            cout << "Index out of bounds" << endl;
            return;
        }

        // Insert the new node before temp
        new_node->next = temp;
        new_node->prev = temp->prev;
        temp->prev->next = new_node;
        temp->prev = new_node;
    }

    void remove(int index)
    {
        // If list is empty
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        // If removing the first node
        if (index == 0)
        {
            DLLNode *temp = head;
            head = head->next;
            
            // If list becomes empty after deletion
            if (head == nullptr)
                tail = nullptr;
            else
                head->prev = nullptr;
                
            delete temp;
            return;
        }

        // If removing the last node
        if (index == size() - 1)
        {
            DLLNode *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            return;
        }

        // Find the node to be deleted
        int i = 0;
        DLLNode *temp = head;
        while (temp != nullptr && i < index)
        {
            temp = temp->next;
            ++i;
        }

        // If temp is null, the index is out of bounds
        if (temp == nullptr)
        {
            cout << "Index out of bounds" << endl;
            return;
        }

        // Remove the node
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    // Get the size of the list
    int size()
    {
        int count = 0;
        DLLNode *temp = head;
        while (temp != nullptr){
            count++;
            temp = temp->next;
        }
        return count;
    }

    void print()
    {
        DLLNode *temp = head;
        cout << "Forward: ";
        while (temp != nullptr)
        {
            cout << temp->value;
            if (temp->next != nullptr)
                cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;

        // Print in reverse to verify doubly linked nature
        cout << "Reverse: ";
        temp = tail;
        while (temp != nullptr)
        {
            cout << temp->value;
            if (temp->prev != nullptr)
                cout << " <-> ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main()
{
    DLL list;
    
    // Test insertion
    list.insert(0, 1);  // Insert 1 at beginning
    list.print();
    
    list.insert(1, 3);  // Insert 3 at end
    list.print();
    
    list.insert(1, 2);  // Insert 2 in middle
    list.print();
    
    list.insert(0, 0);  // Insert 0 at beginning
    list.print();
    
    list.insert(4, 4);  // Insert 4 at end
    list.print();
    
    // Test removal
    list.remove(0);     // Remove first (0)
    list.print();
    
    list.remove(2);     // Remove from middle (3)
    list.print();
    
    list.remove(2);     // Remove from end (4)
    list.print();
    
    return 0;
}