#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache{
private:
    struct DListNode{
        int key,val;
        DListNode* pre;
        DListNode* next;
        DListNode(int key, int val): key(key), val(val), pre(nullptr), next(nullptr){}
    };
    int size;
    DListNode* head;
    DListNode* tail;
    unordered_map<int, DListNode*> hash;
public:
    LRUCache(int capacity) {
        size = capacity;
        head = new DListNode(0, 0);
        tail = new DListNode(0, 0);
        head->next = tail;
        tail->pre = head;
    }

    void addNode(DListNode* node) {
        node->pre = head;
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
    }

    void removeNode(DListNode* node) {
        node->next->pre = node->pre;
        node->pre->next = node->next;
    }

    int get(int key) {
        if(hash.find(key) == hash.end()) {
            return -1;
        } else {
            DListNode* node = hash[key];
            removeNode(node);
            addNode(node);
            return node->val;
        }
    }

    void put(int key, int value) {
        if(hash.find(key) != hash.end()) {
            DListNode* node = hash[key];
            node->val = value;
            removeNode(node);
            addNode(node);
        } else {
            DListNode* node = new DListNode(key, value);
            if(hash.size() >= size) {
                DListNode* removed = tail->pre;
                removeNode(removed);
                hash.erase(removed->key);
                delete removed;
            }
            hash[key] = node;
            addNode(node);
        }
    }
};

int main() {
    LRUCache test = LRUCache(2);
    test.put(1,1);
    test.put(2,2);
    cout << test.get(1) << endl;
    test.put(3,3);
    cout << test.get(2) << endl;
    return 0;
}