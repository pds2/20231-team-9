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
        * @brief
        */
        void definir_acao() override;
};

#endif