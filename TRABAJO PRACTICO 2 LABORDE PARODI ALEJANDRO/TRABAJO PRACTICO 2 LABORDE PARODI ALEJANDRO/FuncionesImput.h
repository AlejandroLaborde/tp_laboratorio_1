
/**
 * \brief Solicita un n˙mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n˙mero ingresado por el usuario
 *
 */
float getFloat(char mensaje[]);

/**
 * \brief Solicita un n˙mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n˙mero ingresado por el usuario
 *
 */
int getInt(char mensaje[]);

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char mensaje[]);

/**
 * \brief Genera un n˙mero aleatorio
 * \param desde N˙mero aleatorio mÌnimo
 * \param hasta N˙mero aleatorio m·ximo
 * \param iniciar Indica si se trata del primer n˙mero solicitado 1 indica que si
 * \return retorna el n˙mero aleatorio generado
 *
 */
char getNumeroAleatorio(int desde , int hasta, int iniciar);

/**
 * \brief Verifica si el valor recibido es numÈrico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n˙merico y 0 si no lo es
 *
 */

int esNumericoFlotante(char str[]);

/**
 * \brief Verifica si el valor recibido es numÈrico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n˙merico y 0 si no lo es
 *
 */

int esNumerico(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras y n˙meros
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y n˙meros, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo n˙meros, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar· el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve (acpeta espacios)
 * \param mensaje es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return void
 *
 */

void getStringNombre(char mensaje[], char input[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar· el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve con el primer caracter de cada palabra en mayusculas y lo demas en minusculas
 * \param mensaje es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return 1 si el texto contiene solo letras
 *
 */

int getStringLetrasNombre(char mensaje[], char input[]);

/**
 * \brief Solicita un texto numÈrico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar· el texto ingresado
 * \return 1 si el texto contiene solo n˙meros
 */
int getStringNumeros(char mensaje[],char input[]);

/**
 * \brief Solicita un texto numÈrico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar· el texto ingresado
 * \return 1 si el texto contiene solo n˙meros
 */
int getStringNumerosFlotantes(char mensaje[],char input[]);

/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Es el limite inferior aceptado
 * \param lowLimit Es el limite superior aceptado
 * \return El numero ingresado por el usuario
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);

/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Es el limite inferior aceptado
 * \param lowLimit Es el limite superior aceptado
 * \return El numero ingresado por el usuario
 *
 */
int getValidFloat(char requestMessage[],char errorMessage[],float lowLimit, float hiLimit);

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargar· el texto ingresado
 * \return -
 *
 */
void getValidString(char requestMessage[],char errorMessage[], char input[]);

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void cleanStdin(void);

/** \brief
 * Funcion para limpiar la pantalla de la consola
 * \param void Sin parametros
 * \return -
 *
 */
void clearScreen(void);
