#ifndef DATA_HPP_INCLUDED
#define DATA_HPP_INCLUDED
#include <string>

using namespace std;

class Data{
    private:
            string data;
            bool validar(string);
    public:
            bool setData(string);
            string getData();
};

inline string Data::getData(){
    return data;
}

#endif // DATA_HPP_INCLUDED
