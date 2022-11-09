#include <iostream>


class MyArray {

    int size = 3;
    int m_arra[3][3];

public:

    void set();
    MyArray& operator += (MyArray& str) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                m_arra[i][j] += str.m_arra[i][j];
            }
        }
        return *this;
    }


    MyArray operator -= (MyArray& str) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                m_arra[i][j] -= str.m_arra[i][j];
            }
        }
        return *this;
    }


    MyArray& operator = (MyArray& str) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                m_arra[i][j] = str.m_arra[i][j];
            }
        }
        return *this;
    }


    MyArray operator + (MyArray& str) {

        MyArray temp;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                temp.m_arra[i][j] = m_arra[i][j] + str.m_arra[i][j];
            }
        }
        return temp;
    }


    friend bool operator == (MyArray& str, MyArray& str2);
    friend std::ostream& operator << (std::ostream &out, MyArray &o);


    int find(int &ele){

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (ele == m_arra[i][j])
                    return ele;
            }
        }
        return false;
    }
};

    bool operator ==(MyArray& str, MyArray& str2) {

         if (str.size != str2.size )
            return false;

        for (int i = 0; i < 3; i++) {
             for (int j = 0; j < 3; j++) {
                if (str.m_arra[i][j] != str2.m_arra[i][j])
                return false;
            }
        }
             return true;
    }


    std::ostream& operator << (std::ostream &out, MyArray &o){
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                out << o.m_arra[i][j] << ' ';
            }
                std::cout << std::endl;
        }
        return out;
    }



    void MyArray::set() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
            m_arra[i][j] = rand() % 10;
            }
        }
    }


int main() {

    MyArray str;
    MyArray str2;

    str2.set();
    std::cout << std::endl;

    str = str2;
    std::cout << str << std::endl;

    str += str2;
    std::cout << str << std::endl;

    str -= str2;
    std::cout << str << std::endl;

    MyArray str3(str + str2);
    std::cout << str3 << std::endl;



    if (str == str2) {
        std::cout << "Arrays is equal " << std::endl;
    }
    else {
        std::cout << "Arrays is not equal " << std::endl;
    }

    int m_find;

    std::cout <<  "Input element - ";
    std::cin >> m_find;

    int  rezult = str.find(m_find);

    std::cout << "Your element - " << rezult << std::endl;

    if (rezult == m_find) {

        std::cout << "Int " << m_find << " is fined in your array " << std::endl;
    }
    else {
        std::cout << "Int " << m_find << " is not fined in your array " << std::endl;
    }

}