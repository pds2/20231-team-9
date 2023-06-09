#include "sistema.h"

void Sistema::criar_participante(string nome, int destrito) {
    auto pair = _vivos.begin();
    while(pair != _vivos.end()) {
        if(nome == pair->first) {
            throw participante_ja_existe_e();
        }
        pair = next(pair);
    }
    
    if(destrito > 12 || destrito < 1) {
        throw distrito_invalido_e();
    }

    _vivos[nome] = Participante(nome,destrito);
}

void Sistema::morrer(Participante &fulano) {
    _mapa.morrer(&fulano);
    _mortos.push_back(fulano.get_nome());
    auto pair = _vivos.begin();
    while(pair != _vivos.end()) {
        if(pair->first == fulano.get_nome()) {
            _vivos.erase(pair);
        }
    }
}

map<string, Participante> Sistema::get_vivos() {
    return _vivos;
}