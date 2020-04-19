#ifndef TOPOSAM_HPP_INCLUDED
#define TOPOSAM_HPP_INCLUDED

#include "tabela.hpp"
#include "utakmica.hpp"

class TopOsam
{
private:
    Tabela tabelica[8];
    Utakmica tekme;
public:
    ///ovde ce bato da bude da uzima prvih osam
    ///spaja timove
    ///treba da racuna koliko ko ima pobeda
    ///pobede dobijamo iz onog brojaca, funkcije, koja ce biti u utakmica.hpp
    ///nakon toga 4 pobednika
};

#endif // TOPOSAM_HPP_INCLUDED
