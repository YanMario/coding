//
// Created by yanpan on 2019/8/4.
//

#if 0
#include <iostream>
using namespace std;

class MyString
{
public:
    MyString(const char* str)
    {
        if(str == NULL)
        {
            m_data = new char[1];
            *m_data = '\0';
        }
        else
            {
            int len = strlen(str);
            m_data = new char[len+1];
            strcpy(m_data, str);
        }
    }

    MyString(const MyString& other)
    {
        int len = strlen(other.m_data);
        if(len <= 0)
        {
            m_data = new char[1];
            *m_data = '\0';
        }
        m_data = new char[len+1];
        strcpy(m_data, other.m_data);
    }

    MyString& operator=(const MyString &other)
    {
        if(this == &other)
        {
            return *this;
        }
        if(m_data)
            delete[] m_data;
        int len = strlen(other.m_data);
        m_data = new char[len+1];
        strcpy(m_data, other.m_data);
        return *this;
    }


    ~MyString()
    {
        delete[]m_data;
    }

    friend ostream& operator<<(ostream& os, const MyString& s);
private:
    char *m_data;
};

ostream& operator<<(ostream& os, const MyString& s) {
    os << s.m_data;
    return os;
}
int main()
{
    char* p="Hello World !";

    MyString s(p);

//    s.show();
cout << s << endl;
    MyString s1("How are you ?");

//    s.show();
    cout << s1 << endl;
    s1=s;
//    s.show();
//    s1.show();
    cout << s << endl;
    cout << s1 << endl;

    s=s=s1;
    cout << s << endl;
    cout << s1 << endl;
//    cout<<s<<endl<<s1<<endl;

    return 0;
}


#endif