#include "hash.h"

// LOOK FOR THE COMMENTS IN THE .H 
// TO UNDERSTAND WHAT EACH FUNCTION MUST DO

Hash::Hash(int tablesize, int (*hf) (std::string) ) {
    _table.resize(tablesize);
    _hash_func = hf;
}

int Hash::add(std::string str, int &collisions) { 
    if(Hash::contains(str, collisions) == 1) {
        return 0;
    }

    int pos = hash(str);

    _table[pos].push_front(str);

    return 1;
}//add

int Hash::remove(std::string str, int &collisions) { 
    if(Hash::contains(str, collisions) == 0) {
        return 0;
    }

    collisions = 0;
    int pos = _hash_func(str);

    _table[pos].remove(str);

    return 1;
}//remove


int Hash::hash(std::string str) { 
    return _hash_func(str);
}//hash
    
int Hash::contains(std::string str, int &collisions) {
    int pos = Hash::hash(str);
    collisions = 0;

    for(std::string& bucket_str : _table[pos]) {
        collisions++;
        if(str == bucket_str) {
            return 1; 
        }
    }
        
    return 0;    
}//contains

int Hash::worst_case() {
    int max_bucket_size = 0;
    int bucket_size;

    for(std::forward_list<std::string>& bucket : _table) {
        bucket_size = 0;
        for(std::string& str : bucket) {
            bucket_size++;
        }
        if(bucket_size > max_bucket_size) {
            max_bucket_size = bucket_size;
        }
    }

    return max_bucket_size;
}//worst_case

int Hash::size() {
    int size = 0;

    for(std::forward_list<std::string>& bucket : _table) {
        for(std::string& bucket_str : bucket) {
            size += 1;
        }
    }

    return size;    
}//size

