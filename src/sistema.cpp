#include "../include/sistema.h"

#include <iostream>

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

    Participante *novo_participante = new Participante(nome, distrito);
    _vivos[nome] = *novo_participante;
    // _vivos[nome] = Participante(nome,distrito);
    // _vivos.push_back(Participante(nome, distrito));
}

void Sistema::inicio() {
    _mapa.inicio(_vivos);
    cout << "O jogo começou! Jogadores estão no centro!" << endl;
    cout << "Nossos jogadores sao: ";
    vector<string> jogadores = _mapa.get_participantes_centro();
    int i = 0;
    while(i <= jogadores.size() - 2) {
        cout << jogadores[i] << ", ";
        i++;
    }
    cout << jogadores[i + 1] << "." << endl; 
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

void Sistema::Rodada() {
    for(string nome : _mapa.get_td_mundo()) {

        Participante *jogador;
        //achando o jogador da vez
        auto pair = _vivos.begin();
        while(pair != _vivos.end()) {
            if(nome == pair->second.get_nome()) {
                jogador = pair->second;
            }

            cout << nome << ", você está na região " << endl;
            cout << endl << "Os jogadores que estão na mesma regiao que voce sao: ";


            //Pergunta o que o jogador quer fazer
            cout << nome <<  ", o que voce quer fazer?" << endl;
            cout << "1. Atacar." << endl;
            cout << "2. Buscar." << endl;
            cout << "3. Sei la." << endl;

            //Realizando Ação:
            int resposta;
            switch (resposta) {
            case 1: // Case Atacar
                cout << "Quem voce quer atacar?" << endl;

                //achando o jogador da vez
                auto pair = _vivos.begin();
                while(pair != _vivos.end()) {
                    if(nome == pair->second.get_nome()) {
                        pair->second.batalha();
                    }
                }
                break;
            
            case 2: // Case Buscar
                /* code */
                break;
            
            case 3: // Case Sla
                /* code */
                break;

            default:
                break;
            }
        }
    }
}