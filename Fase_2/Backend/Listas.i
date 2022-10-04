%module  Listas
%include "std_string.i"
%{
#include "Usuarios/ListaUsuarios.h"
#include "Usuarios/ArbolB.h"
#include "Tutorial/ColaTutorial.h"
#include "Movimientos/ListaMovimientos.h"
#include "Categoria/ListaCategoria.h"
#include "Categoria/ArbolAvl.h"
%}
%include Usuarios/ListaUsuarios.h
%include Usuarios/ArbolB.h
%include Tutorial/ColaTutorial.h
%include Movimientos/ListaMovimientos.h
%include Categoria/ListaCategoria.h
%include Categoria/ArbolAvl.h