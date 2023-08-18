#ifndef CAR_CPP_STRING_H
#define CAR_CPP_STRING_H

#include <iostream>
#include <fstream>
#include <cstring>

class String {
private:
    char * value;
    size_t length;
public:
    String() : value(nullptr), length(0) {}

    String(const char *val) : value(nullptr), length(0) {
        if (val) {
            this->length = strlen(val);
            this->value = new char [this->length + 1];
            strcpy(this->value, val);
        }
    }

    ~String() {
        delete [] this->value;
    }

    String(const String &other) {
        if (this != &other) {
            delete []  this->value;
            this->length = other.length;
            this->value = new char [this->length + 1];
            strcpy(this->value, other.value);
        }
    }

    String &operator=(const String &other) {
        if (this != &other) {
            if (other.value) {
                this->length = other.length;
                this->value = new char[this->length + 1];
                strcpy(this->value, other.value);
            } else {
                this->value = nullptr;
                this->length = 0;
            }
        }
        return *this;
    }

    char &operator[](int index) const {
        if (index > length - 1) {
            std::cerr << "Index out of boundaries!";
            throw std::invalid_argument("Index out of boundaries");
        }
        return value[index];
    }

    size_t size() const {
        return this->length;
    }

    void concatChar(const char c) {
        this->value[this->length] = c;
        this->length++;
    }

    friend std::ostream &operator<<(std::ostream &os, const String &str) {
        os << str.value;
        return os;
    }

    String & concat(const String & str) {
        if (str.value) {
            this->length += str.length;
            String container = String(this->value);
            delete [] this->value;
            this->value = new char [this->length];
            strcpy(this->value, container.value);
            strcat(this->value, str.value);
        }
        return *this;
    }

    bool operator==(const String & other) {
        return strcmp(this->value, other.value) == 0;
    }
    bool operator!=(const String & other) {
        return !(this == &other);
    }

    bool operator<(const String & other) {
        return strcmp(this->value, other.value) > 0;
    }

    bool operator>(const String & other) {
        return strcmp(this->value, other.value) < 0;
    }

    bool operator<=(const String & other) {
        return this < &other || this == &other;
    }
    bool operator>=(const String & other) {
        return this > &other || this == &other;
    }

};


#endif //CAR_CPP_STRING_H
