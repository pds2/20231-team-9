#include "../include/sistema.h"

#include <iostream>
#include <set>
#include <algorithm>
#include <random>

Sistema::Sistema() {
    contador_dias_ = 1;
    contador_noites_ = 1;
    contador_vivos_ = 0;
}

void Sistema::criar_jogador(string nome) {
    //IDEIA DE CÓDIGO SE _vivos FOR VECTOR
    // for(Participante& this_one : _vivos) {
    //     if(nome == this_one.get_nome()) {
    //         throw participante_ja_existe_e();
    //     }
    // }
    auto pair = participantes_.begin();
    while(pair != participantes_.end()) {
        if(nome == pair->first) {
            throw participante_ja_existe_e();
        }
        pair = next(pair);
    }

    Jogador *novo_jogador = new Jogador(nome);
    participantes_[nome] = novo_jogador;
    contador_vivos_++;
    // _vivos[nome] = Participante(nome,distrito);
    // _vivos.push_back(Participante(nome, distrito));
}

// !!! IDEIA DE NOVA FUNÇÃO CRIAR_BOT
// void Sistema::criar_bot(int n) {
//     std::string nome_bot = "Bot ";
//     for(int i = 0; i < n; i++) {
//         nome_bot += to_string(i+1);
//         Bot *novo_bot = new Bot(novo_bot);
//         participantes_[nome_bot] = novo_bot;
//     }
// }
void Sistema::criar_bot(string nome) {
    auto pair = participantes_.begin();
    while(pair != participantes_.end()) {
        if(nome == pair->first) {
            throw participante_ja_existe_e();
        }
        pair = next(pair);
    }

    Jogador *novo_bot = new Jogador(nome);
    participantes_[nome] = novo_bot;
    contador_vivos_++;
}

void Sistema::inicio() {
    cout << "O jogo começou! Jogadores estão no centro!" << endl;
    cout << "Nossos jogadores são: ";
    // set<Jogador *> jogadores = _mapa.get_participantes_centro();
    auto it = participantes_.begin();
    while(it != participantes_.end()) {
        cout << it->second->get_nome() << endl;
        it = next(it);
    }
}

// void Sistema::inicio() {
//     _mapa.inicio(_vivos);
//     cout << "O jogo começou! Jogadores estão no centro!" << endl;
//     cout << "Nossos jogadores sao: ";
//     vector<string> jogadores = _mapa.get_participantes_centro();
//     int i = 0;
//     while(i <= jogadores.size() - 2) {
//         cout << jogadores[i] << ", ";
//         i++;
//     }
//     cout << jogadores[i + 1] << "." << endl; 
// }

// void Sistema::morrer(Participante &fulano) {
//     _mapa.morrer(&fulano);
//     _mortos.push_back(fulano.get_nome());
//     auto pair = _vivos.begin();
//     while(pair != _vivos.end()) {
//         if(pair->first == fulano.get_nome()) {
//             _vivos.erase(pair);
//         }
//     }
// }

map<string, Participante*> Sistema::get_participantes() {
    return participantes_;
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
    regioes r = fulano->get_Regiao_Atual().get_nome();

    for (auto pair = participantes_.begin(); pair != participantes_.end(); ++pair) {
        if (pair->second->get_Regiao_Atual().get_nome() == r) {
            s.insert(pair->second);
        }
    }

    return s;
}


void Sistema::Rodada() {
    // Pegando vetor com os jogadores embaralhados:
    cout << "hello";

    vector<Participante*> participantes = EmbaralhaParticipantesVivos();

    // Percorrendo:
    for (Participante* participante_da_vez : participantes) {
        // Definindo a ação:

        // Recolhendo um set com os participantes na mesma região que
        // o jogador da vez:
        set<Participante*> s = ParticipanteNaMesmaRegiao(participante_da_vez);
        participante_da_vez->definir_acao(s);

        //Atualizando o contador de vivos depois de algm jogar:
        int aux = 0;
        auto pair = participantes_.begin();
        while(pair != participantes_.end()) {
            if(pair->second->get_vivo() == true) {
                aux++;
            }
            else {
                _mortos.push_back(pair->second);
                participantes_.erase(pair);
            }
            pair = next(pair);
        }
        contador_vivos_ = aux;
    }
}

void Sistema::Jogo() {
    //Chama Rodadas até ter apenas um participante vivo:
    while (contador_vivos_ > 1) {
        //Informa o Dia em que a rodada acontece
        cout << "Dia " << contador_dias_ << ":" << endl;
       
        Rodada();
        cout <<"alo2";
        contador_dias_++;

        // Roda uma rodada "Noite" a não ser q sobre apenas um participante
        // do "Dia" anterior
        if(contador_vivos_ > 1) {
            cout << "Noite " << contador_noites_ << ":" << endl;
            Rodada();
            
            //faz um resumo dos personagens que morreram no dia
            cout << "Personagens que morreram nessa rodada:" <<endl;
            for(Participante *p : _mortos) {
                cout << p->get_nome() << endl;
            }
            _mortos.clear();
            
            contador_noites_++;
        }
    }
}