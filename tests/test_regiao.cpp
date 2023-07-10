#include "../third_party/doctest.h"
#include "../include/regiao.h"
#include "../include/jogador.h"
#include <string>
#include <map>

TEST_CASE("Testa se os atributos são inicializados") {
    Regiao r = Regiao();
    CHECK(r.get_chance_agua() == 0);
    CHECK(r.get_chance_arma() == 9);
    CHECK(r.get_chance_comida() == 0);
    CHECK(r.get_chance_remedio() == 3);
    CHECK(r.get_nome_string() == "centro");
    CHECK(r.get_x() == 2);
    CHECK(r.get_y() == 2);
}

TEST_CASE("Testa se a regiao muda corretamente e se os erros são lançados") {
    Regiao Centro(2,2,"centro",0,0,9,3);
    Jogador p = Jogador("Maria", &Centro);
    
    Regiao r = Regiao();
    int x,y,agua,comida,arma,remedio;
    std::string nome = "centro";

    std::map<std::string,Regiao*> map_regioes;

    Regiao Reg1(2,1,"flor",8,7,2,0);
    map_regioes[Reg1.get_nome_string()] =  &Reg1;

    Regiao Reg2(3,1,"sol",10,3,1,0);
    map_regioes[Reg2.get_nome_string()] =  &Reg2;

    Regiao Reg3(1,3,"lua",10,10,0,0);
    map_regioes[Reg3.get_nome_string()] =  &Reg3;

    p.muda_regiao("flor",&map_regioes);

    nome = p.get_Regiao_Atual()->get_nome_string();
    x = p.get_Regiao_Atual()->get_x();
    y = p.get_Regiao_Atual()->get_y();
    agua = p.get_Regiao_Atual()->get_chance_agua();
    comida = p.get_Regiao_Atual()->get_chance_comida();
    arma = p.get_Regiao_Atual()->get_chance_arma();
    remedio = p.get_Regiao_Atual()->get_chance_remedio();
    CHECK(x == 2);
    CHECK(y == 1);
    CHECK(agua == 8);
    CHECK(comida == 7);
    CHECK(arma == 2);
    CHECK(remedio == 0);
    CHECK(nome == "flor");
    
    p.muda_regiao("sol",&map_regioes);
    nome = p.get_Regiao_Atual()->get_nome_string();
    x = p.get_Regiao_Atual()->get_x();
    y = p.get_Regiao_Atual()->get_y();
    agua = p.get_Regiao_Atual()->get_chance_agua();
    comida = p.get_Regiao_Atual()->get_chance_comida();
    arma = p.get_Regiao_Atual()->get_chance_arma();
    remedio = p.get_Regiao_Atual()->get_chance_remedio();
    CHECK(x == 3);
    CHECK(y == 1);
    CHECK(agua == 10);
    CHECK(comida == 3);
    CHECK(arma == 1);
    CHECK(remedio == 0);
    CHECK(nome == "sol");

    CHECK_THROWS_AS(p.muda_regiao("lua", &map_regioes), nao_da_para_mudar_para_essa_regiao_e);
    
}

TEST_CASE("Novo teste para ver se os atributos são inicializados") {
    Regiao r = Regiao();
    CHECK(r.get_chance_agua() == 0);
    CHECK(r.get_chance_arma() == 9);
    CHECK(r.get_chance_comida() == 0);
    CHECK(r.get_chance_remedio() == 3);
    CHECK(r.get_nome_string() == "centro");
    CHECK(r.get_x() == 2);
    CHECK(r.get_y() == 2);
}
