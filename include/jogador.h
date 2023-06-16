#ifndef PDS2_JOGADOR_H
#define PDS2_JOGADOR_H

#include "participante.h"

#include <string>

using namespace std;

class Jogador : public Participante {
    public:
        /*
        * @brief Construtor
        */
        Jogador(string nome, int distrito);
        /*
        * @brief Lê do usuário um comando para definir a ação do respectivo participante
        */
        void definir_acao() override;
};

#endif