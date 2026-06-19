#include "tempo.hpp"
#include <stdexcept>

using namespace std;

bool Tempo::validar(int tempo){
    if(tempo > 365 || tempo < 1)
        return false;
    return true;
}

bool Tempo::setTempo(int tempo){
    if(!validar(tempo))
        throw invalid_argument("Formato de Tempo invalido.");
    this->tempo = tempo;
    return true;
}
