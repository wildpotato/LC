#include "../include.h"

struct Node {
	int key;
	int val;
	Node *prev;
	Node *next;
	Node() : key(-1), val(-1), prev(nullptr), next(nullptr) {}
    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
		capacity = capacity;
		head->next = tail;
		tail->prev = head;
    }
    int get(int key) {
		int ret = -1;
		auto itr = hash_map.find(key);
		if (itr == hash_map.end()) {
			return ret;
		}
		removeNode(itr->second);
		addNode(itr->second);
		return itr->second->val;
    }
    void put(int key, int value) {
		auto itr = hash_map.find(key);
		if (itr != hash_map.end()) {
			removeNode(itr->second);
            addNode(itr->second);
		} else {
            if (size == capacity) {
                removeNode(tail->prev);
                size--;
            }
            addNode(new Node(key, value));
            ++size;
        }
    }
private:
	/* add node to head */
	void addNode(Node *node) {
		node->next = head->next;
		node->prev = head;
		head->next->prev = node;
		head->next = node;
	}
	/* remove current node from list */
	void removeNode(Node *node) {
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	unordered_map<int, Node *> hash_map;
	Node *head = new Node();
	Node *tail = new Node();
	int size = 0;
	int capacity = 0;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
