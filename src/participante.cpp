#include "../include/participante.h"
#define stringify( name ) # name

Participante::Participante(string nome) : _arma(armas::desarmado) {
    _nome = nome;
    _vivo = true;
    _energia = 100;
    _hidratacao = 100;
    _regiao_atual = Regiao();
    qntd_agua = 0;
    qntd_comida = 0;
    qntd_remedio = 0;
}

string Participante::get_nome() const {
    return _nome;
}

bool Participante::get_vivo() const {
    return _vivo;
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

void Participante::imprime_qntd_utensilios() {
    //std::cout << "O jogador " << get_nome() << " possui:" << std::endl;
    std::cout << "Água: " << to_string(qntd_agua) << std::endl;
    std::cout << "Comida: " << to_string(qntd_comida) << std::endl;
    std::cout << "Remédio: " << to_string(qntd_remedio) << std::endl;

}

void Participante::adicionar_arma(Arma arma) {
    if(arma.get_poder() > _arma.get_poder()) {
        _arma = arma;
    }
}

void Participante::adicionar_utensilio(std::string utensilio, int qntd) { //Vamos alterar isso
    if(utensilio == "agua") {
        qntd_agua++;
    } else if( utensilio == "comida") {
        qntd_comida++;
    } else if(utensilio == "remedio") {
        qntd_remedio++;
    } else {
        throw utensilio_invalido_e();
    }
}

/*
void Participante::adicionar_utensilio_agua(int a_consumir) { //Vamos alterar isso
    qntd_agua += a_consumir;
}

void Participante::adicionar_utensilio_comida(int a_consumir) { //Vamos alterar isso
    qntd_comida += a_consumir;
}

void Participante::adicionar_utensilio_remedio(int a_consumir) { //Vamos alterar isso
    qntd_remedio += a_consumir;
}
*/

void Participante::muda_regiao(regioes destino) {
    //ainda tenho q colocar aq a função "pode mudar?"
    _regiao_atual.muda_regiao(destino);
}

void Participante::batalha(Participante& p) {
    std::cout << "O jogador " << get_nome() << " atacou o jogador " << p.get_nome() << std::endl;
    Arma arma_escolhida_atacante = _arma;
    Arma arma_escolhida_defesa = p._arma;

    if(arma_escolhida_atacante.get_poder() > arma_escolhida_defesa.get_poder()) {
        p._vivo = false;
        std::cout << "O jogador " << p.get_nome() << " foi morto" << std::endl;
        _energia *= (1 - 0.1*arma_escolhida_atacante.get_poder());

    } else if(arma_escolhida_atacante.get_poder() < arma_escolhida_defesa.get_poder()) {
        _vivo = false;
        std::cout << "O jogador " << get_nome() << " foi morto" << std::endl;
        p._energia *= (1 - 0.1*arma_escolhida_defesa.get_poder());
    } else {
        _energia *= (1 - 0.1*arma_escolhida_atacante.get_poder());
        p._energia *= (1 - 0.1*arma_escolhida_defesa.get_poder());
    }
}

Regiao Participante::get_Regiao_Atual() {
    return _regiao_atual;
}

void Participante::consumir_utensilio(std::string utensilio, int qntd) {
    if(utensilio == "agua") {
        consumir_utensilios_agua(qntd);
    } else if( utensilio == "comida") {
        consumir_utensilios_comida(qntd);
    } else if(utensilio == "remedio") {
        consumir_utensilios_remedio(qntd);
    } else {
        throw utensilio_invalido_e();
    }
}

void Participante::consumir_utensilios_agua(int a_consumir) {
    if(a_consumir > qntd_agua) {
        throw quantidade_agua_invalida_e();
    }
    qntd_agua -= a_consumir;
    _hidratacao = 100;
}

void Participante::consumir_utensilios_comida(int a_consumir) {
    if(a_consumir > qntd_comida) {
        throw quantidade_comida_invalida_e();
    }
    qntd_comida -= a_consumir;
    _energia = 100;
}

void Participante::consumir_utensilios_remedio(int a_consumir) {
    if(a_consumir > qntd_remedio) {
        throw quantidade_remedio_invalida_e();
    }
    qntd_remedio -= a_consumir;
    _hidratacao += 50;
    _energia += 50;
    if(_energia > 100) {
        _energia = 100;
    }
    if(_hidratacao > 100) {
        _hidratacao = 100;
    }
}

void Participante::buscar_na_regiao() {
    _energia -= 20;
    _hidratacao -= 20;
    float chance_agua = rand() % 10 + 1;
    float chance_comida = rand() % 10 + 1;
    float chance_remedio = rand() % 10 + 1;
    float chance_arma = rand() % 10 + 1;

    if(chance_agua < _regiao_atual.get_chance_agua()) {
        qntd_agua++;
    }

    if(chance_remedio < _regiao_atual.get_chance_remedio()) {
        qntd_remedio++;
    }

    if(chance_comida < _regiao_atual.get_chance_comida()) {
        qntd_comida++;
    }

    if(chance_arma < _regiao_atual.get_chance_arma()) {
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