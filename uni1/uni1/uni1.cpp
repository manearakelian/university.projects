#include<iostream>
using namespace std;


class temperature {

private:
    int value;
public:
    //default
    temperature() : value(0) {}
    //parameter
    temperature(int v) : value(v) {}

    //prefix(adding value before)
    temperature& operator++() {
        ++value;
        return *this;
    }
    //postfix

    temperature operator++(int) {
        temperature temp = *this;
        ++value;
        return temp;
    }

    temperature& operator--() {
        --value;
        return *this;
    }

    temperature operator--(int) {
        temperature temp = *this;
        --value;
        return temp;
    }
    temperature operator+(const temperature& t) {
        return this->value + t.value;
    }
    temperature operator*(const temperature& t) {
        return this->value * t.value;
    }
    temperature& operator=(const temperature& t) {
        if (this != &t) {
            this->value = t.value;
        }
        return *this;
    }


    int operator!=(const temperature& t) {
        return this->value != t.value;
    }
    int operator>(const temperature& t) {
        return this->value > t.value;
    }
    int operator>=(const temperature& t) {
        return this->value >= t.value;
    }
    int operator<(const temperature& t) {
        return this->value < t.value;
    }
    int operator<=(const temperature& t) {
        return this->value <= t.value;
    }
    int operator==(const temperature& t) {
        return this->value == t.value;
    }
    friend istream& operator>>(istream& is, temperature& t) {
        is >> t.value;
        return is;
    }
    friend ostream& operator<<(ostream& os, const temperature& t) {
        os << t.value;
        return os;
    }


    void display() const {
        cout << value << endl;

    }
};
int main() {
    temperature temp1(21), temp2(24);
    temp1.display();
    temp2.display();

    ++temp1;
    temp1.display();

    temp1++;
    temp1.display();

    --temp1;
    temp1.display();

    temp1--;
    temp1.display();
    temperature temp3 = temp1 + temp2;
    temp3.display();

    temperature temp4 = temp1 * temp2;
    temp4.display();

    cout << (temp1 != temp2) << endl;
    cout << (temp1 > temp2) << endl;
    cout << (temp1 >= temp2) << endl;
    cout << (temp1 < temp2) << endl;
    cout << (temp1 <= temp2) << endl;
    cout << (temp1 == temp2) << endl;
    temp1 = temp2;
    temp1.display();




}