/*****************************************************************//**
 * \file   Main.c
 * \brief  
 * 
 * \author julia
 * \date   March 2023
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"
#include "Structs.h"

int main(){

	Cliente* c = NULL;
	MeioMob* m = NULL;
	Gestor* g = NULL;
	Cliente* ptr = NULL;
	Cliente* inicio = NULL;

	g = criarGestor(g, 99, "Julia");

	c = criarCliente(c, 3, "Maria", 333333333, "Rua do beijinho", 400.00);
	c = criarCliente(c, 4, "Joana", 444444444, "Rua do doce de leite", 500.00);
	
	m = criarMeio(m, 79, "trotinete", 55, 55, 2.5, "barcelos");

	guardarCliente(ptr);




	/*
	Cliente* listaClientes = NULL;
	Cliente *c = criarCliente(c, 9, "Carlos", 999999999, "Rua lar doce lar", 500.00);
	inserirCliente(&listaClientes, c);
	*/

	;
}