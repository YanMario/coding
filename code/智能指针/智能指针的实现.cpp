//
// Created by yanpan on 2019/5/9.
//

/*智能指针的实现*/


#if 0

#include <iostream>
#include <memory>
using namespace std;

template <class T>
class my_sharedptr
{
public:

    my_sharedptr(T *rhs)
    {
        _PBlock = new ControlBlock(rhs);
        cout << "my_sharedptr" << _PBlock -> ref_count << endl;
    }
    my_sharedptr(const my_sharedptr& rhs)
    {
        _PBlock = rhs._PBlock;
        _PBlock -> ref_count++;
    }
    my_sharedptr& operator=(const my_sharedptr& rhs)
    {
        if(*this == rhs)
            return *this;
        //对之前智能指针的
        if(_PBlock -> ref_count > 0)
            _PBlock -> ref_count--;
        if(0 == _PBlock -> ref_count)
            delete _PBlock;

        _PBlock = rhs._PBlock;
        _PBlock -> ref_count++;
    }
    T* operator->()
    {
        return _PBlock -> _ptr;
    }

    void reset(T *rhs = 0)
    {
        _PBlock -> ref_count--;
        if(0 == _PBlock -> ref_count)
            delete _PBlock;
        _PBlock = new ControlBlock(rhs);
    }

    T* get()
    {
        return _PBlock -> _ptr;
    }
    ~my_sharedptr()
    {
        _PBlock -> ref_count--;
        if(0 == _PBlock -> ref_count)
            delete _PBlock;
        cout << "~my_sharedptr" << endl;
    }
    int use_count()
    {
        return _PBlock -> ref_count;
    }
private:
    class ControlBlock
    {
    public:
        ControlBlock(T* ptr)
        {
            _ptr = ptr;
            ref_count = 1;
        }
        ~ControlBlock()
        {
            delete _ptr;
            cout << "~ControlBlock()" << endl;
        }
        int ref_count;
        T* _ptr;
    };
    ControlBlock* _PBlock;
};



int main()
{
    my_sharedptr<int> aptr(new int);
    my_sharedptr<int> bptr(aptr);
    cout << bptr.use_count() << endl;
    return 0;
}

#endif