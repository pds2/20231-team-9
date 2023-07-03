#include "../third_party/doctest.h"
#include "../include/regiao.h"


TEST_CASE("Testa se os atributos são inicializados") {
    Regiao r = Regiao();
    CHECK(r.get_chance_agua() == 0);
    CHECK(r.get_chance_arma() == 9);
    CHECK(r.get_chance_comida() == 0);
    CHECK(r.get_chance_remedio() == 9);
    CHECK(r.get_nome() == regioes::centro);
    CHECK(r.get_x() == 2);
    CHECK(r.get_y() == 2);
}

TEST_CASE("Testa se a regiao muda corretamente e se os erros são lançados") {
    Regiao r = Regiao();
    int x,y,agua,comida,arma,remedio;
    regioes nome = regioes::centro;
    r.muda_regiao(floresta);
    nome = r.get_nome();
    x = r.get_x();
    y = r.get_y();
    agua = r.get_chance_agua();
    comida = r.get_chance_comida();
    arma = r.get_chance_arma();
    remedio = r.get_chance_remedio();
    CHECK(x == 2);
    CHECK(y == 1);
    CHECK(agua == 8);
    CHECK(comida == 7);
    CHECK(arma == 2);
    CHECK(remedio == 0);
    CHECK(nome == floresta);
    
    r.muda_regiao(deserto);
    nome = r.get_nome();
    x = r.get_x();
    y = r.get_y();
    agua = r.get_chance_agua();
    comida = r.get_chance_comida();
    arma = r.get_chance_arma();
    remedio = r.get_chance_remedio();
    CHECK(x == 3);
    CHECK(y == 3);
    CHECK(agua == 2);
    CHECK(comida == 5);
    CHECK(arma == 5);
    CHECK(remedio == 0);
    CHECK(nome == regioes::deserto);

    CHECK_THROWS_AS(r.muda_regiao(floresta),nao_da_para_mudar_para_essa_regiao_e);
}
