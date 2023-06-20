#ifndef PDS2_UTENSILIOS_H
#define PDS2_UTENSILIOS_H

enum utensilios {
    agua, remedio, comida
};

class Utensilio {
    private:
        utensilios _utensilio;
    public:
        /*
        * @brief Construtor
        */
        Utensilio(utensilios utensilio);
        /*
        * @brief Retorna o tipo
        */
        utensilios get_tipo() const;

        auto operator<=>(const Utensilio&) const = default;
};

#endif 