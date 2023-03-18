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
	Cliente* atual = NULL;

	g = criarGestor(g, 99, "Julia");

	c = criarCliente(c, 3, "Maria", 333333333, "Rua do beijinho", 400.00);
	c = criarCliente(c, 4, "Joana", 444444444, "Rua do doce de leite", 500.00);
	c = criarCliente(c, 5, "Luis", 555555555, "Rua do pudim", 150.00);

	m = criarMeio(m, 1, "trotinete", 55, 55, 2.5, "barcelos");
	m = criarMeio(m, 2, "bicicleta", 44, 44, 3.5, "braga");
	m = criarMeio(m, 3, "trotinete", 33, 33, 2.5, "barcelos");
	
	
	removerMeioMob(m, 3);
	
	listarMeiosMob(m);
	
	/*
	listarClientes(c);

	removerCliente(c, 4);

	alterarCliente(c, 5, 6, "Luis", 666666666, "Rua do bolo", 335.00);
	*/
	
}