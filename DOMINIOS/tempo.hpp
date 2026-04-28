#ifndef TEMPO_HPP_INCLUDED
#define TEMPO_HPP_INCLUDED

class Tempo{
    private:
        int tempo;
        bool validar(int);
    public:
        bool setTempo(int);
        int getTempo();
};

inline int Tempo::getTempo(){
    return tempo;
}

#endif // TEMPO_HPP_INCLUDED
