#ifndef PDS2_PATROCINADOR_H
#define PDS2_PATROCINADOR_H

#include <iostream>
#include <map>
#include "participante.h"

class Patrocinador {
    private:
        std::map<Participante, int> _participantes;

    public:
        /*
        * @brief Construtor
        */
        Patrocinador();
        /*
        * @brief Da a nota aos participantes utilizando um while com cin
        */
        void dar_notas_participantes();
        /*
        * @brief Seleciona um participante aleatorio que esteja mal de status
        */
        Participante selecionar_participante();
        /*
        * @brief adiciona utenzilho a tal participante
        */
        void dar_utensilios(Utensilio u, Participante& p);
        /*
        * @brief Adiciona arma a tal participante
        */
        void dar_armas(Arma a, Participante& p);
};

#endif