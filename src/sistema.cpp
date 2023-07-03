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

void Sistema::criar_jogador(string nome, int distrito) {
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
    
    if(distrito > 12 || distrito < 1) {
        throw distrito_invalido_e();
    }

    Jogador *novo_jogador = new Jogador(nome, distrito);
    participantes_[nome] = novo_jogador;
    _mapa.inicio(novo_jogador);
    contador_vivos_++;
    // _vivos[nome] = Participante(nome,distrito);
    // _vivos.push_back(Participante(nome, distrito));
}

void Sistema::criar_bot(string nome, int distrito) {
    auto pair = participantes_.begin();
    while(pair != participantes_.end()) {
        if(nome == pair->first) {
            throw participante_ja_existe_e();
        }
        pair = next(pair);
    }
    
    if(distrito > 12 || distrito < 1) {
        throw distrito_invalido_e();
    }

    Jogador *novo_bot = new Jogador(nome, distrito);
    participantes_[nome] = novo_bot;
    contador_vivos_++;
    _mapa.inicio(novo_bot);
}

void Sistema::inicio() {
    cout << "O jogo começou! Jogadores estão no centro!" << endl;
    cout << "Nossos jogadores são: ";
    set<Jogador *> jogadores = _mapa.get_participantes_centro();
    auto it = jogadores.begin();
    while(it != jogadores.end()) {
        cout << (*it)->get_nome() << endl;
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

vector<string> Sistema::EmbaralhaParticipantesVivos() {
    vector<string> v;
    // Coloca o os jogadores que estão vivos no vetor:
    auto pair = participantes_.begin();
    while(pair != participantes_.end()) {
        if(pair->second->get_vivo() == true) {
            v.push_back(pair->second->get_nome());
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

    // busco o nome(enum) da regiao atual do participante
    regioes r = fulano->get_Regiao_Atual().get_nome();

    auto pair = participantes_.begin();
    while(pair != participantes_.end()) {
        if(pair->second->get_Regiao_Atual().get_nome() == r) {
            s.insert(pair->second);
        }
    }
    return s;
}

void Sistema::Rodada() {
    //Pegando Vetor com os Jogadores embaralhados:
    vector<string> participantes = EmbaralhaParticipantesVivos();

    //Percorrendo:
    for(string participante : participantes) {
        Participante *ParticipanteDaVez;
        //Procurando o participante da vez
        auto pair = participantes_.begin();
        while(pair != participantes_.end()) {
            if(pair->second->get_nome() == participante) {
                ParticipanteDaVez == pair->second;
                break;
            }
        }

        // Definindo a ação:

        // Recolhendo um set com os participantes na mesma regiao que
        // o jogador da vez:
        set<Participante*> s = ParticipanteNaMesmaRegiao(ParticipanteDaVez);
        ParticipanteDaVez->definir_acao(s);
    } 
}

void Sistema::Jogo() {
    //Chama Rodadas até ter apenas um participante vivo:
    while (contador_vivos_ > 1) {
        //Informa o Dia em que a rodada acontece
        cout << "Dia " << contador_dias_ << ":" << endl;
        Rodada();
        contador_dias_++;

        // Roda uma rodada "Noite" a não ser q sobre apenas um participante
        // do "Dia" anterior
        if(contador_vivos_ > 1) {
            cout << "Noite " << contador_noites_ << ":" << endl;
            Rodada();
            contador_noites_++;
        }
    }
}

// void Sistema::Rodada() {
//     for(string nome : _mapa.get_td_mundo()) {

//         Participante *jogador;
//         //achando o jogador da vez
//         auto pair = _vivos.begin();
//         while(pair != _vivos.end()) {
//             if(nome == pair->second.get_nome()) {
//                 jogador = pair->second;
//             }

//             cout << nome << ", você está na região " << endl;
//             cout << endl << "Os jogadores que estão na mesma regiao que voce sao: ";


//             //Pergunta o que o jogador quer fazer
//             cout << nome <<  ", o que voce quer fazer?" << endl;
//             cout << "1. Atacar." << endl;
//             cout << "2. Buscar." << endl;
//             cout << "3. Sei la." << endl;

//             //Realizando Ação:
//             int resposta;
//             switch (resposta) {
//             case 1: // Case Atacar
//                 cout << "Quem voce quer atacar?" << endl;

//                 //achando o jogador da vez
//                 auto pair = _vivos.begin();
//                 while(pair != _vivos.end()) {
//                     if(nome == pair->second.get_nome()) {
//                         pair->second.batalha();
//                     }
//                 }
//                 break;
            
//             case 2: // Case Buscar
//                 /* code */
//                 break;
            
//             case 3: // Case Sla
//                 /* code */
//                 break;

//             default:
//                 break;
//             }
//         }
//     }
// }