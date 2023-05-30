#ifndef PDS2_PATROCINADOR_H
#define PDS2_PATROCINADOR_H

#include <iostream>
#include <map>
#include "participante.h"
#include "mapa.h"

class Patrocinador {
    private:
        std::map<Participante, int> _participantes;

    public:
        Patrocinador();
        void dar_notas_participantes();
        Participante selecionar_participante();
        void dar_utensilios(Utensilio u, Participante p);
        void dar_armas(Arma a, Participante p);
};

#endif