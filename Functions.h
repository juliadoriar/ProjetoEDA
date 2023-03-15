/*****************************************************************//**
 * \file   Functions.h
 * \brief  Funções para autenticação de cada utilizador, armazenamento
 * de dados de clientes, dos gestores e dos meios de mobilidade.
 * 
 * \author julia
 * \date   March 2023
 *********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Structs.h"

#pragma once

/*bool existeCliente(Cliente* clientes[], int aux, int n);*/

Cliente* criarCliente(Cliente* inicio, int id, char *nome[], int nif, char morada[], float saldo);

MeioMob* criarMeio(MeioMob* inicio, int id, char tipo[], float carga, float autonomia, char localizacao[]);

Gestor* criarGestor(Gestor* inicio, int id, char nome[]);




/*int guardarCliente(Cliente* inicio);







int guardarCliente(Cliente* inicio);
int inserirCliente();
int inserirMeio();
int removeCliente();
int removeMeio();*/
