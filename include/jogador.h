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
        * @brief Movimenta o jogador
        */
        void definir_acao() override;
};

#endif