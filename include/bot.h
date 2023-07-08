#ifndef PDS2_BOT_H
#define PDS2_BOT_H

#include "participante.h"
#include "jogador.h"

#include <string>

using namespace std;

class Bot : public Jogador {
    public:
        /*
        * @brief Construtor
        */
        Bot(string nome);
        /*
        * @brief Define a ação do bot a partir de parâmetros pré-definidos
        */
        void definir_acao(set<Participante*> Msm_Regiao_Q_Eu, map<string,Regiao*>* map_regioes) override;
};

#endif