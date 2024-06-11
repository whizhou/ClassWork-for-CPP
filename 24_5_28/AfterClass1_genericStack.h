template <typename ElementType> // genericStack.h
class Stack
{
public:
    Stack() : top(nullptr) {}
    ~Stack() {
        while (top) {
            auto tmp = top;
            top = top->next;
            delete tmp;
        }
    }
    void push(ElementType obj) {
        auto tmp = new Node{obj, top};
        top = tmp;
    } // 将新元素入栈
    void pop() {
        if (top) {
            auto tmp = top;
            top = top->next;
            delete tmp;
        }
    }                 // 将栈顶元素出栈
    ElementType getTop() const {
        if (top) return top->element;
    } // 返回栈顶元素
    bool isEmpty() const { return !top; }       // 判断栈是否为空

private:
    struct Node
    {                        // 栈结点类型
        ElementType element; // 结点中存放的元素
        Node *next;          // 指向下一结点的指针
    };
    Node *top; // 栈顶
};