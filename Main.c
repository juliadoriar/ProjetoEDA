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

	g = criarGestor(g, 99, "Julia");

	c = criarCliente(c, 3, "Maria", 333333333, "Rua do beijinho", 400.00);
	c = criarCliente(c, 4, "Joana", 444444444, "Rua do doce de leite", 500.00);

	void guardarCliente(Cliente * inicio);


	
}