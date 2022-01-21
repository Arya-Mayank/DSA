
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    // constructor
    Node(T d)
    {
        data = d;
    }
};

template <typename T>
class Stack
{
    Node<T> *head;

public:
    // constructor
    Stack()
    {
        head = nullptr;
    }

    void push(T d)
    {
        Node<T> *n = new Node<T>(d);
        n->next = head;
        head = n;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    T top()
    {
        return head->data;
    }

    void pop()
    {
        if (head != nullptr)
        {
            Node<T> *n = head;
            head = head->next;
            delete n;
        }
    }
};