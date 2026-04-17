#include "HashMap.hpp"
#include <iostream>
#include <stdexcept>

template <typename K, typename V>
HashMap<K, V>::HashMap(int size) : n(0)
{
    data.resize(size, nullptr);
    
    deleted = new HashNode<K, V>(K(), V());
}

template <typename K, typename V>
bool HashMap<K, V>::empty() const {
    return n == 0;
}

template <typename K, typename V>
bool HashMap<K, V>::full() const {
    return n == data.size();
}

template <typename K, typename V>
int HashMap<K, V>::hash(const K& key) const {
    return key % data.size();
}

template <typename K, typename V>
void HashMap<K, V>::insert(const K& key, const V& value) {
    if (full()) {
        return;
    }
    
    // Find the hash
    int index = hash(key);
    
    while (data[index] && data[index] != deleted) {
        index = (index + 1) % data.size(); // Go to the next position
    }
    
    data[index] = new HashNode<K, V>(key, value);
    n++;
}

template <typename K, typename V>
void HashMap<K, V>::print() const {
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << i << ' ';
        if (data[i] == nullptr) {
            std::cout << "nullptr\n";
        }
        else if (data[i] == deleted) {
            std::cout << "deleted\n";
        }
        else {
            std::cout << "{ " << data[i]->key << "; " << data[i]->value << " }\n";
        }
    }
}

template <typename K, typename V>
int HashMap<K, V>::searchIndex(const K& key) const {
    // do not search through whole data, instead convert key into hash and look at position. if key == key, then we got it. If not, keep going.
    int index = hash(key);
    while (data[index] != nullptr)
    {
        if (data[index]->key == key) {
            return index;
        }

        index++;
    }

    // if nullptr, stop
    // return -1 if not there
    return -1;
}

template <typename K, typename V>
const V& HashMap<K, V>::search(const K& key) const {
    int idx = searchIndex(key);

    if (idx == -1)
    {
        throw 5;

    }
    else
        return data[idx]->value;
}

template <typename K, typename V>
void HashMap<K, V>::remove(const K& key) {
    int idx = searchIndex(key);
    
    if (idx == -1)
        return;
    
    data[idx] = deleted;
}

