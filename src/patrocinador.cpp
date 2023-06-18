#include "../include/patrocinador.h"
#include "mapa.h"
#include "../include/sistema.h"

Patrocinador::Patrocinador() {
    
}

Participante *Patrocinador::selecionar_participante() {
    Sistema s;
    map<string, Participante> map_vivos = s.get_vivos();


   //acho que aqui dá para usar polimorfismo 
    // Mapa m;
    // map<string, Participante> map_vivos = m.get_map_vivos();

    while(1) {
        int get_index_random = rand() % map_vivos.size();
        Participante *partic_escolhido;
        auto pair = map_vivos.begin();

        while(get_index_random >= 0) {
            if(get_index_random == 0) {
                *partic_escolhido = pair->second;
            }
            pair = next(pair);
        }
        if(partic_escolhido->get_energia() < 40 || partic_escolhido->get_hidratacao() < 40) {
            return partic_escolhido;
        }
    }

}
void Patrocinador::dar_utensilios(Utensilio u, Participante& p) {
    p.adicionar_utensilio(u);
}

void Patrocinador::dar_armas(Arma a, Participante& p) {
    p.adicionar_arma(a);
}