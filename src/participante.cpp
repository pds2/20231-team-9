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

int Participante::get_agua(){
    return qntd_agua;
}

int Participante::get_remedio(){
    return qntd_remedio;
}

int Participante::get_comida(){
    return qntd_comida;
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

void Participante::morrer(){
    _vivo = false;
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

void Participante::muda_regiao(std::string destino) {
    regioes destino_enum;
    if(destino == "centro") {
        destino_enum = centro;
    } else if(destino == "floresta") {
        destino_enum = floresta;
    } else if(destino == "deserto") {
        destino_enum = deserto;
    } else if(destino == "pantano") {
        destino_enum = pantano;
    } else if(destino == "campo") {
        destino_enum = campo;
    } else if(destino == "montanhas") {
        destino_enum = montanhas;
    } else if(destino == "ruinas") {
        destino_enum = ruinas;
    } else if(destino == "cavernas") {
        destino_enum = cavernas;
    } else if(destino == "savana") {
        destino_enum = savana;
    } else {
        throw regiao_invalida_e();
    }

    _regiao_atual.muda_regiao(destino_enum);
    _hidratacao -= 20;
    std::cout << get_nome() << " correu para a região " << destino << endl;
}

void Participante::muda_regiao(regioes destino) {
    _regiao_atual.muda_regiao(destino);
    _hidratacao -= 20;
    std::cout << get_nome() << " correu para a região " << stringify(destino) << endl;
}

void Participante::batalha(Participante& p) {
    std::cout << "O jogador " << get_nome() << " atacou o jogador " << p.get_nome() << "." << std::endl;
    Arma arma_escolhida_atacante = _arma;
    Arma arma_escolhida_defesa = p._arma;

    if(arma_escolhida_atacante.get_poder() > arma_escolhida_defesa.get_poder()) {
        p._vivo = false;
        std::cout << "O jogador " << p.get_nome() << " foi morto em batalha." << std::endl;
        _energia -= (10*arma_escolhida_atacante.get_poder());

    } else if(arma_escolhida_atacante.get_poder() < arma_escolhida_defesa.get_poder()) {
        _vivo = false;
        std::cout << "O jogador " << get_nome() << " foi morto em batalha." << std::endl;
        p._energia -= (10*arma_escolhida_defesa.get_poder());
    } else {
        std::cout << "Mas nada acontece..." << endl;
        _energia -= (10*arma_escolhida_atacante.get_poder());
        p._energia -= (10*arma_escolhida_defesa.get_poder());
    }
}

Regiao Participante::get_Regiao_Atual() {
    return _regiao_atual;
}

void Participante::consumir_utensilio(std::string utensilio, int qntd) {
    if(utensilio == "agua") {
        consumir_utensilios_agua(qntd);
        std::cout << get_nome() << " bebeu água." << endl;
    } else if( utensilio == "comida") {
        consumir_utensilios_comida(qntd);
        std::cout << get_nome() << " comeu um lanche." << endl;
    } else if(utensilio == "remedio") {
        consumir_utensilios_remedio(qntd);
        std::cout << get_nome() << " tomou seus remédios." << endl;
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
    _energia -= 15;
    _hidratacao -= 15;
    float chance_agua = rand() % 10 + 1;
    float chance_comida = rand() % 10 + 1;
    float chance_remedio = rand() % 10 + 1;
    float chance_arma = rand() % 10 + 1;

    if(chance_agua < _regiao_atual.get_chance_agua()) {
        qntd_agua++;
        std::cout << get_nome() << " encontrou água em suas buscas." << endl;
    }

    if(chance_remedio < _regiao_atual.get_chance_remedio()) {
        qntd_remedio++;
        std::cout << get_nome() << " achou um kit de primeiros socorros." << endl;
    }

    if(chance_comida < _regiao_atual.get_chance_comida()) {
        qntd_comida++;
        std::cout << get_nome() << " achou uma fonte de alimento." << endl;
    }

    if(chance_arma < _regiao_atual.get_chance_arma()) {
        int qual_arma = rand() % 10 + 1;
        if(qual_arma <= 4) {
            Arma _faca(faca);
            adicionar_arma(_faca);
            std::cout << get_nome() << " encontrou uma faca." << endl;
        } else if(qual_arma <= 7) {
            Arma _arco(arco);
            adicionar_arma(_arco);
            std::cout << get_nome() << " encontrou um arco e flecha." << endl;
        } else if(qual_arma <= 8) {
            Arma _espada(espada);
            adicionar_arma(_espada);
            std::cout << get_nome() << " encontrou uma espada." << endl;
        } else if(qual_arma == 10) {
            Arma _machado(machado);
            adicionar_arma(_machado);
            std::cout << get_nome() << " encontrou um machado! Agora ele está imparável!" << endl;
        }
    }
}