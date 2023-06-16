#include "../include/sistema.h"

void Sistema::criar_participante(string nome, int distrito) {
    //IDEIA DE CÓDIGO SE _vivos FOR VECTOR
    // for(Participante& this_one : _vivos) {
    //     if(nome == this_one.get_nome()) {
    //         throw participante_ja_existe_e();
    //     }
    // }
    auto pair = _vivos.begin();
    while(pair != _vivos.end()) {
        if(nome == pair->first) {
            throw participante_ja_existe_e();
        }
        pair = next(pair);
    }
    
    if(distrito > 12 || distrito < 1) {
        throw distrito_invalido_e();
    }

    _vivos[nome] = Participante(nome,distrito);
    // _vivos.push_back(Participante(nome, distrito));
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

map<string,Participante> Sistema::get_vivos() {
    return _vivos;
}