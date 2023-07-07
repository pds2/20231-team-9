#include "../third_party/doctest.h"
#include "../include/jogador.h"

TEST_CASE("Testa se os atributos de Participante foram corretamente inicializados") {
    Jogador p = Jogador("Maria");
    CHECK_EQ(p.get_Regiao_Atual().get_nome(), regioes::centro);
    CHECK_EQ(p.get_energia(), 100.0);
    CHECK_EQ(p.get_hidratacao(), 100.0);
}

TEST_CASE("Testa se o personagem está na região correta") {
    Jogador p = Jogador("Maria");
    Regiao _floresta(8,7,2,0,regioes::floresta,2,1);
    p.muda_regiao("floresta");
    CHECK_EQ(p.get_Regiao_Atual().get_nome(), regioes::floresta);
}

TEST_CASE("Testa se a mudança de arma está ocorrendo corretamente") {
    Jogador p = Jogador("Maria");
    Arma _nova_arma = Arma(armas::espada);
    p.adicionar_arma(_nova_arma);
    CHECK_EQ(p.get_arma().get_tipo(), armas::espada);
}

TEST_CASE("Testa a função batalha") {
    Jogador p = Jogador("Maria");
    Arma _nova_arma = Arma(armas::espada);
    p.adicionar_arma(_nova_arma);

    Jogador p2 = Jogador("Pedro");
    Arma _nova_arma2 = Arma(armas::faca);
    p2.adicionar_arma(_nova_arma2);
    p.batalha(p2);
    CHECK_EQ(p2.get_vivo(), false);
    CHECK_EQ(p.get_energia(), 60);
}

TEST_CASE("Testa o lançamento das excessões") {
    Jogador p = Jogador("Maria");
    p.muda_regiao("floresta");

    Regiao _floresta(8,7,2,0,floresta,2,1);
    CHECK_EQ(p.get_Regiao_Atual(), _floresta);

    CHECK_THROWS_AS(p.muda_regiao("praia"), regiao_invalida_e);
}

TEST_CASE("Testa a função 'consumir_utensilio()'") {
    Jogador p = Jogador("Maria");
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
// TEST_CASE("Testa a função buscar_na_regiao()") {
//     Jogador p = Jogador("Maria");
//     CHECK_EQ(p.get_agua(), 0);
//     CHECK_EQ(p.get_remedio(), 0);
//     CHECK_EQ(p.get_comida(), 0);

//     p.muda_regiao(regioes::floresta);
//     p.buscar_na_regiao();
// }