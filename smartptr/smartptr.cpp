#include<iostream>

//如果你自己要实现一个智能智能，你要怎么实现。
//它里面最重要的是计数器。
//智能指针用于标准容器，所以使用默认析构函数就可以了，不用自己再去写了。
//或者在智能指针的类中是自己提供了析构函数，然后计数器为0的时候，调用它的析构函数就可以了
//智能指针初始化应该是需要初始化一个指针

//三五法则告诉我们要实现一个析构函数，则必须要实现他拷贝构造和赋值构造

//智能指针是如何管理它管理的指针的接口呢？需要实现一个 -> 的接口吗？
//如何在智能指针中释放

//我们需要考虑需求，而不是接口越多越好，满足功能就可以了

class Person {
public:
    Person() : name_(nullptr), age_(0) {}
    Person(const char* name, int age) : name_(name), age_(age) {}

    void Display() const {
        std::cout <<"the name is "<< name_ << std::endl;
        std::cout <<"the age  is "<< age_ << std::endl;
    }

    ~Person() {}

private:
    const char* name_;
    int age_;
};

class RC
{
private:
    int count_;

public:
    void AddRef() {
        count_++;
    }
    int Release() {
        return --count_;
    }
};

template<typename T>
class SmartPtr {
public:
    SmartPtr() : t_(NULL), ref_(0) {
        ref_ = new RC();
        ref_->AddRef();
    }
    explicit SmartPtr(T *t) : t_(t), ref_(0) {
        ref_ = new RC();
        ref_->AddRef();
    }

    SmartPtr(const SmartPtr<T>& sp) : t_(sp.t_), ref_(sp.ref_) {
        ref_->AddRef();
    }

    T* operator-> () {
        return t_;
    }

    T& operator* () {
        return *t_;
    }

    SmartPtr<T>& operator= (const SmartPtr<T>& sp) {
        if (this != &sp) {
            if (ref_->Release() == 0) {
                delete t_;
                delete ref_;
            }

            t_ = sp.t_;
            ref_ = sp.ref_;
            ref_->AddRef();
        }
        return *this;
    }

    ~SmartPtr() {
        if (ref_->Release() == 0) {
            delete t_;
            delete ref_;
        }
    }

private:
    T *t_;
    RC *ref_;
};


template <typename T>
class SP 
{
private:
    T* pData;
public:
    SP(T* pValue) : pData(pValue) {}
    ~SP() {
        delete pData;
    }

    T& operator* () {
        return *pData;
    }

    T* operator->() {
        return pData;
    }
};


//测试代码

int main()
{
    SmartPtr<Person> p(new Person("Scott", 25));
    p->Display();
    {
        SmartPtr<Person> q = p;
        q->Display();

        SmartPtr<Person> r;
        r = p;
        r->Display();
    }
    p->Display();

    return 0;
}



