#include "../include/participante.h"
#define stringify( name ) # name

Participante::Participante(string nome, int distrito) : _arma(armas::desarmado) {
    _nome = nome;
    _distrito = distrito;
    _vivo = true;
    _energia = 100;
    _hidratacao = 100;
    _atual = Regiao();
    qntd_agua = 0;
    qntd_comida = 0;
    qntd_remedio = 0;
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
    return _arma;
}

void Participante::adicionar_arma(Arma arma) {
    if(arma.get_poder() > _arma.get_poder()) {
        _arma = arma;
    }
}

void Participante::adicionar_utensilio() { //Vamos alterar isso
    std::cout << "1) " << to_string(qntd_agua) << std::endl;
    std::cout << "2) " << to_string(qntd_comida) << std::endl;
    std::cout << "3) " << to_string(qntd_remedio) << std::endl;

    int a_consumir;
    std::cout << "Digite o nome do utensílio que você deseja adicionar nessa rodada: ";
    std::cin >> a_consumir;

    switch (a_consumir) {
    case 1:
        qntd_agua++;
        break;
    case 2:
        qntd_comida++;
        break;
    case 3:
        qntd_remedio++;
        break;
    
    default:
        break;
    }
}

void Participante::muda_regiao_atual(Regiao destino) {
    _atual = destino;
}

void Participante::batalha(Participante& p) {
    std::cout << "O jogador " << get_nome() << " do distrito " << get_distrito() << " atacou o jogador " << p.get_nome() << " do distrito " << p.get_distrito() << std::endl;
    Arma arma_escolhida_atacante = _arma;
    Arma arma_escolhida_defesa = p._arma;

    if(arma_escolhida_atacante.get_poder() > arma_escolhida_defesa.get_poder()) {
        p._vivo = false;
        std::cout << "O jogador " << p.get_nome() << " do distrito " << p.get_distrito() << " foi morto" << std::endl;
        _energia *= (1 - 0.1*arma_escolhida_atacante.get_poder());

    } else if(arma_escolhida_atacante.get_poder() < arma_escolhida_defesa.get_poder()) {
        _vivo = false;
        std::cout << "O jogador " << get_nome() << " do distrito " << get_distrito() << " foi morto" << std::endl;
        p._energia *= (1 - 0.1*arma_escolhida_defesa.get_poder());
    } else {
        _energia *= (1 - 0.1*arma_escolhida_atacante.get_poder());
        p._energia *= (1 - 0.1*arma_escolhida_defesa.get_poder());
    }
}

regioes Participante::get_regiao_atual() {
    return _atual.get_nome();
}

void Participante::consumir_utensilios() { //Vamos alterar isso
    //Consumir água  = hidratação 100
    //Consumir comida = energia 100
    //Remédio +50 +50, maximo 100
    std::cout << "O jogador " << get_nome() << " possui:" << std::endl;
    std::cout << "1) " << to_string(qntd_agua) << "água(s)" << std::endl;
    std::cout << "2) " << to_string(qntd_comida) << "comida(s)" << std::endl;
    std::cout << "3) " << to_string(qntd_remedio) << "remédio(s)" << std::endl;

    int a_consumir;
    std::cout << "Digite o nome do utensílio que você deseja consumir nessa rodada: ";
    std::cin >> a_consumir;

    switch (a_consumir) {
    case 1:
        qntd_agua--;
        break;
    case 2:
        qntd_comida--;
        break;
    case 3:
        qntd_remedio--;
        break;
    
    default:
        break;
    }

}

void Participante::buscar_na_regiao() {
    float chance_agua = rand() % 10 + 1;
    float chance_comida = rand() % 10 + 1;
    float chance_remedio = rand() % 10 + 1;
    float chance_arma = rand() % 10 + 1;

    if(chance_agua < _atual.get_chance_agua()) {
        qntd_agua++;
    }

    if(chance_remedio < _atual.get_chance_remedio()) {
        qntd_remedio++;
    }

    if(chance_comida < _atual.get_chance_comida()) {
        qntd_comida++;
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