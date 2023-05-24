#ifndef PDS2_MAPA_H
#define PDS2_MAPA_H

#include "participante.h"
#include "regiao.h"

class participante_ja_existe_e {};
class idade_invalido_e {};
class distrito_invalido_e {};

class Mapa {
    private:
    map<string,Participante> _vivos;
    Regiao _centro;
    Regiao _floresta;
    Regiao _deserto;
    Regiao _pantano;
    Regiao _campo;
    Regiao _montanhas;
    Regiao _ruinas;

    public:
    /*
    * @brief Construtor
    */
    Mapa();
    Regiao get_centro();
    Regiao get_floresta();
    Regiao get_deserto();
    Regiao get_pantano();
    Regiao get_campo();
    Regiao get_montanhas();
    Regiao get_ruinas();
    void criar_participante(string nome,int idade, int destrito);
    void inicio();
    void morrer(Participante* fulano);
    void mover_do_centro(regioes destino, Participante* fulano);
    void mover_da_floresta(regioes destino, Participante* fulano);
    void mover_do_deserto(regioes destino, Participante* fulano);
    void mover_do_pantano(regioes destino, Participante* fulano);
    void mover_do_campo(regioes destino, Participante* fulano);
    void mover_das_montanhas(regioes destino, Participante* fulano);
    void mover_das_ruinas(regioes destino, Participante* fulano);
};

#endif