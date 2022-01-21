#include <iostream>
using namespace std;
class List;

class Node
{

public:
    int data;
    Node *next;
    // friend class List;
    // constructor
    Node(int d) : data(d), next(nullptr){};

    // getter
    int getData()
    {
        return data;
    }

    Node *getNext()
    {
        return next;
    }

    // destructor
    // ~Node()
    // {
    //     if (next != nullptr)
    //     {
    //         delete next;
    //     }
    // }
};

class List
{
    Node *head;
    Node *tail;

public:
    // constructor
    List() : head(nullptr), tail(nullptr){};

    // getter
    Node *begin()
    {
        return head;
    }

    Node *end()
    {
        return tail;
    }

    // setter
    void setHead(Node *temp)
    {
        head = temp;
    }

    void push_front(int data)
    {
        // if LL empty
        if (head == nullptr)
        {
            Node *n = new Node(data);
            head = tail = n;
        }
        // if elements already present
        else
        {
            Node *n = new Node(data);
            n->next = head;
            head = n;
        }
    }

    void push_back(int data)
    {
        if (head == nullptr)
        {
            Node *n = new Node(data);
            head = tail = n;
        }

        else
        {
            Node *n = new Node(data);
            tail->next = n;
            tail = n;
        }
    }

    void insert(int data, int position)
    {
        // position = 0 == inserting at head
        if (position == 0)
        {
            push_front(data);
            return;
        }

        // otherwise
        Node *temp = head;
        for (int jump = 1; jump <= position - 1; jump++)
        {
            temp = temp->next;
        }

        Node *n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }

    void search(Node *head, int key)
    {
        Node *temp = head;

        int position = 0;
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                cout << "Element found at index " << position;
                return;
            }
            position++;
            temp = temp->next;
        }

        cout << "No element found";
        return;
    }

    bool searchRecursive(Node *head, int key)
    {
        if (head == nullptr)
        {
            return false;
        }

        if (head->data == key)
        {
            return true;
        }

        else
        {
            return searchRecursive(head->next, key);
        }
    }

    void pop_front()
    {
        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }

    void pop_back(Node *head)
    {
        if (head == nullptr)
        {
            return;
        }

        Node *secondLast = head;
        while (secondLast->next->next != nullptr)
        {
            secondLast = secondLast->next;
        }

        delete secondLast->next;

        secondLast->next = nullptr;
    }

    void deletePos(Node *head, int position)
    {
        // reach position
        Node *temp = head;
        for (int j = 1; j <= position; j++)
        {
            temp = temp->getNext();
        }

        Node *it = head;

        while (it->next != temp)
        {
            it = it->next;
        }

        it->next = temp->next;
        delete temp;
        temp = nullptr;
    }

    void delIndex(Node *head, int index)
    {
        Node *temp = head;

        while (index > 1)
        {
            temp = temp->next;
            index--;
        }

        Node *nbr = temp->next;
        temp->next = nbr->next;
        delete nbr;
        nbr = nullptr;
    }

    void display()
    {
        while (head != nullptr)
        {
            cout << head->getData() << "-> ";
            head = head->getNext();
        }
        return;
    }

    void reverse(Node *start)
    {
        Node *current = head;
        Node *prev = nullptr;

        Node *temp;

        while (current != nullptr)
        {
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }

        head = prev;
    }

    int kthLast(Node *head, int k)
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            Node *temp2 = temp;

            for (int i = 0; i < k - 1; i++)
            {
                temp = temp->next;
            }

            if (temp->next == nullptr)
            {
                // cout << temp2->getData();
                return temp2->getData();
            }
            else
            {
                temp = temp2;
            }

            temp = temp->next;
        }

        return -1;
    }

    // destructor`
    ~List()
    {
        if (head != nullptr)
        {
            delete head;
            head = nullptr;
        }
    }
};

Node *alternateMerge(Node *root1, Node *root2)
{
    Node *temp1 = root1;
    Node *temp2 = root2;

    Node *t1n;
    Node *t2n;

    while (temp1 != nullptr && temp2 != nullptr)
    {
        t1n = temp1->next;
        t2n = temp2->next;

        temp1->next = temp2;
        temp2->next = t1n;
        temp1 = t1n;
        temp2 = t2n;
    }

    return root1;
}

Node *bubbleSort(Node *head)
{

    for (int j = 0; j < 4; j++)
    {
        Node *current = head;
        Node *prev = nullptr;
        
        for(int i=0;i<4;i++){

            Node *n = current->next;

            if (current->data > n->data)
            {
                Node *t1 = prev->next;
                Node *t2 = n->next;

                prev->next = current->next;
                n->next = t1;
                current->next = t2;
            }

            prev = current;
            current = n;
            
        }
    }

    return head;
}