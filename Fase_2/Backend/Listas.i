%module  Listas
%include "std_string.i"
%{
#include "ListaUsuarios.h"
#include "Carga.h"
#include "ColaTutorial.h"
#include "ListaMovimientos.h"
#include "ListaCategoria.h"
%}
%include ListaUsuarios.h
%include Carga.h
%include ColaTutorial.h
%include ListaMovimientos.h
%include ListaCategoria.h