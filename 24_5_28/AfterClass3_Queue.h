#include <iostream>

template <typename T>
class Queue {
public:
    Queue() : front_node(nullptr), back_node(nullptr), node_num(0) {}
    Queue(const Queue &another) : node_num(another.node_num) {
        back_node = front_node = new Node(another.front_node->element);
        for (Node *ano = another.front_node->next; ano; ano = ano->next) {
            Node *tmp = new Node(ano->element);
            back_node->next = tmp;
            back_node = tmp;
        }
    }
    ~Queue() {
        while (node_num--) {
            Node *tmp = front_node;
            front_node = front_node->next;
            delete tmp;
        }
    }
    bool empty() { return !node_num; }
    int size() { return node_num; }
    T front() const { if (node_num) return front_node->element; }
    T back() const { if (node_num) return back_node->element; }
    void push(T element) {
        if (! node_num) {
            front_node = back_node = new Node(element);
            ++node_num;
            return;
        }
        ++node_num;
        Node *tmp = new Node(element);
        back_node->next = tmp;
        back_node = tmp;
    }
    void pop() {
        if (node_num) {
            Node *tmp = front_node;
            front_node = front_node->next;
            delete tmp;
            --node_num;
        }
    }
    void swap(Queue &queue) {
        Node *frontTmp = front_node, *backTmp = back_node;
        int numTmp = node_num;

        front_node = queue.front_node,
        back_node = queue.back_node,
        node_num = queue.node_num;

        queue.front_node = frontTmp,
        queue.back_node = backTmp,
        queue.node_num = numTmp;
    }

private:
    struct Node {
        T element;
        Node *next;
        Node(T ele, Node *n = NULL) {
            element = ele;
            next = n;
        }
    };
    Node *front_node;
    Node *back_node;
    int node_num;
};