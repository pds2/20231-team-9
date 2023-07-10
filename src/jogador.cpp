#include "../include/jogador.h"
#include "../third_party/tabulate.hpp"

#include <iostream>
#include <ratio>
#include <string>
#include <set>

using namespace std;

Jogador::Jogador(string nome, Regiao* ponto_partida) : Participante(nome, ponto_partida) { }

void Jogador::definir_acao(set<Participante*> Msm_Regiao_Q_Eu, map<string,Regiao*>* map_regioes) {
    if (get_energia() <= 0){
        morrer();
        std::cout << termcolor::red << get_nome() << termcolor::reset << " morreu de fome." << endl;
        return;
    }
    if (get_hidratacao() <= 0){
        morrer();
        std::cout << termcolor::red << get_nome() << termcolor::reset << " morreu de sede." << endl;
        return;
    }
    
    cout << endl << "------------------------------------------------------------------------------------" << endl;
    cout << termcolor::yellow << get_nome() << termcolor::reset << ", é sua vez de jogar!" << endl << endl;
    imprime_status(Msm_Regiao_Q_Eu);
    char comando;
    string escolha;
    cin >> comando;
    switch (comando){
        case 'a': //atacar
            while(1){
                cin >> escolha;
                if (Msm_Regiao_Q_Eu.size() == 0){
                    cout << "A região está vazia, não há ninguém para atacar!" << endl;
                    cout << "Por isso, você buscará recursos na rodada" << endl;
                    buscar_na_regiao();
                    return;
                }
                for (auto pessoa : Msm_Regiao_Q_Eu){
                    if (pessoa->get_nome() == escolha) {
                        batalha(*pessoa);
                        return;
                    }
                }
                cout << "Não existe essa pessoa na sua região! Insira outro nome" << endl;
            }
            //throw comando_invalido_e{};
            cout << endl << "------------------------------------------------------------------------------------" << endl;
            break;

        case 'm': //mover
        // !! ADICIONEI O CÓDIGO DAQUI 
            imprime_mapa();
            cout << "Digite o nome da região para onde você quer ir:" << endl;
            while(1) {
                cin >> escolha;
                try {
                    return muda_regiao(escolha, map_regioes);
                } catch (regiao_invalida_e) {
                    cout << "Entrada inválida! Essa região não existe. Digite novamente" << endl; 
                } catch (nao_da_para_mudar_para_essa_regiao_e) {
                    cout << "Movimento incorreto! Essa região não é adjacente a que você está. Digite novamente" << endl;
                }

            }
        // !! ADICIONEI O CÓDIGO ATÉ AQUI
            break;

        case 'b': //buscar elementos
            cout << endl << "------------------------------------------------------------------------------------" << endl;
            buscar_na_regiao();
            break;
        case 'u': //usar utensílio
            while(1){
                cin >> escolha;
                if (get_agua() == 0 && get_remedio() == 0 && get_comida() == 0){
                    cout << "Você não tem nada para consumir!" << endl;
                    cout << "Por isso, você buscará recursos nessa rodada" << endl;
                    buscar_na_regiao();
                    return;
                }
                try{
                    return consumir_utensilio(escolha, 1);
                } catch (utensilio_invalido_e){
                    cout << "Utensílio inválido! Nome não registrado no jogo." << endl;
                } catch (quantidade_remedio_invalida_e){
                    cout << "Você não possui nenhum remédio!" << endl;
                }catch (quantidade_agua_invalida_e){ 
                    cout << "Você não possui nenhuma água!" << endl;
                }catch (quantidade_comida_invalida_e){
                    cout << "Você não possui nenhuma comida!" << endl;
                }
            }
            break;
    }
}

void Jogador::imprime_status(set<Participante*> Msm_Regiao_Q_Eu) {
    cout << "STATUS:" << endl;
    cout << termcolor::red << "Energia: " << termcolor::reset << get_energia() << "/100" << endl;
    cout << termcolor::blue << "Hidratação: " << termcolor::reset << get_hidratacao() << "/100" << endl << endl;
    cout << "Seu inventário:" << endl;
    imprime_qntd_utensilios();
    cout << termcolor::magenta << "Arma: " << termcolor::reset << get_arma().get_tipo() << endl << endl;


    cout << "Você está na região " << termcolor::cyan << get_Regiao_Atual()->get_nome_string() << termcolor::reset << "." << endl << endl;
    cout << "Estão na mesma região que você:" << endl;
    if (Msm_Regiao_Q_Eu.size()==0){
        cout << "Você está sozinho..." << endl;
    } else for (auto i: Msm_Regiao_Q_Eu){
        cout << termcolor::blue << i->get_nome() << termcolor::reset << ", ";
    }
    cout << endl << endl;

    cout << "Defina sua ação!" << endl;
    cout << termcolor::underline << "M" << termcolor::reset << "over: " << "Muda para outra região." << endl;
    cout << termcolor::underline << "A" << termcolor::reset << "tacar: " << "Batalha com outro participante." << endl;
    cout << termcolor::underline << "B" << termcolor::reset << "uscar: " << "Procura por recursos na região." << endl;
    cout << termcolor::underline << "U" << termcolor::reset << "sar: " << "Consome um item." << endl << endl;
}

void Jogador::imprime_mapa(){
    tabulate::Table mapa;
    mapa.add_row({"\nCavernas\n\n","\nSavana\n\n", "\nDeserto\n\n"});
    mapa.add_row({"\nRuinas\n\n","\nCentro\n\n", "\nMontanhas\n\n"});
    mapa.add_row({"\nCampo\n\n","\nFloresta\n\n", "\nPantano\n\n"});

    mapa.format().font_style({tabulate::FontStyle::bold});
    mapa.format().width(15);
    mapa.format().font_align(tabulate::FontAlign::center);

    mapa.format()
        .border_top("")
        .border_bottom("")
        .border_left("")
        .border_right("")
        .corner("");
    
    mapa[0][0].format().font_background_color(tabulate::Color::grey);
    mapa[0][1].format().font_background_color(tabulate::Color::yellow);
    mapa[0][2].format().font_background_color(tabulate::Color::yellow);

    mapa[1][0].format().font_background_color(tabulate::Color::magenta);
    mapa[1][1].format().font_background_color(tabulate::Color::white);
    mapa[1][2].format().font_background_color(tabulate::Color::red);

    mapa[2][0].format().font_background_color(tabulate::Color::green);
    mapa[2][1].format().font_background_color(tabulate::Color::green);
    mapa[2][2].format().font_background_color(tabulate::Color::cyan);

    cout << mapa << endl;
}