#include "../third_party/doctest.h"
#include "../include/jogador.h"
#include "../include/sistema.h"

TEST_CASE("Testa se os atributos de Participante foram corretamente inicializados") {
    // // Criando as Regioes:
    Regiao Centro(2,2,"centro",0,0,9,3);
    
    Jogador p = Jogador("Maria", &Centro);
    CHECK_EQ(p.get_Regiao_Atual()->get_nome_string(), "centro");
    CHECK_EQ(p.get_energia(), 100.0);
    CHECK_EQ(p.get_hidratacao(), 100.0);
}

// TEST_CASE("Testa se o personagem está na região correta") {
//     Regiao Centro(2,2,"centro",0,0,9,3);
//     Jogador p = Jogador("Maria", &Centro);

//     Regiao Floresta(2,1,"floresta",8,7,2,0);
//     Regiao Pantano(3,1,"pantano",10,3,1,0);
//     Regiao Montanhas(3,2,"montanhas",4,3,5,0);
//     Regiao Deserto(3,3,"deserto",2,5,5,0);
//     Regiao Ruinas(1,2,"ruinas",0,2,5,4);
//     Regiao Campo(1,1,"campo",6,8,2,0);
//     Regiao Cavernas(1,3,"cavernas",7,3,5,0);
//     Regiao Savana(2,3,"savana",3,6,4,1);
//     Sistema jogo;

//     // Inserindo as Regioes no jogo:
//     jogo.insere_regiao(&Centro);
//     jogo.insere_regiao(&Floresta);
//     jogo.insere_regiao(&Pantano);
//     jogo.insere_regiao(&Montanhas);
//     jogo.insere_regiao(&Deserto);
//     jogo.insere_regiao(&Ruinas);
//     jogo.insere_regiao(&Campo);
//     jogo.insere_regiao(&Cavernas);
//     jogo.insere_regiao(&Savana);

//     p.muda_regiao("floresta", &(jogo.get_map_regioes()));
//     CHECK_EQ(p.get_Regiao_Atual()->get_nome_string(), "floresta");
// }

TEST_CASE("Testa se a mudança de arma está ocorrendo corretamente") {
    Regiao Centro(2,2,"centro",0,0,9,3);
    Jogador p = Jogador("Maria", &Centro);
    Arma _nova_arma = Arma(armas::espada);
    p.adicionar_arma(_nova_arma);
    CHECK_EQ(p.get_arma().get_tipo(), armas::espada);
}

TEST_CASE("Testa a função batalha") {
    Regiao Centro(2,2,"centro",0,0,9,3);
    Jogador p = Jogador("Maria", &Centro);
    Arma _nova_arma = Arma(armas::espada);
    p.adicionar_arma(_nova_arma);

    Jogador p2 = Jogador("Pedro", &Centro);
    Arma _nova_arma2 = Arma(armas::faca);
    p2.adicionar_arma(_nova_arma2);
    p.batalha(p2);
    CHECK_EQ(p2.get_vivo(), false);
    CHECK_EQ(p.get_energia(), 60);
}

// TEST_CASE("Testa o lançamento das excessões") {
//     Jogador p = Jogador("Maria");
//     p.muda_regiao("floresta");

//     Regiao _floresta(8,7,2,0,floresta,2,1);
//     CHECK_EQ(p.get_Regiao_Atual(), _floresta);

//     CHECK_THROWS_AS(p.muda_regiao("praia"), regiao_invalida_e);
// }

TEST_CASE("Testa a função 'consumir_utensilio()'") {
    Regiao Centro(2,2,"centro",0,0,9,3);
    Jogador p = Jogador("Maria", &Centro);
    p.adicionar_utensilio("agua", 1);
    p.adicionar_utensilio("remedio", 1);
    p.adicionar_utensilio("agua", 1);
    p.adicionar_utensilio("comida", 1);

    CHECK_EQ(p.get_agua(), 2);
    CHECK_EQ(p.get_comida(), 1);
    CHECK_EQ(p.get_remedio(), 1);
    CHECK_THROWS_AS(p.adicionar_utensilio("suco", 1), utensilio_invalido_e);

    p.consumir_utensilio("agua", 1);
    p.consumir_utensilio("remedio", 1);
    p.consumir_utensilio("comida", 1);

    CHECK_THROWS_AS(p.consumir_utensilio("remedio", 1), quantidade_remedio_invalida_e);
    CHECK_THROWS_AS(p.consumir_utensilio("cafe", 1), utensilio_invalido_e);

}

TEST_CASE("Testa a função muda_regiao()") {
    Regiao Centro(2,2,"centro",0,0,9,3);
    Jogador p = Jogador("Maria", &Centro);

    map<string,Regiao*> map_regioes;
    Regiao Floresta(2,1,"floresta",8,7,2,0);
    Regiao Deserto(3,3,"deserto",2,5,5,0);
    map_regioes[Centro.get_nome_string()] =  &Centro;
    map_regioes[Floresta.get_nome_string()] = &Floresta;
    map_regioes[Deserto.get_nome_string()] = &Deserto;

    CHECK(p.get_Regiao_Atual()->get_nome_string() == "centro");

    p.muda_regiao("floresta",&map_regioes);
    CHECK(p.get_Regiao_Atual()->get_nome_string() == "floresta");
    CHECK(p.get_Regiao_Atual()->get_chance_agua() == 8);
    CHECK(p.get_Regiao_Atual()->get_chance_comida() == 7);
    CHECK(p.get_Regiao_Atual()->get_chance_arma() == 2);
    CHECK(p.get_Regiao_Atual()->get_chance_remedio() == 0);
    CHECK(p.get_Regiao_Atual()->get_x() == 2);
    CHECK(p.get_Regiao_Atual()->get_y() == 1);

    CHECK_THROWS_AS(p.muda_regiao("deserto",&map_regioes), nao_da_para_mudar_para_essa_regiao_e);
}

TEST_CASE("Testa a função buscar_na_regiao()") {
    Regiao Centro(2,2,"centro",0,0,9,3);
    Jogador p = Jogador("Maria", &Centro);

    Regiao Teste1(2,1,"teste1",10,11,0,0);
    map<string,Regiao*> map_regioes;
    map_regioes[Teste1.get_nome_string()] =  &Teste1;

    p.muda_regiao("teste1",&map_regioes);
    p.buscar_na_regiao();
    CHECK_EQ(p.get_agua(), 1);
    CHECK_EQ(p.get_comida(), 1);
    CHECK_EQ(p.get_remedio(), 0);

    Regiao Teste2(1,1,"teste2",0,0,10,10);
    map_regioes[Teste2.get_nome_string()] =  &Teste2;
    p.muda_regiao("teste2",&map_regioes);
    p.buscar_na_regiao();
    CHECK_EQ(p.get_agua(), 1);
    CHECK_EQ(p.get_comida(), 1);
    CHECK_EQ(p.get_remedio(), 1);

}