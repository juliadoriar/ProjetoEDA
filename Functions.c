/*****************************************************************//**
 * \file   FunctionsStorage.c
 * \brief  Implementação das funções recursivas e diretivas a serem usadas no main.c
 * 
 * \author julia
 * \date   March 2023
 *********************************************************************/
#include "Functions.h"
#include "Structs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//Funções para criar Clientes, Meios e Gestores e alocar na memória
/**
 * .
 * 
 * \param inicio
 * \param id
 * \param nome
 * \param nif
 * \param morada
 * \param saldo
 * \return 
 */
Cliente* criarCliente(Cliente * inicio, int id, char nome[], int nif, char morada[], float saldo)
{
	Cliente * c = malloc(sizeof(Cliente)); 
	if (c != NULL) 
	{
		c->id = id;
		strcpy(c->nome, nome);
		c->nif = nif;
		strcpy(c->morada, morada);
		c->saldo = saldo;

		return c;
	}
	else return(inicio);
}

/**
 * .
 * 
 * \param inicio
 * \param id
 * \param tipo
 * \param carga
 * \param autonomia
 * \param localizacao
 * \return 
 */
MeioMob* criarMeio(MeioMob* inicio, int id, char tipo[], float carga, float autonomia, char localizacao[])
{
	MeioMob* m = malloc(sizeof(MeioMob));
	if (m != NULL)
	{
		m->id = id;
		strcpy(m->tipo, tipo);
		m->carga = carga;
		m->autonomia = autonomia;
		strcpy(m->localizacao, localizacao);
		
		return m;
	}
	else return(inicio); 
}
/**
 * .
 * 
 * \param inicio
 * \param id
 * \param nome
 * \return 
 */
Gestor* criarGestor(Gestor* inicio, int id, char nome[])
{
	Gestor* g = malloc(sizeof(Gestor));
	if (g != NULL)
	{
		g->id = id;
		strcpy(g->nome, nome);
	
		return g;
	}
	else return(inicio);
}


//Funções para guardar em ficheiros de texto os Clientes e Meios criados nas funções anteriores
void guardarCliente(Cliente* inicio)
{
	FILE* fp;
	fp = fopen("Clientes.txt", "w");
	if (fp != NULL)
	{
		Cliente* ptr = inicio;
		while (ptr != NULL)
		{
			fprintf(fp, "%d;%s;%d;%s;%f\n", ptr->id, &(ptr->nome), ptr->nif, &(ptr->morada), ptr->saldo);
			ptr = ptr->proximo;
		}
		fclose(fp);
		return(1);
	}
	else return(0);
}

Cliente* inserirCliente(Cliente* listaClientes, int id, char nome, int nif, char morada, float saldo)
{
	Cliente* novoCliente = malloc(sizeof(Cliente));

	if (novoCliente != NULL)
	{
		novoCliente->id = id;
		strcpy(novoCliente->nome, nome);
		novoCliente->nif = nif;
		strcpy(novoCliente->morada, morada);
		novoCliente->saldo = saldo;
		novoCliente->proximo = listaClientes;



		return novoCliente;
	}
	else return(0);

}


/**
 * .
 * 
 * \param c
 * \return 
 */
 
 /*
Cliente* lerFicheiro(Cliente* c)
{
	FILE* fp = fopen("Clientes.txt", "r");

	if (fp == NULL)
	{
		exit(1);
	}
	Cliente* listaClientes= (Cliente*)malloc(sizeof(Cliente));

	while (!feof(fp))
	{
		fscanf(fp, "%d;%50[^;];%d;%100[^;];%f;\n", &c->id, &(c->nome), c->nif, &(c->morada), c->saldo);
		listaClientes= InsereCliente(&listaClientes, c);
	}

	fclose(fp);
	return listaClientes;
}




	*/






