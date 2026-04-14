#ifndef EMAIL_HPP_INCLUDED
#define EMAIL_HPP_INCLUDED
#include <string>

using namespace std;

class Email{
    private:
            string email;
            bool validar(string);
            const int tamanhoMaxParteLocal = 64;
            const int tamanhoMaxParteDominio = 255;
    public:
            bool setEmail(string);
            string getEmail();
};

inline string Email::getEmail(){
    return email;
}



#endif // EMAIL_HPP_INCLUDED
