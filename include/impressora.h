#ifndef PDS2_IMPRESSORA_H
#define PDS2_IMPRESSORA_H

#include "../third_party/tabulate.hpp"

class Impressora{
    private:
        tabulate::Table mapa;
    public:
        Impressora();
        void imprime_mapa();
        void imprime_titulo();
};

#endif