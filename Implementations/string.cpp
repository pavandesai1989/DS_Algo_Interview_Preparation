#include <iostream>
#include <string.h>
#include <stdio.h>
#include<ostream>
using namespace std;


class mystring
{
private:
    char* buff;
    size_t size;

public:
    mystring():buff(nullptr),size(0)
    {

    }
    ~mystring()
    {
        delete [] buff;
        size = 0;
    }
    explicit mystring( const char* const buffer)
    {
        size = strlen(buffer);
        buff = new char[size+1];
        strncpy(buff,buffer,size);
    }
    mystring(const mystring& ob)
    {
        cout<<"copy constructor"<<endl;
        size=ob.size;
        buff = new char[size+1];
        strncpy(buff,ob.buff,ob.size);
    }
    mystring& operator=(const mystring& ob)
    {
        cout<<"copy assignment operator"<<endl;
        if(this == &ob)
           return *this;

        delete [] buff;
        size=0;

        size=ob.size;
        buff = new char[size+1];
        strncpy(buff,ob.buff,ob.size);

        return *this;
    }

    mystring(mystring &&ob)
    {
        cout<<"move constructor"<<endl;
        size = ob.size;
        buff = move(ob.buff);

        ob.size = 0;
        ob.buff = nullptr;
    }

    mystring& operator=(mystring &&ob)
    {
        cout<<"move assignment operator"<<endl;
         if(this == &ob)
             return *this;

         delete []buff;
         buff = ob.buff;
         size = ob.size;

         ob.buff = nullptr;
         ob.size = 0;

         return *this;
    }

    const char* c_str()const
    {
        return buff;
    }

    size_t length()const{
        return size;
    }
};

ostream& operator<<(ostream& out,const mystring& ob)
{
    out<<ob.c_str();
    return out;
}


istream& operator>>(istream& in,const mystring& ob)
{
    in>>ob.c_str();
    return in;
}



int main()
{
   mystring ob("pavan");
    
    mystring ob2(move(ob));
   cout<<ob2<<endl;
    
    return 0;
}



