#include "../third_party/doctest.h"
#include "../include/jogador.h"

TEST_CASE("Testa a saída quando a ação de um jogador é chamada"){
    cout << "------------------------------------------------------------------" << endl;
    cout << "Saída de imprime_status" << endl;

    Regiao Centro(2,2,"centro",0,0,9,3);

    map<string,Regiao*> map_regioes;
    map_regioes[Centro.get_nome_string()] =  &Centro;

    std::set<Participante *> Msm_Regiao_Q_Eu;
    Jogador p = Jogador("Maria", &Centro);
    Msm_Regiao_Q_Eu.insert(&p);

    Jogador p1 = Jogador("P1", &Centro);
    Msm_Regiao_Q_Eu.insert(&p1);

    Jogador p2 = Jogador("P2", &Centro);
    Msm_Regiao_Q_Eu.insert(&p2);

    Jogador p3 = Jogador("P3", &Centro);
    Msm_Regiao_Q_Eu.insert(&p3);


    p.imprime_status(Msm_Regiao_Q_Eu);
    cout << "------------------------------------------------------------------" << endl;

    
    Regiao Floresta(2,1,"floresta",8,7,2,0);
    map_regioes[Floresta.get_nome_string()] =  &Floresta;

    CHECK_NOTHROW(p.muda_regiao("floresta",&map_regioes));
    CHECK(p.get_Regiao_Atual()->get_chance_agua() == 8);
    CHECK(p.get_Regiao_Atual()->get_chance_comida() == 7);
    CHECK(p.get_Regiao_Atual()->get_chance_arma() == 2);
    CHECK(p.get_Regiao_Atual()->get_chance_remedio() == 0);

    // p.muda_regiao(regioes::floresta);

    Arma _nova_arma = Arma(armas::espada);
    p.adicionar_arma(_nova_arma);

    CHECK_EQ(p.get_arma().get_poder(), 4);

    p.buscar_na_regiao();
    p.buscar_na_regiao();
    p.buscar_na_regiao();

    p.imprime_status(Msm_Regiao_Q_Eu);

    cout << "------------------------------------------------------------------" << endl;
}