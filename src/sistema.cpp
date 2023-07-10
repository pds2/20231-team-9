#include "../include/sistema.h"

#include <iostream>
#include <set>
#include <algorithm>
#include <random>

Sistema::Sistema() {
    contador_dias_noites_ = 1;
    contador_vivos_ = 0;
}

void Sistema::insere_regiao(Regiao* lugar) {
    map_regioes_[lugar->get_nome_string()] = lugar;
}

void Sistema::criar_jogador(string nome, Regiao* ponto_partida) {
    auto pair = participantes_.begin();
    while(pair != participantes_.end()) {
        if(nome == pair->first) {
            throw participante_ja_existe_e();
        }
        pair = next(pair);
    }

    Jogador *novo_jogador = new Jogador(nome, ponto_partida);
    participantes_[nome] = novo_jogador;
    contador_vivos_++;
}

void Sistema::criar_bot(string nome, Regiao* ponto_partida) {
    auto pair = participantes_.begin();
    while(pair != participantes_.end()) {
        if(nome == pair->first) {
            throw participante_ja_existe_e();
        }
        pair = next(pair);
    }

    Bot *novo_bot = new Bot(nome, ponto_partida);
    participantes_[nome] = novo_bot;
    contador_vivos_++;
}

void Sistema::inicio() {
    cout << termcolor::blue << endl << termcolor::reset;
    cout << termcolor::blue << "-----------------------------------------------------------------" << endl << termcolor::reset;
    cout << termcolor::blue << "Início da partida:" << endl << termcolor::reset; 
    cout << termcolor::blue << "-----------------------------------------------------------------" << termcolor::reset << endl;
    cout << "Jogadores estão no centro!" << endl;
    cout << "Nossos jogadores são: " << endl;
    auto it = participantes_.begin();
    while(it != participantes_.end()) {
        cout << termcolor::blue << it->second->get_nome() << endl;
        it = next(it);
    }
    cout << termcolor::reset << endl;
}

map<string, Participante*> Sistema::get_participantes() {
    return participantes_;
}

map<string,Regiao*> Sistema::get_map_regioes() {
    return map_regioes_;
}

vector<Participante*> Sistema::EmbaralhaParticipantesVivos() {
    vector<Participante*> v;
    // Coloca os jogadores que estão vivos no vetor:
    for (auto pair = participantes_.begin(); pair != participantes_.end(); ++pair) {
        if (pair->second->get_vivo() == true) {
            v.push_back(pair->second);
        }
    }

    // Criar um gerador de números aleatórios
    random_device rd;
    mt19937 g(rd());

    // Embaralhar o vetor usando a função std::shuffle
    shuffle(v.begin(), v.end(), g);

    return v;
}


set<Participante*> Sistema::ParticipanteNaMesmaRegiao(Participante* fulano) {
    set<Participante*> s;

    // Busco o nome (enum) da região atual do participante
    string r = fulano->get_Regiao_Atual()->get_nome_string();

    for (auto pair = participantes_.begin(); pair != participantes_.end(); ++pair) {
        if (pair->second->get_Regiao_Atual()->get_nome_string() == r && pair->second->get_vivo() && pair->second->get_nome() != fulano->get_nome()) {
            s.insert(pair->second);
        }
    }

    return s;
}


void Sistema::Rodada() {
    // Pegando vetor com os jogadores embaralhados:
    vector<Participante*> participantes = EmbaralhaParticipantesVivos();

    // Percorrendo:
    for (Participante* participante_da_vez : participantes) {
        // Definindo a ação:

        // Recolhendo um set com os participantes na mesma região que
        // o jogador da vez:
        set<Participante*> s = ParticipanteNaMesmaRegiao(participante_da_vez);
        if(participante_da_vez->get_vivo()){
            participante_da_vez->definir_acao(s,&map_regioes_);
        }
    }
   
   //Atualizando o contador de vivos depois da rodada:
    int aux = 0;
    for (auto participante = participantes.begin(); participante != participantes.end();) {
        if((*participante)->get_vivo() == true) {
            aux++;
            participante++;
        }
        else {
            _mortos.push_back(*participante);
            participante = participantes.erase(participante);
        }
    }
    contador_vivos_ = aux;

    cout << termcolor::red << endl << termcolor::reset;
    cout << termcolor::red << "-----------------------------------------------------------------" << endl << termcolor::reset;
    cout << termcolor::red << "Personagens que morreram nessa rodada:" << endl;
    for(Participante *p : _mortos) {
        cout << termcolor::red << p->get_nome() << endl << termcolor::reset;
    }
    cout << termcolor::red << "-----------------------------------------------------------------" << termcolor::reset << endl;
    _mortos.clear();
}

void Sistema::Jogo() {
    //Chama Rodadas até ter apenas um participante vivo:
    while (contador_vivos_ > 1) {
        //Informa o Dia em que a rodada acontece
        cout << termcolor::yellow << endl << termcolor::reset;
        cout << termcolor::yellow << "-----------------------------------------------------------------" << endl << termcolor::reset;
        cout << termcolor::yellow << "Dia " << contador_dias_noites_ << ":" << endl << termcolor::reset;
        cout << termcolor::yellow << "-----------------------------------------------------------------" << termcolor::reset << endl;
       
        Rodada();

        // Roda uma rodada "Noite" a não ser q sobre apenas um participante
        // do "Dia" anterior
        if(contador_vivos_ > 1) {
            cout << termcolor::blue << endl << termcolor::reset;
            cout << termcolor::blue << "-----------------------------------------------------------------" << endl << termcolor::reset;
            cout << termcolor::blue << "Noite " << contador_dias_noites_ << ":" << endl << termcolor::reset; 
            cout << termcolor::blue << "-----------------------------------------------------------------" << termcolor::reset << endl;
            Rodada();
            contador_dias_noites_++;
        }
    }
    cout << endl << "FIM DE JOGO!" << endl;
    if(contador_vivos_ == 0){
        cout << "OH NÃO! OS FINALISTAS MORRERAM JUNTOS! NÃO TEMOS UM CAMPEÃO...";
    } else{
        for (auto pair = participantes_.begin(); pair != participantes_.end(); ++pair) {
            if (pair->second->get_vivo()) {
                cout << termcolor::blue << pair->second->get_nome() << termcolor::yellow << " foi coroado o grande campeão!" << endl;
            }
        }
        cout << "PARABÉNS!" << termcolor::reset << endl << endl << endl;
    }
}

void Sistema::imprime_titulo(){
    cout << "Seja bem vindo ao:" << endl;

    cout << " _____  _              _         _           " << endl;
    cout << "|   __||_| _____  _ _ | | ___  _| | ___  ___ " << endl;
    cout << "|__   || ||     || | || || .'|| . || . ||  _|" << endl;
    cout << "|_____||_||_|_|_||___||_||__,||___||___||_|  " << endl;

    cout << termcolor::color<221,139,38>;
    cout << "    __                     " << endl;
    cout << " __|  | ___  ___  ___  ___ " << endl;
    cout << "|  |  || . || . || . ||_ -|" << endl;
    cout << "|_____||___||_  ||___||___|" << endl;
    cout << "            |___|          " << endl;

    cout << " _____                               " << endl;
    cout << "|  |  | ___  ___  ___  ___  ___  ___ " << endl;
    cout << "|  |  || . ||  _|| .'||- _|| -_||_ -|" << endl;
    cout << " \\___/ |___||_|  |__,||___||___||___|" << endl;
    cout << termcolor::reset << endl;
    
    cout << "Um projeto de PDS2 realizado por:" << endl;
    cout << termcolor::blue << "Arthur Buzelin" << endl;
    cout << termcolor::magenta << "Cecília Junqueira" << endl;
    cout << termcolor::green << "Felipe Gomide" << endl;
    cout << termcolor::red << "Lucas Junqueira" << termcolor::reset << endl << endl;

    cout << "Consulte nosso README no GitHub!" << endl;

}