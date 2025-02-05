# ft_printf es un proyecto que imita la función printf real<hr>


## [ft_printf](/ft_printf.c) 
`ft_printf`es una función que formatea e imprime la salida en stdout (típicamente la terminal). Toma una cadena de formato, que especifica cómo se debe formatear la salida, y un número variable de argumentos que contienen los valores que se imprimirán.

La función comienza inicializando una lista de argumentos variables usando `va_start`. Luego itera a través de la cadena de formato, carácter por carácter. Cuando encuentra un carácter `'%'`, llama a la función de conversión con el siguiente carácter en la cadena de formato y el argumento actual de la lista de argumentos. La función de conversión procesa el argumento y lo formatea de acuerdo con el especificador de conversión correspondiente (el carácter después del '%'). Si el carácter no es un `'%'`, se llama a `ft_putchar` para imprimir el carácter. Finalmente, la función devuelve el número total de caracteres impresos.

### va-list
En C, `va_list` es un tipo que contiene una lista de argumentos de distintos tipos, junto con un estado actual que apunta al siguiente argumento de la lista. Se utiliza para pasar un número variable de argumentos a una función.

Para usar `va_list` en una función, primero debe declararla e inicializarla usando `va_start`. Luego puede usar `va_arg` para recuperar el siguiente argumento de la lista y `va_end` para limpiar y restablecer la lista cuando haya terminado de procesar los argumentos.

### va_arg
`va_arg` es una macro en C que recupera el siguiente argumento en una `va_list`. Toma una variable `va_list` y el tipo del argumento como argumentos, y devuelve el argumento como el tipo especificado.

La macro `va_arg` generalmente se usa dentro de un ciclo para iterar a través de todos los argumentos en una `va_list`. La primera vez que se llama a `va_arg` en una `va_list`, devuelve el primer argumento; la segunda vez que se llama, devuelve el segundo argumento; etcétera.

### va_start
`va_start` es una macro en C que inicializa una variable `va_list` para usar con `va_arg` y `va_end`. Toma como argumentos una variable `va_list` y el nombre del último parámetro fijo en la función.

La variable `va_list` se usa para contener una lista de argumentos de diferentes tipos pasados a una función. Se debe llamar a `va_start` antes de que se pueda usar `va_arg` para recuperar los argumentos de la lista.

### va_end
`va_end` es una macro en C que limpia y restablece una variable `va_list` después de haberla usado con `va_arg`. Toma una variable `va_list` como argumento.

La variable `va_list` se usa para contener una lista de argumentos de diferentes tipos pasados a una función. Una vez que haya terminado de procesar los argumentos, debe llamar a `va_end` para limpiar y restablecer la variable `va_list`. Esto normalmente se hace antes de regresar de la función.

### converter

El [convertidor](/ft_printf.c) es una función que procesa un solo argumento en una `va_list` y lo formatea de acuerdo con el especificador de formato dado. Toma un `char` que representa el especificador de formato y una `va_list` como argumentos, y devuelve un `int` que indica el número de caracteres impresos.

La función primero verifica el valor del parámetro de formato y llama a la función adecuada para procesar el argumento. Por ejemplo, si el formato es `'c'`, la función llama a `ft_putchar` para imprimir un solo carácter de `va_list`. Si el formato es `'s'`, la función llama a `ft_putstr` para imprimir una cadena terminada en nulo. Si el formato es `'p'`, la función llama a `ft_print_ptr` para imprimir un valor de puntero.

Cada una de las funciones llamadas por el convertidor toma un solo argumento de `va_list` usando la macro `va_arg`. El tipo de argumento pasado a `va_arg` debe coincidir con el tipo de argumento esperado por la función. Por ejemplo, si el especificador de formato es `'d'` o `'i'`, la función llama a `ft_putnbr` para imprimir un valor `int`, por lo que se llama a `va_arg` con `int` como segundo argumento.

Una vez que el argumento ha sido procesado e impreso, el convertidor devuelve el número de caracteres impresos. Si no se reconoce el parámetro de formato, la función devuelve 1.
