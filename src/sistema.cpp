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
    novo_jogador->muda_regiao("centro", &map_regioes_);
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

    Bot *novo_bot = new Bot(nome);
    participantes_[nome] = novo_bot;
    novo_bot->muda_regiao("centro", &map_regioes_);
    contador_vivos_++;
}

void Sistema::inicio() {
    cout << "O jogo começou! Jogadores estão no centro!" << endl;
    cout << "Nossos jogadores são: " << endl;
    // set<Jogador *> jogadores = _mapa.get_participantes_centro();
    auto it = participantes_.begin();
    while(it != participantes_.end()) {
        cout << it->second->get_nome() << endl;
        it = next(it);
    }
    cout << endl;
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
    cout << "Iniciando uma rodada!" << endl << endl;

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
            // if (participante != participantes.end()){
            //     participante++;
            //     }
            }
        }
    contador_vivos_ = aux;

    cout << "-----------------------------------------------------------------" << endl;
    cout << "Personagens que morreram nessa rodada:" <<endl;
    for(Participante *p : _mortos) {
        cout << p->get_nome() << endl;
    }
    cout << "-----------------------------------------------------------------" << endl;
    _mortos.clear();
}

void Sistema::Jogo() {
    //Chama Rodadas até ter apenas um participante vivo:
    while (contador_vivos_ > 1) {
        //Informa o Dia em que a rodada acontece
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Dia " << contador_dias_noites_ << ":" << endl << endl;
        cout << "-----------------------------------------------------------------" << endl;
       
        Rodada();

        // Roda uma rodada "Noite" a não ser q sobre apenas um participante
        // do "Dia" anterior
        if(contador_vivos_ > 1) {
            cout << "-----------------------------------------------------------------" << endl;
            cout << "Noite " << contador_dias_noites_ << ":" << endl;
            cout << "-----------------------------------------------------------------" << endl;

            Rodada();
            contador_dias_noites_++;
            //faz um resumo dos personagens que morreram no dia
        }
    }
    cout << "-----------------------------------------------------------------" << endl;
    cout << "FIM DE JOGO!" << endl;
    for (auto pair = participantes_.begin(); pair != participantes_.end(); ++pair) {
        if (pair->second->get_vivo()) {
            cout << pair->second->get_nome() << " foi o grande campeão!" << endl;
        }
    }
    cout << "PARABÉNS!";
}