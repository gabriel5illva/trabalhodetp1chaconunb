#include "tempo.hpp"

using namespace std;

bool Tempo::validar(int tempo){
    if(tempo > 365 || tempo < 1)
        return false;
    return true;
}

bool Tempo::setTempo(int tempo){
    if(!validar(tempo))
        return false;
    this->tempo = tempo;
}
