%module  Listas
%include "std_string.i"
%{
#include "Usuarios/ListaUsuario.h"
#include "Tutorial/ColaTutorial.h"
#include "Movimientos/ListaMovimientos.h"
#include "Categoria/ListaCategoria.h"
%}
%include Usuarios/ListaUsuario.h
%include Tutorial/ColaTutorial.h
%include Movimientos/ListaMovimientos.h
%include Categoria/ListaCategoria.h