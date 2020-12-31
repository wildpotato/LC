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

    /* for debugging purposes */
    void showCurrentInfo() {
        cout << "----------------------------------------------\n";
        cout << "Cache capacity = " << capacity << "\n";
        cout << "Current cache size = " << size << "\n";
        cout << "Show current hash map:\n";
        for (auto itr = hash_map.begin(); itr != hash_map.end(); ++itr) {
            cout << "key=" << itr->first << " val=" << itr->second->val << "\n";
        }
        cout << "Show current doubly liniked list:\n";
        for (Node *ptr = head; ptr != tail; ptr = ptr->next) {
            cout << "key=" << ptr->key << " val=" << ptr->val << "\n";
        }
        cout << "----------------------------------------------\n";
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
void test() {
    LRUCache *obj = new LRUCache(2);
    obj->showCurrentInfo();
    obj->put(1,1);
    obj->showCurrentInfo();
    obj->put(2,2);
    obj->showCurrentInfo();
    assert(obj->get(1) == 1);
    obj->showCurrentInfo();
    obj->put(3,3);
    assert(obj->get(2) == -1);
    obj->put(4,4);
    assert(obj->get(1) == -1);
    assert(obj->get(3) == 3);
    assert(obj->get(4) == 4);
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
