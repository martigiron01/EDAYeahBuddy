# YeahBuddy

YeahBuddy es la red social por y para amantes del fitness que necesitas!

## Contenidos

- Introducción
- Objetivos del proyecto
- Solución
- Referencias

## Introducción

Cuando empezamos con este proyecto, no sabíamos que haría nuestra red social diferente. No sabíamos cuál sería el tema o qué la haría útil o divertida. Así que preguntamos a Chat GPT. Tan pronto como leímos sus propuestas, lo supimos inmediatamente: una red social de fitness. A los tres nos encanta el gimnasio y fitness en general así que era la idea perfecta. Además, es una idea bastante original ya que aún no hay aplicaciones grandes o conocidas que hagan eso. Inicialmente, pensamos que sería buena idea que los usuarios pudieran encontrar gente con la que entrenar cerca, aun que esto no se ha podido acabar de implementar. Lo que si hemos conseguido es crear una red donde usuarios pueden hacer un seguimiento de su progreso y publicar sus avances en el ámbito del fitness y conocer a personas fantásticas en el proceso.

## Objetivos del proyecto

#### Objetivos obligatorios alcanzados
- **Implementación de una cola, lista y pila.**
Uno de los objetivos obligatorios que se requería era el de implementar al menos una cola, lista y pila para alguna funcionalidad del proyecto. Hemos conseguido implementar las tres y así es cómo:<br/><br/>
    - Empleamos una **cola** para gestionar las peticiones de amistad de los usuarios. Cada usuario tiene una cola de solicitudes propia así que la añadimos a la estructura `User` y lo hacemos como un array de usuarios: `struct _user** requestsQueue`. `User` también debe almacenar información sobre el primero en esta cola y su tamaño, así que añadimos en `User`, `struct _user* requests_first` y `int requests_size`. Una vez terminamos con esto, debemos añadir las funciones básicas de una cola. Éstas son `requests_init_queue()`, `requests_is_empty()`, `requests_enqueue()` y `requests_dequeue()` y, finalmente, una función para mostrar todas las peticiones `requests_print()`. Los nombres explican con bastante acierto lo que hace cada función pero estas son las explicaciones con un poco más de detalle, incluyendo sus argumentos y tipo de retorno:
        - `void requests_init_queue(User* user)` inicializa la cola.
        - `bool requests_is_empty(User* user)` comprueba si la cola está vacía.
        - `void requests_enqueue(User* user, User* new_friend)` añade una petición de amistad de `new_friend` al final de la cola.
        - `void requests_dequeue(User* user)` elimina la primera petición de la cola.
        - `void requests_print(User* user)` imprime las solicitudes una a una y permite al usuario aceptar o rechazarlas.<br/><br/>
    - Usamos una **lista**, concretamente una **lista enlazada**, para almacenar los amigos de un usuario. Como cada usuario tiene su propia lista de amigos, se añade en la estructura `User` un puntero con el primer amigo de la lista, que apuntará al siguiente (inicialmente NULL) y así hasta que no haya más amigos en la lista. Para ello, creamos el nodo `friendsNode` que representa un amigo del usuario. Este nodo incluye el nombre de usuario del amigo (`char username[MAX_LENGTH]`) y un puntero hacia el siguiente amigo de la lista (`struct friendsNode* next`). Con esto, ya tenemos la estructura básica de nuestra lista de amigos. Las funciones empleadas para trabajar y modificar esta lista son `add_friend()` y `print_friends_list()`. De nuevo, explicamos en más profundidad estas funciones:
        - `void add_friend(User* user, User* sender)` añade a `sender` a la lista de amigos de `user` y viceversa, siendo `sender` el usuario que envió la solicitud de amistad y `user` el que la aceptó.
        - `void print_friends_list(User* user)` imprime la lista de amigos de `user`.<br/><br/>
    - La **pila** la utilizamos para las publicaciones. Cada usuario tiene una pila de publicaciones que definimos como `postStack`. Esta pila incluye un array de publicaciones (`char** posts`) y un entero que marca el elemento "de más arriba" de la pila (`int top`). Creamos las funciones básicas de una pila: `posts_init_stack()`, `posts_is_empty()`, `push_post()` y `pop_post()`.
        - `postStack* posts_init_stack()` crea una pila vacía y la devuelve. Lo hacemos así para incluir la pila nada más se crea un usuario. `new_user->posts = posts_init_stack()` en la función `create_user()`.
        - `bool posts_is_empty(postStack* stack)` comprueba si `stack` está vacío. Si lo está, devuelve `true`, sino `false`.
        - `void push_post(postStack* stack, char* post, Dictionary * dictionary)` añade ...