#include "../include/patrocinador.h"

Patrocinador::Patrocinador() {
    
}

void Patrocinador::dar_notas_participantes() {
    auto pair = _participantes.begin();
    while(pair != _participantes.end()) {
        int nota;
        std::cout << "Dê uma nota ao participante " << pair->first.get_nome() << ", do distrito " << (pair->first).get_distrito() << std::endl;
        std::cin >> nota;
        _participantes[pair->first] = nota;
    }
}

void Patrocinador::dar_utensilios(Utensilio u, Participante p) {
    p.adicionar_utensilio(u);
}

void Patrocinador::dar_armas(Arma a, Participante p) {
    p.adicionar_arma(a);
}