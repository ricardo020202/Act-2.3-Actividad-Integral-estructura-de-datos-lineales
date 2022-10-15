![Tec de Monterrey](images/logotecmty.png)
# Act 2.3 - Actividad Integral estructura de datos lineales (Evidencia Competencia)

## <span style="color: rgb(26, 99, 169);">¿Qué tengo que hacer?</span>
En este repositorio encontrarás los archivos de entrada, así como las salidas esperadas que podrás usar para probar tu implementación. También encontrarás un archivo "main.cpp". Ahí deberás implementar tu solución. En el archivo deberás colocar en la parte superior, en comentarios, tus datos. Por ejemplo:
```
// =========================================================
// File: main.cpp
// Author: Edward Elric - A00123456
// Date: 01/01/2021
// =========================================================
```
<span style="text-decoration: underline;">De manera individual</span>, desarrolla la solución del siguiente problema:

El canal de Suez es un canal navegable que conecta el mar Mediterráneo con el mar Rojo a través de alrededor de 190 km, uniendo por un el lado del mar Mediterráneo desde el puerto Said hasta el golfo de Suez en el mar Rojo. Este canal es navegado entre 49 y 97 barcos diariamente. Se tiene un registro de los barcos que navegan por el canal con el siguiente formato.
```
<fecha> <hora> <punto-entrada> <UBI-Identificador único del buque>
```
Ejemplo:
```
03-01-20 13:45 M 8PAK7
```
Donde:
* El punto de entrada puede ser **M – Mar Mediterráneo** y **R – Mar Rojo**.
* La fecha estará entre **01-01-2020** y **31-12-2020**.
* El tiempo estará en formato de 24 Hrs.

## <span style="color: rgb(26, 99, 169);">**Entrada**</span>
La primera línea de entrada contiene dos elementos: un entero *n*, el número de barcos que ha entrado al canal, y una cadena de 3 tres caracteres *prefix*, el prefijo del UBI a búscar. Las siguientes *n* líneas; contiene el registro de los barcos que han entrado al canal con el formato descrito anteriormente. Todas las fechas

## <span style="color: rgb(26, 99, 169);">**Salida**</span>
Deberás desplegar el listas por mes de los buques cuyo UBI empiece con *prefix* hayan entrada por el mar Mediterráneo, así como el listado de los que entraron por el mar Rojo. Se deben omitir los meses en los que no haya entrado ningún barco por ambas entradas  o aquella entrada por la que no haya ingresado algún barco en un mes en particular.

## <span style="color: rgb(26, 99, 169);">**Ejemplo de entrada**</span>
```
27 2FJ
25-07-20 20:10 M 2FJU9
05-01-20 10:16 M 1FRB6
17-07-20 21:36 R 2FRZ9
17-10-20 10:06 M 2TLR2
24-04-20 14:15 M 2FJA8
18-08-20 14:50 M 2ARL4
19-11-20 07:08 M 2OIM0
10-09-20 14:02 R 1TLP1
24-05-20 12:36 M 2ARF7
13-12-20 19:59 M 2MXB0
05-10-20 17:04 R 2UYN7
05-10-20 03:47 R 1AVM9
13-04-20 12:29 M 1MXL3
29-07-20 11:09 M 2ARA4
04-10-20 14:32 R 1ARY0
24-10-20 20:34 R 1ARU2
25-04-20 21:28 M 2TLP1
09-01-20 07:37 M 2FJX8
28-09-20 20:22 M 2MXJ6
12-10-20 10:28 R 1IJH1
20-11-20 13:37 R 1MXT7
30-10-20 12:52 M 1FRD9
27-01-20 16:36 M 1FRB7
07-02-20 00:21 M 2FJV6
17-11-20 05:45 M 2ARF4
01-02-20 01:55 R 2FJB6
14-03-20 16:13 M 1MXU2
```

## <span style="color: rgb(26, 99, 169);">**Ejemplo de salida**</span>
```
jan
M 1: 2FJX8
feb
M 1: 2FJV6
R 1: 2FJB6
apr
M 1: 2FJA8
jul
M 1: 2FJU9
```

Para probar tu implementación, compila tu programa con el comando:
```
g++ -std=c++11 main.cpp -o app
```
Posteriormente, prueba con cada uno de los archivos de entrada de prueba que encontrarás en este repositorio (input1.txt, input2.txt, input3.txt, input4.txt). Los resultados que debes obtener se encuentran en los archivos llamados output1.txt, output1.txt, output1.txt y output1.txt. Para realizar las pruebas, puedes usar las siguientes líneas de código. Por ejemplo, si queremos probar con el archivo de prueba "input1.txt".
```
./app > mysolution1.txt
diff mysolution1.txt output1.txt
```
Si el segundo comando no tenga ninguna salida, sabrás que los resultados que obtuviste son los esperados. Recuerda actualizar tu repositorio (*git push*) cuando hayas terminado tu implementación.

Por último, realiza una investigación y reflexión de la importancia y eficiencia del uso de las listas doblemente ligadas en una situación problema de esta naturaleza,  generando un documento llamado **"ReflexAct2.3.pdf"**

## <span style="color: rgb(26, 99, 169);">**¿Bajo qué criterios se evalúa mi evidencia?**</span>

- **80%** - Para cada una de las funcionalidades se evaluará:

    - **Excelente (80%)** - pasa correctamente todos los casos de prueba.
    - **Muy Bien (60%)** - pasa correctamente el 75% de los casos de prueba.
    - **Bien (40%)** - pasa correctamente el 50% de los casos de prueba.
    - **Insuficiente (20%)** - pasa correctamente menos del 50% de los casos de prueba.


- **10%** - El código deberá seguir los lineamientos estipulados en el estándar de codificación: <span class="instructure_file_holder link_holder">[liga_estándar_codificación](estandar.pdf)</span>
- **10%** - Se respetenan los nombres de las funciones en la aplicación.

## <span style="color: rgb(26, 99, 169);">**¿Dónde la entrego?**</span>
Esta actividad forma parte tanto de tu calificación final del curso, así como del portafolio de evidencias de las competencias a desarrollar del curso, por lo que se te pide que en forma individual:
* Realices una entrega del código fuente de la solución del problema, en la sección correspondiente dentro de esta plataforma, así como el documento de reflexión individual (**ReflexAct2.3.pdf**).
En la carpeta personal llamada **TC1031(Portafolio_Final)** que generaste desde la entrega de la actividad 1.3 y que te servirá como preparación para la entrega del portafolio de competencias que se realizará al final del curso, coloca en la subcarpeta **Act2.3** tus archivos que solucionaron la <span style="text-decoration: underline;">actividad 2.3</span> así como el documento de reflexión individual (**ReflexAct2.3.pdf**).
