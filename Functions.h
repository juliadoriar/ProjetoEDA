/*****************************************************************//**
 * \file   Functions.h
 * \brief  Assinatura para todas as funções do programa.
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

//Função para criar novo cliente
Cliente* criarCliente(Cliente* inicio, int id, char nome[], int nif, char morada[], float saldo);

//Função para criar novo meio de mobilidadade
MeioMob* criarMeio(MeioMob* inicio, int id, char tipo[], float carga, float autonomia, char localizacao[]);

//Função para criar um novo gestor com id e nome
Gestor* criarGestor(Gestor* inicio, int id, char nome[]);

//Função para ler ficheiro Clientes.txt
Cliente* lerFicheiro(Cliente*);

void guardarCliente(Cliente* inicio);

Cliente* inserirCliente(Cliente* listaClientes, int id, char nome[], int nif, char morada[], float saldo);


/*

int inserirMeio();
int removeCliente();
int removeMeio();*/
