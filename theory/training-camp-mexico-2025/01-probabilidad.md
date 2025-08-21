# Probabilidad by Marckess

## Diseño de algoritmos aleatorizados

### Problema 1

Dado un arreglo, encontrar si exisete un elemento que se repite más de la mitad de las veces.

#### Solución probabilística

1. Seleccionar un elemento al azar
2. Ver cuantas veces se repite en el arreglo
3. Si se repite más de la mitad de las veces, devolverlo como solución
4. Si no, volvemos a tomar otro valor

La probabilidad de fallar es aproximadamente $\left(\frac{1}{2}\right)^k$, donde k es el número de intentos.

Si llevamos 20 intentos la probabilidad de fallar es $\left(\frac{1}{2}\right)^{20}$, que es aproximadamente 0.000000095 con lo que podemos asegurar que no va a existir un elemento que se repita más de la mitad de las veces.

> **Nota**: Algoritmo Boyer-Moore es una opción con complejidad O(n) y espacio O(1).

### Problema 2

Hallar el GHD de un arreglo. El GHD se define como el mayor entero que divide al menos a la mitad de elementos del arreglo

#### Solución probabilística

1. Elegir un elemento al azar, ese elemento tiene la probabilidad de $\left(\frac{1}{2}\right)$ de que uno de sus divisores sea el GHD
2. Recorrer sus divisores (los divisores se pueden obtener en $\sqrt{n}$) y probar cuál es su máximo divisor que divide al menos a la mitad de los elementos del arreglo
3. Si encontramos un divisor que divide al menos a la mitad de los elementos, lo devolvemos como solución
4. Si no, volvemos a intentar con otro elemento al azar

### Problema 3

Dado un conjunto de puntos, decir cuál es la máxima cantidad de triángulos no degenerados con vértices en los puntos dados que se pueden formar. No se pueden usar más de una vez cada punto.

#### Solución probabilística

Si el tamaño de la recta con más puntos colineales entre 2 es mayor a lo que tengo afuera (es decir, los puntos que no están en esa recta), $ \frac{mx}{2} > n - mx$. Entonces puedo formar triángulos con esos puntos. Por lo tanto la respuesta es el número total de puntos menos el tamaño de la recta con más puntos colineales $res = n - mx$.

Si el tamaño de la recta con más puntos colineales entre 2 es menor o igual a lo que tengo afuera $ \frac{mx}{2} \leq n - mx$. Entonces puedo formar el máximo de triángulos no degenerados con los puntos restantes. Por lo tanto la respuesta es el número total de puntos entre 3,  $res = \frac{n}{3}$.

> **TLDR**: Si existe una recta $3 mx > 2n$, la respuesta es $res = n - mx$. Si no, la respuesta es $res = \frac{n}{3}$.

Si selecciono un punto al azar, la probabilidad de que esté en la recta más grande es de $\frac{1}{3}$.

Para calcular esto, calculo la pendiente de un punto $(x_1, y_1)$ a otro punto $(x_2, y_2)$, si hay varios puntos con la misma pendiente, están en la misma recta.

> **Nota**: Es recomendable usar fracciones para evitar problemas de precisión con los números decimales.

### Problema 4

Se da un árbol con valores en los nodos. Contestar las queries:

- En el camino de u a v, decir si existe un valor que se repita una cantidad impar de veces.

#### Solución

La solución se puede obtener al sacar XOR de todo el camino. Si la respuesta final es diferente de 0, puedo asegurar que hay un impar, pero no al revés. Para solucionar esto, es hace un mapeo a otro número (por ejemplo multiplicar por un primo). Por cada bit que utilize, se aumenta la probabilidad de no colisionar, por ejemplo con long long: $\left(\frac{1}{2}\right)^{64}$.

### Problema 5

Hay una permutación oculta de tamaño a lo más 2048. Tiene que encontrar todos los elementos de la permutación haciendo a lo más 4269 preguntas del tipo:

- Da dos enteros i y j, el evaluador te regresa el valor de $p_i | p_j$ (bitwise or).

#### Solución

Encontrando el 0, puedes obtener el resto de valores al realizar la combinación.

Para encontrar el valor exacto, es realizar la operación con 20 elementos al azar y hacer un and de todos los resultados, 
con eso buscas el 0.

### Problema 6

Tienes un árbol k-nario completo con n nodos. Hallar la raíz del árbol con a lo más 60n preguntas:

- Dados $a$ $b$ $c$, el evaluador devuelve yes si b está en el camino de $a$ a $c$.

#### Solución

La probabilidad de que escoja dos nodos en sub-árboles distintos, es $\frac{k-1}{k}$. Para 
