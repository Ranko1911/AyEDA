# AyEDA

## Práctica 1: Automata Celular Elemental

## Practica 2: Juego de la Vida

## Practica 3: Autómata celular general

### Notas / Comentarios / Dudas

- al separar las clases en ficheros se arreglaron gran parte de los problemas de compilación.
- revisar los metodos que usan getCell y cambiarlos por el operator[].
- revisar el uso de el operator[] en la clase Lattice.

### Dudas que comentar al profesor

- En las practicas anterirores yo he estado usando el "Lattice* lattice_ptr = nullptr; " para poder usar el puntero en las clases, pero en la practica 3 no se como hacer para que esto funcione de forma correcta.

- En prácticas anteriores he usado condionales para crear los objetos, si mantengo la misma idea aquí, me vana quedar muchos condicionales, ¿hay alguna forma de evitar esto?