# AyEDA

## Práctica 1: Automata Celular Elemental

## Practica 2: Juego de la Vida

## Practica 3: Autómata celular general

## Práctica 4: Funciones de Distribución y Exploración

## Práctica 5: Funciones de Distribución y Exploración

## Práctica 6: Arboles Binarios

En esta práctica se implementan el arból binario de busqueda y el arbol binario balanceado y se realizan operaciones de busqueda e inserción de nodos en ambos arboles.

Para compilar el programa se debe ejecutar el siguiente comando:

```bash
./ejecutable.sh
```

Para ejecutar el programa se debe ejecutar el siguiente comando:

```bash
./int_main -ab <abe|abb> -init <i> [s][f]
```

Donde:

- ab: Especifica el tipo de arbol a utilizar, puede ser abe para arbol binario de busqueda o abb para arbol binario balanceado.
- init: Especifica el tipo de inicialización de nodos, puede ser i para inicialización manual o a para inicialización aleatoria.
- s: Especifica la semilla para la inicialización aleatoria.
- f: Especifica el archivo de entrada para la inicialización manual.

Si se tiene alguna duda sobre el uso del programa se puede ejecutar el siguiente comando:

```bash
./int_main -h
```

Modificacion:

Se ha pedido implementar una clase fecha ( date) y un main que trabaje con ella, además de cambiar la funcion de imprimir inorden por imprimir postorden

Para ello se ha creado la clase date en el archivo date.h, además se ha creado un main especifico para trabajar con la clase date en el archivo date_main.cpp donde el unico cambio es el tipo de dato que se almacena en el arbol, en este caso se almacenan fechas.

Además en el archivo ab.h se implementado la funcion de imprimir postorden.

El formato para incluir las fechas es el siguiente:

```bash
yyyymmdd
```