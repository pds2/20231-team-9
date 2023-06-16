#ifndef PDS2_BOT_H
#define PDS2_BOT_H

#include "participante.h"

#include <string>

using namespace std;

class Bot : public Participante {
    public:
        /*
        * @brief Construtor
        */
        Bot(string nome, int distrito);
        /*
        * @brief Define a ação do bot a partir de parâmetros pré-definidos
        */
        void definir_acao() override;
};

#endif