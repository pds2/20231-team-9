#ifndef PDS2_UTENSILIOS_H
#define PDS2_UTENSILIOS_H

enum utensilios {
    agua, remedio, comida
};

class Utensilio {
    private:
        utensilios _utensilio;
    public:
        Utensilio(utensilios utensilio);
        utensilios get_tipo() const;
};

#endif