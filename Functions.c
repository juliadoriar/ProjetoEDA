/*****************************************************************//**
 * \file   FunctionsStorage.c
 * \brief  funções para autenticação de cada utilizador, armazenamento
 * de dados de clientes, dos gestores e dos meios de mobilidade.
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




/*int guardarCliente(Cliente* inicio)
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
}*/