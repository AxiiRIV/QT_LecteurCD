#ifndef DECLARATIONS_COMMUNES_H
#define DECLARATIONS_COMMUNES_H
#include <string>

namespace constantes
{
    constexpr unsigned short int NB_MAX_TITRES = 4;
    inline const std::string_view VERSION  = "version v3";
    inline const std::string DETAIL = "Vue + lien vue -> LecteurCD + classes Titre et Cd intégrées dans le projet";
    inline const std::string AUTEUR = "P.Dagorret";
    inline const std::string DATE = "mars 2026";
    inline constexpr int PAS_DE_TITRE = -1;
}

#endif // DECLARATIONS_COMMUNES_H
