//
// Created by vasilhristov on 27.08.23.
//

#ifndef CAR_CPP_HASHTABLE_H
#define CAR_CPP_HASHTABLE_H

#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

template <class Key, class Value>
class HashTable {
private:
    static const size_t TABLE_SIZE = 100; // Size of the hash table array
    std::vector<std::list<std::pair<Key,Value>>> table;
    size_t encode(const Key & key) const {
        return std::hash<Key>{}(key) % TABLE_SIZE;
    }

public:
    HashTable() : table(TABLE_SIZE){};

    void insert(const Key & key, const Value & value) {
        size_t index = this->encode(key);
        table[index].emplace_back(key, value);
    }

    Value get(const Key & key) const {
        size_t index = this->encode(key);
        for (const auto &item: table[index]) {
            if (item.first == key) {
                return item.second;
            }
        }
        return Value();
    }

    void remove(const Key & key) {
        size_t index = encode(key);
        table[index].remove_if([&] (const std::pair<Key, Value> & keyPair) {
            return keyPair.first == key;
        });
    }
};


#endif //CAR_CPP_HASHTABLE_H
