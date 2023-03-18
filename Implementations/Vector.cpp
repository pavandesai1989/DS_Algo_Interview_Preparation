#include <iostream>
using namespace std;

class myvector
{
private:
    int* m_ptr;
    int m_capacity;
    int m_size;

public:
    myvector()
    {
        m_ptr = new int[1];
        m_capacity=1;
        m_size=0;
    }
    ~myvector()
    {
        if(m_ptr)
        {
            delete[]m_ptr;
            m_ptr=nullptr;
        }

    }
    myvector(const myvector &ob)
    {
        cout<<"copy constructor"<<endl;
        m_size = ob.m_size;
        m_ptr = new int[m_size];

        for(int i=0;i<m_size;i++)
        {
            m_ptr[i] = ob.m_ptr[i];
        }
    }

    myvector& operator=(const myvector &ob)
    {
         if(this == &ob)
            return *this;

         //clean
         delete[]m_ptr;
         m_ptr = new int[ob.m_size];   
         m_size = ob.m_size;

         for(int i=0;i<m_size;i++)
           m_ptr[i] = ob.m_ptr[i];

         return *this;  
    }

    myvector(myvector &&ob)
    {
        cout<<"move constructor"<<endl;
        m_size = move(ob.m_size);
        m_ptr = move(ob.m_ptr);

        ob.m_ptr = nullptr;
        ob_m_size = 0;
    }

    myvector& operator=(myvector &&ob)
    {
       if(this == &ob)
          return *this;

       delete [] m_ptr;

       m_size = move(ob.m_size);
       m_ptr = move(ob.m_ptr);

       ob.m_size=0;
       ob.m_ptr=nullptr;

       return *this;

    }


    void pushback(int data)
    {
        if(m_capacity == m_size)
        {
            cout<<"resizing"<<endl;
            int* temp = new int[2*m_capacity];

            for(int i=0;i<m_capacity;i++)
               temp[i] = m_ptr[i];

            delete[]m_ptr;
            m_capacity = 2*m_capacity;
            m_ptr = temp;
           
        }

        m_ptr[m_size] = data;
        m_size++;
    }

    void push(int idx,int data)
    {
        if(m_capacity == m_size)
           pushback(data);
        else
        {
            m_ptr[idx] = data;

        }
    }

    int& operator[](int idx)
    {
        return m_ptr[idx];
    }

    void popback()
    {
        m_size--;
    }

    int getsize()
    {
        return m_size;
    }
};

ostream& operator<<(ostream& out,myvector& ob)
{
    for(int i=0;i<ob.getsize();i++)
    {
        out<<ob[i];
    }
    return out;
}




int main()
 {
    myvector ob;
    ob.pushback(1);
    ob.pushback(123);

     print(vec);
    
    return 0;
}


