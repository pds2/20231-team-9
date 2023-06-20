#include "../include/participante.h"

#define stringify( name ) # name

Participante::Participante() {}

Participante::Participante(string nome, int distrito) {
    _nome = nome;
    _distrito = distrito;
    _vivo = true;
    _energia = 100;
    _hidratacao = 100;
    _atual = Regiao();
    *_arma = Arma(armas::desarmado);
}

string Participante::get_nome() const {
    return _nome;
}

int Participante::get_distrito() const {
    return _distrito;
}

bool Participante::get_vivo() const {
    return _vivo;
}

Regiao Participante::get_atual() {
    return _atual;
}

float Participante::get_energia() {
    return _energia;
}
float Participante::get_hidratacao() {
    return _hidratacao;
}

Arma Participante::get_arma() {
    return *_arma;
}

void Participante::adicionar_arma(Arma arma) {
    if(arma.get_poder() > _arma->get_poder()) {
        *_arma = arma;
    }
}

void Participante::adicionar_utensilio(Utensilio utensilio) {
    auto pair = _utensilios.begin();
    while(pair != _utensilios.end()) {
        if((pair->first).get_tipo() == utensilio.get_tipo()) {
            pair->second +=1;
            return ;
        }
    }
    _utensilios[utensilio] = 1;
}

void Participante::muda_regiao_atual(Regiao destino) {
    _atual = destino;
}

void Participante::batalha(Participante& p) {
    std::cout << "O jogador " << get_nome() << " do distrito " << get_distrito() << " atacou o jogador " << p.get_nome() << " do distrito " << p.get_distrito() << std::endl;
    Arma *arma_escolhida_atacante = _arma;
    Arma *arma_escolhida_defesa = p._arma;

    if(arma_escolhida_atacante->get_poder() > arma_escolhida_defesa->get_poder()) {
        p._vivo = false;
        std::cout << "O jogador " << p.get_nome() << " do distrito " << p.get_distrito() << " foi morto" << std::endl;
        //faltar adicionar chamadas que mudarão os campos "_energia" e "_ferido"
        _energia *= (1 - 0.1*arma_escolhida_atacante->get_poder());

    } else if(arma_escolhida_atacante->get_poder() < arma_escolhida_defesa->get_poder()) {
        _vivo = false;
        std::cout << "O jogador " << get_nome() << " do distrito " << get_distrito() << " foi morto" << std::endl;
        p._energia *= (1 - 0.1*arma_escolhida_defesa->get_poder());
    } else {
        _energia *= (1 - 0.1*arma_escolhida_atacante->get_poder());
        p._energia *= (1 - 0.1*arma_escolhida_defesa->get_poder());
    }
}

regioes Participante::get_regiao_atual() {
    return _atual.get_nome();
}

void Participante::consumir_utensilios() {
    auto pair = _utensilios.begin();
    std::cout << "O jogador " << get_nome() << " possui os seguintes utensílios:" << std::endl;
    while(pair != _utensilios.end()) {
        std::cout << "* " << stringify(pair->first.get_tipo()) << ": " << pair->second << "unidades" << std::endl;
        pair = next(pair);
    }

    while(1) {
        std::string a_consumir;
        std::cout << "Digite o nome do utensílio que você deseja consumir nessa rodada: ";
        std::cin >> a_consumir;

        transform(a_consumir.begin(), a_consumir.end(), a_consumir.begin(), ::tolower);
        pair = _utensilios.begin();
        while(pair != _utensilios.end()) {
            if(stringify(pair->first.get_tipo()) == a_consumir) {
                _utensilios[pair->first] -= 1;
                return ;
            }
        }
    }

}

void Participante::buscar_na_regiao() {
    float chance_agua = rand() % 10 + 1;
    float chance_comida = rand() % 10 + 1;
    float chance_remedio = rand() % 10 + 1;
    float chance_arma = rand() % 10 + 1;

    if(chance_agua < _atual.get_chance_agua()) {
        auto aux = _utensilios.begin();
        while(aux != _utensilios.end()) {
            if(aux->first.get_tipo() == utensilios::agua) {
                aux->second++;
                return ;
            }
            aux = next(aux);
        }
        _utensilios[utensilios::agua] = 1;
    }

    //ESSA PARTE ESTAVA FALHANDO
    if(chance_remedio < _atual.get_chance_remedio()) {
        auto aux = _utensilios.begin();
        while(aux != _utensilios.end()) {
            if(aux->first.get_tipo() == utensilios::remedio) {
                aux->second++;
                return ;
            }
            aux = next(aux);
        }
        _utensilios[utensilios::remedio] = 1;
    }
    //FIM DA PARTE QUE ESTAVA FALHANDO

    if(chance_comida < _atual.get_chance_comida()) {
        auto aux = _utensilios.begin();
        while(aux != _utensilios.end()) {
            if(aux->first.get_tipo() == utensilios::comida) {
                aux->second++;
                return ;
            }
            aux = next(aux);
        }
        _utensilios[utensilios::comida] = 1;
    }
    if(chance_arma > _atual.get_chance_arma()) {
        int qual_arma = rand() % 10 + 1;
        if(qual_arma <= 4) {
            Arma _faca(faca);
            adicionar_arma(_faca);
        } else if(qual_arma <= 7) {
            Arma _arco(arco);
            adicionar_arma(_arco);
        } else if(qual_arma <= 8) {
            Arma _espada(espada);
            adicionar_arma(_espada);
        } else if(qual_arma == 10) {
            Arma _machado(machado);
            adicionar_arma(_machado);
        }
    }
}