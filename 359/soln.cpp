#include "../include.h"

class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {}

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        // turns out the if - else if - else is more efficient
        // than the if - if structure!
        auto itr = hash_table.find(message);
        if (itr == hash_table.end()) {
            hash_table[message] = timestamp;
            return true;
        }
        else if (timestamp >= itr->second + time_delay) {
            itr->second = timestamp;
            return true;
        } else {
            return false;
        }
    }

private:
    unordered_map<string, int> hash_table;
    int time_delay = 10;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */

void test() {
    Logger *log = new Logger();
    assert(log->shouldPrintMessage(1, "foo"));
    assert(log->shouldPrintMessage(2, "bar"));
    assert(!log->shouldPrintMessage(3, "foo"));
    assert(!log->shouldPrintMessage(8, "bar"));
    assert(!log->shouldPrintMessage(10, "foo"));
    assert(log->shouldPrintMessage(11, "foo"));
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
