/*
We need to keep track of a min as we progress in our own custom node, rest is also normal
*/

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    int minSoFar;
    Node* next;

    Node(int v, int m, Node* n) {
        val = v;
        minSoFar = m;
        next = n;
    }
};


class MinStack {
public:
    Node* head;

    MinStack() {
        head = nullptr;
    }
    
    void push(int val) {
        if (!head) {
            head = new Node(val, val, nullptr);
        } else {
            int newMin = std::min(val, head->minSoFar);
            head = new Node(val, newMin, head);
        }
    }
    
    void pop() {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->minSoFar;
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
