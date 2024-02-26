#!/bin/bash

# Función para reemplazar los caracteres en el archivo
replace_characters_in_file() {
    input_file="$1"
    # Utilizamos sed para realizar los reemplazos en el archivo
    sed -i 's/0/ /g; s/1/X/g' "$input_file"
}

# Verificar que se proporcionó un nombre de archivo como argumento
if [ $# -ne 1 ]; then
    echo "Uso: $0 <nombre_del_archivo>"
    exit 1
fi

# Verificar si el archivo existe
input_file="$1"
if [ ! -f "$input_file" ]; then
    echo "El archivo '$input_file' no existe."
    exit 1
fi

# Llamar a la función para reemplazar los caracteres en el archivo
replace_characters_in_file "$input_file"

echo "Contenido del archivo '$input_file' modificado exitosamente."
