#include "../include/jogador.h"

#include <iostream>
#include <ratio>
#include <string>
#include <set>

using namespace std;

Jogador::Jogador(string nome) : Participante(nome) { }

void Jogador::definir_acao(set<Participante*> Msm_Regiao_Q_Eu, map<string,Regiao*>* map_regioes) {
    if (get_energia() <= 0){
        morrer();
        std::cout << get_nome() << " morreu de fome." << endl;
        return;
    }
    if (get_hidratacao() <= 0){
        morrer();
        std::cout << get_nome() << " morreu de sede." << endl;
        return;
    }
    
    cout << endl << "------------------------------------------------------------------------------------" << endl;
    cout << get_nome() << ", é sua vez de jogar!" << endl << endl;
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
    cout << "Energia: " << get_energia() << "/100" << endl;
    cout << "Hidratação: " << get_hidratacao() << "/100" << endl << endl;
    cout << "Seu inventário:" << endl;
    imprime_qntd_utensilios();
    cout << "Arma: " << get_arma().get_tipo() << endl << endl;


    cout << "Você está na região " << get_Regiao_Atual()->get_nome_string() << "." << endl << endl;
    cout << "Estão na mesma região que você:" << endl;
    if (Msm_Regiao_Q_Eu.size()==0){
        cout << "Você está sozinho..." << endl;
    } else for (auto i: Msm_Regiao_Q_Eu){
        cout << i->get_nome() << ", ";
    }
    cout << endl << endl;

    cout << "Defina sua ação!" << endl;
    cout << "Mover: Muda para outra região." << endl;
    cout << "Atacar: Batalha com outro participante." << endl;
    cout << "Buscar: Procura por recursos na região." << endl;
    cout << "Usar: Consome um item." << endl << endl;
}