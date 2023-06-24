#include "../third_party/doctest.h"
#include "../include/regiao.h"

TEST_CASE("Testa se os atributos são inicializados") {
    Regiao r = Regiao();
    CHECK(r.get_chance_agua() == 0);
    CHECK(r.get_chance_arma() == 9);
    CHECK(r.get_chance_comida() == 0);
    CHECK(r.get_chance_remedio() == 9);
    CHECK(r.get_nome() == regioes::centro);
}