/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
private:
    struct Node {
        int val;
        Node *next;
        Node(int x) : val(x), next(nullptr) {}  
    };
    Node *head_;
    Node *tail_;
    int size_;
    bool empty() {
        return !size_;
    }

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        size_ = 0;
        head_ = nullptr;
        tail_ = nullptr;
    }

    ~MyLinkedList() {
        Node *node = head_;
        while(node) {
            Node *cur = node;
            node = node->next;
            delete(cur);
        }
        head_ = nullptr;
        tail_ = nullptr;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
       if(index < 0 || index >= size_) {
           return -1;
       }
       Node *cur = head_;
       while(index--) {
           cur = cur->next;
       }
       return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *node = new Node(val);
        if(empty()) {
            head_ = tail_ = node;
        } else {
            node->next = head_;
            head_ = node;
        }
        ++size_;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
       if(empty()) {
           addAtHead(val);
           return;
       }
       Node *node = new Node(val);
       tail_->next = node;
       tail_ = node;
       ++size_;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
       if(index < 0 || index > size_) {
           return;
       }
       if(index == 0) {
           return addAtHead(val);
       }
       if(index == size_) {
           return addAtTail(val);
       }
       Node *node = new Node(val);
       Node dummy(0);
       dummy.next = head_;
       Node *prev = &dummy;
       while(index--) {
           prev = prev->next;
       }
       node->next = prev->next;
       prev->next = node;
       ++size_;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
       if(index < 0 || index >= size_) {
           return;
       }
       Node dummy(0);
       dummy.next = head_;
       Node *prev = &dummy;
       for(int i = 0; i < index; i++) {
           prev = prev->next;
       }
       Node *node_to_delete = prev->next;
       prev->next = prev->next->next;
       if(index == 0) {
           head_ = prev->next;
       }
       if(index == size_ - 1) {
           tail_ = prev;
       }
       delete node_to_delete;
       --size_;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

