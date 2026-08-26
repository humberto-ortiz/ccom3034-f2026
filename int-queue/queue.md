# Implementen intqueue

Implementen un queue con arreglos, parecido al intstack que hicimos.

Las operaciones

`void enqueue(int x)` -> añade x al final de la cola.

`int dequeue()` -> devuelve el primer elemento de la cola

```
intqueue q;

q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
q.dequeue() -> 1
q.dequeue() -> 2
q.dequeue() -> 3
q.dequeue() -> exepcion.
```
Entreguen los archivos queue.h y main.cpp con su codigo. Los archivos
deben tener:

1. Encabezado con descripcion del archivo y su nombre
2. Comentarios en las funciones
3. Implementaciones de las operaciones antes descritas.
