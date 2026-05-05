#ifndef PAPEL_HPP_INCLUDED
#define PAPEL_HPP_INCLUDED
#include <string>

using namespace std;

class Papel{
    private:
        string papel;
        bool validar(string);
    public:
        bool setPapel(string);
        string getPapel();
};

inline string Papel::getPapel(){
    return papel;
}


#endif // PAPEL_HPP_INCLUDED
