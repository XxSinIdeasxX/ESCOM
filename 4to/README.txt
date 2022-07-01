El programa es un código de python por lo que para correrlo es necesario contar 
con el interprete de Python 3.10 y las librerias matplotlib y numpy instaladas en el equipo

El programa se controla a travez de la terminal

Una vez en el interprete, al ejecutarse primeramente va a solicitar datos de entrada: Número de máquinas,
Operaciones y sus repectivos tiempos por máquina y Tareas. Una vez ingresados se mostrará un menu en el cual
el usuario puede elegir entre varias acciones escribiendo el numero de la opcion y pulsando enter

Tenga precaución con la opción de cambiar el número de máquinas, ya que esta eliminará todos los datos 
introducidos previamente

Al momento de agregar tareas, asegurese de ingresar operaciones existentes con el formato que se indica
operaciones señaladas con la letra O mayuscula seguido del numero de operación, separadas por comas
(es indistinto si las comas van seguidas de un espacio)

Para las operaciones asegurese de ingresar unicamente numeros para los tiempos de ejecucion en cada
máquina, pueden ser con decimales pero cualquier otro tipo de dato hará que el programa falle

Despues de simular debe cerrar la ventana del diagrama de Gantt para seguir con la ejecución del programa

Al ejecutar el programa tambien se generará un archivo de texto llamado "Reporte de tiempos.txt" en el mismo
directorio en el que esté guardado el programa, en él se guardaran los reportes de tiempos de todas las 
simulaciones que se realicen. Dicho archivo se sobreescribe al ejecutar nuevamente el programa

Para finalizar la ejecución seleccione la opción "6. Salir"