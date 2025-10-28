2. Existe un archivo medidas.dat, binario de organización directa con la siguiente estructura:
id(long),descripción(char[120]), double medida ,estado(unsigned),baja(int 0:alta 1:baja)

Se pide, usando funciones de lenguaje c, que pase como argumento  el id entre otros parámetros y agregue  un elemento en una pila (estructura dinámica) con el elemento de los registro coincidente con el id,  si está marcados como alta,  que los bits 0,1,2 y 3  del campo estado esté en 1, y las 3 primeras letras de la descripción  son “ESP”, además modificar el campo baja y regrabar el registro en este caso. La función deberá retornar lo adecuado, teniendo en cuenta que no hay variables globales.
 En la función el main() correr la función 10 veces y luego mostrar el contenido de la pila.
