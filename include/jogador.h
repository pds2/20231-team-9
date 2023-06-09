#ifndef PDS2_JOGADOR_H
#define PDS2_JOGADOR_H

#include "participante.h"

#include <string>

using namespace std;

class Jogador : public Participante {
    public:
        Jogador(string nome, int distrito);
        void definir_acao() override;
};

#endif