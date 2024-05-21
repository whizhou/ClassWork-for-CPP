    #include "listnode.h"

    class OrderedList {
    protected:
        listNode* root;
    public:
        OrderedList() : root(new listNode) {}
        virtual void insert(int val) = 0;
        void printList() const {
            listNode* cur = root->next;
            while (cur) {
                std::cout << cur->val << ' ';
                cur = cur->next;
            }
            std::cout << std::endl;
        }
        ~OrderedList() {
            while (root) {
                listNode* tmp = root;
                root = root->next;
                delete tmp;
            }
        }
    };

    class AscendOrderedList : public OrderedList {
    public:
        void insert(int val) {
            listNode* cur = root;
            while (cur->next && cur->next->val < val)
                cur = cur->next;
            listNode* tmp = new listNode(val, cur, cur->next);
            // if (cur->next)
            //     cur->next->prev = tmp;
            // cur->next = tmp;
        }
    };

    class DescendOrderedList : public OrderedList {
    public:
        void insert(int val) {
            listNode* cur = root;
            while (cur->next && cur->next->val > val)
                cur = cur->next;
            listNode* tmp = new listNode(val, cur, cur->next);
            // if (cur->next)
            //     cur->next->prev = tmp;
            // cur->next = tmp;
        }
    };