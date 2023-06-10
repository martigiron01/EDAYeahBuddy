# YeahBuddy
YeahBuddy es la red social por y para amantes del fitness que necesitas!
## Contenidos
- Introducción
- Objetivos del proyecto
- Solución
- Referencias
## Introducción
Cuando empezamos con este proyecto, no sabíamos qué haría a nuestra red social diferente. No sabíamos cuál sería el tema o qué la haría útil o divertida. Así que preguntamos a Chat GPT. Tan pronto como leímos sus propuestas, lo supimos inmediatamente: una red social de fitness. A los tres nos encanta el gimnasio y el fitness en general así que era la idea perfecta. Además, es una idea bastante original ya que aún no hay aplicaciones grandes o conocidas que hagan eso. Inicialmente, pensamos que sería buena idea que los usuarios pudieran encontrar gente con la que entrenar cerca, aún que esto no se ha podido acabar de implementar. Lo que sí hemos conseguido es crear una red donde los usuarios pueden hacer un seguimiento de su progreso y publicar sus avances en el ámbito del fitness y conocer a personas fantásticas en el proceso.
## Objetivos del proyecto
#### Objetivos obligatorios alcanzados
- **Implementación de una cola, lista y pila.**
Uno de los objetivos obligatorios que se requería era el de implementar al menos una cola, lista y pila para alguna funcionalidad del proyecto. Hemos conseguido implementar las tres y así es cómo:<br/><br/>
    - Empleamos una **cola** para gestionar las peticiones de amistad de los usuarios. Cada usuario tiene una cola de solicitudes propia así que la añadimos a la estructura `User` y lo hacemos como un array de usuarios: `struct _user** requestsQueue`. `User` también debe almacenar información sobre el primero en esta cola y su tamaño, así que añadimos en `User`, `struct _user* requests_first` y `int requests_size`. Una vez terminamos con esto, debemos añadir las funciones básicas de una cola. Éstas son `requests_init_queue()`, `requests_is_empty()`, `requests_enqueue()` y `requests_dequeue()` y, finalmente, una función para mostrar todas las peticiones `requests_print()`. Los nombres explican con bastante acierto lo que hace cada función pero estas son las explicaciones con un poco más de detalle, incluyendo sus argumentos y tipo de retorno:
        - `void requests_init_queue(User* user)` inicializa la cola de `user`.
        - `bool requests_is_empty(User* user)` comprueba si la cola de `user` está vacía.
        - `void requests_enqueue(User* user, User* new_friend)` añade una petición de amistad de `new_friend` al final de la cola de `user`.
        - `void requests_dequeue(User* user)` elimina la primera petición de la cola de `user`.
        - `void requests_print(User* user)` imprime las solicitudes una a una y permite a `user` aceptar o rechazarlas.<br/><br/>
    - Usamos una **lista**, concretamente una **lista enlazada**, para almacenar los amigos de un usuario. Como cada usuario tiene su propia lista de amigos, se añade en la estructura `User` un puntero con el primer amigo de la lista, que apuntará al siguiente (inicialmente NULL) y así hasta que no haya más amigos en la lista. Para ello, creamos el nodo `friendsNode` que representa un amigo del usuario. Este nodo incluye el nombre de usuario del amigo (`char username[MAX_LENGTH]`) y un puntero hacia el siguiente amigo de la lista (`struct friendsNode* next`). Con esto, ya tenemos la estructura básica de nuestra lista de amigos. Las funciones empleadas para trabajar y modificar esta lista son `add_friend()` y `print_friends_list()`. De nuevo, explicamos en más profundidad estas funciones:
        - `void add_friend(User* user, User* sender)` añade a `sender` a la lista de amigos de `user` y viceversa, siendo `sender` el usuario que envió la solicitud de amistad y `user` el que la aceptó.
        - `void print_friends_list(User* user)` imprime la lista de amigos de `user`.<br/><br/>
    - La **pila** la utilizamos para las publicaciones. Cada usuario tiene una pila de publicaciones que definimos como `postStack`. Esta pila incluye un array de publicaciones (`char** posts`) y un entero que marca el elemento "de más arriba" de la pila (`int top`). Creamos las funciones básicas de una pila: `posts_init_stack()`, `posts_is_empty()`, `push_post()` y `pop_post()`, adicionalmente, usamos una función `save_post()` para guardar las publicaciones en un archivo `.txt`.
        - `postStack* posts_init_stack()` crea una pila vacía y la devuelve. Lo hacemos así para incluir la pila nada más se crea un usuario. `new_user->posts = posts_init_stack()` en la función `create_user()`.
        - `bool posts_is_empty(postStack* stack)` comprueba si `stack` está vacío. Si lo está, devuelve `true`, sino `false`.
        - `void push_post(postStack* stack, char* post, Dictionary * dictionary)` añade `post` "arriba" de `stack`. 
        - `void pop_post(postStack* stack)` borra la publicación que se encuentra en `stack->top`.
        - `void save_post(char* post, User * user, char* filename)` guarda `post` en un archivo `.txt`. También guarda el nombre de usuario de `user` y la fecha y hora de publicación.<br/><br/>
- **Implementación del algoritmo de búsqueda LinearSearch.**
Otro de los objetivos que se requerían era la implementación de un algoritmo de búsqueda, ya sea LinearSearch o BinarySearch. Nosotros empleamos el algoritmo de LinearSearch en la función `User* search_user(char* username, userArray* array)` que busca el nombre de usuario `username` en el array de usuarios `array` de forma lineal y devuelve el usuario con dicho `username`.  Usamos LinearSearch ya que el array de usuarios no está ordenado. Cada vez que se añade un usuario, se añade a la última posición del array sin tener en cuenta el orden alfabético o cualquier otro tipo de orden, por lo que no se puede usar un algoritmo como BinarySearch, que lo requiere.
La función `search_user()`, que incluye este algoritmo, es imprescindible para el correcto funcionamiento del programa. La usamos para saber con qué usuario estamos operando, para verificar si un usuario existe o para buscar un usuario concreto y visitar su perfil.
Las posibles limitaciones de este algoritmo de búsqueda es el tiempo de ejecución en caso de que el array de usuarios crezca mucho.<br/><br/>
- **Implementación del algoritmo de ordenamiento BubbleSort.**
Además del algoritmo de búsqueda LinearSearch se pedía implementar un algoritmo de ordenación de los que hemos visto durante el curso. Entre ellos se encuentra BubbleSort, que es el que hemos implementado.<br/><br/>
- **Implementación de un diccionario.**
...<br/><br/>
- **Comentarios**
El código incluye comentarios en las partes que consideramos que necesitan una explicación o que no son tan legibles a simple vista. Los comentarios facilitan mucho la labor del programador, en este caso nosotros, en caso de querer modificar algún fragmento del código en un futuro.
#### Objetivos deseables alcanzados
- **Lectura de datos de una fuente externa .txt.**
El primer objetivo deseable pedía implementar la posibilidad de leer datos de una fuente externa como por ejemplo un archivo de texto. Hemos implementado esto para diferentes funcionalidades del código, concretamente, para leer datos de los usuarios y de las publicaciones.
Tenemos un archivo `users.txt` donde se almacenan datos de los usuarios y otro archivo `posts.txt` donde se almacenan datos sobre las publicaciones de los usuarios. La función `import_data()` lee e importa los datos de ambos archivos para que puedan ser utilizados. Usamos también una función auxiliar `line_count()`. Así es como funcionan:
    - `int line_count(char* filename)` cuenta el número de líneas de `filename`. Para ello abre `filename` en modo lectura y cada vez que se encuentra con un `\n`, añade 1 a `lines`. En caso de error abriendo el archivo, devuelve 0 y, si todo va bien, devuelve el número de líneas `lines`.
    - `void import_data(userArray* array, char* users_filename, char* posts_filename, Dictionary* dictionary)` lee e importa los datos de 
## Solución
#### Arquitectura del sistema

## Referencias