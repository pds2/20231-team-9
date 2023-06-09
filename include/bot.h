#ifndef PDS2_BOT_H
#define PDS2_BOT_H

#include "participante.h"

#include <string>

using namespace std;

class Bot : public Participante {
    public:
        Bot(string nome, int distrito);
        void definir_acao() override;
};

#endif