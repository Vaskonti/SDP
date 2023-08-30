
#include <iostream>
#include <vector>

class BaseDictionary {
public:
    virtual void insert(const int &key, const int &value) = 0;

    virtual void remove(const int &key) = 0;

    virtual int get(const int &key) = 0;

    virtual bool contains(const int &key) = 0;

    virtual int size() = 0;

    virtual bool empty() = 0;

    virtual void clear() = 0;

    virtual ~BaseDictionary() = default;
};

class AVLDictionary : public BaseDictionary {
public:
    void insert(const int &key, const int &value) override {

    }

    void remove(const int &key) override {

    }

    int get(const int &key) override {
        return 0;
    }

    bool contains(const int &key) override {
        return false;
    }

    int size() override {
        return 0;
    }

    bool empty() override {
        return false;
    }

    void clear() override {

    }
};

class HashDictionary : public BaseDictionary {
public:
    void insert(const int &key, const int &value) override {

    }

    void remove(const int &key) override {

    }

    int get(const int &key) override {
        return 0;
    }

    bool contains(const int &key) override {
        return false;
    }

    int size() override {
        return 0;
    }

    bool empty() override {
        return false;
    }

    void clear() override {

    }
};

class SortedArrayDictionary : public BaseDictionary {
public:
    void insert(const int &key, const int &value) override {

    }

    void remove(const int &key) override {

    }

    int get(const int &key) override {
        return 0;
    }

    bool contains(const int &key) override {
        return false;
    }

    int size() override {
        return 0;
    }

    bool empty() override {
        return false;
    }

    void clear() override {

    }
};
int main() {
    std::vector<BaseDictionary> dictionaries = {AVLDictionary(), HashDictionary(), SortedArrayDictionary()};
}