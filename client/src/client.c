#include "client.h"


int main(void)
{
	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	logger = iniciar_logger();

	log_info(logger, "Hola! Soy un log");

	config = iniciar_config();

	ip = config_get_string_value(config, "IP");
	puerto = config_get_string_value(config, "PUERTO");
	valor = config_get_string_value(config, "CLAVE");

	log_info(logger, "\nIP: %s\n PUERTO: %s\n CLAVE: %s\n", ip, puerto, valor);

	leer_consola(logger);

	conexion = crear_conexion(ip, puerto);

	enviar_mensaje(valor, conexion);

	paquete(conexion);

	terminar_programa(conexion, logger, config);
}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger;

	if((nuevo_logger = log_create("tp0.log", "TP0", 1,LOG_LEVEL_INFO)) == NULL) {
		printf("No se pudo crear el log\n");
		exit(1);
	}

	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config;

	if ((nuevo_config = config_create("./cliente.config")) == NULL) {
		printf("No se pudo crear el config\n");
		exit(2);
	}

	return nuevo_config;
}

void leer_consola(t_log* logger)
{
	char* leido;

	leido = readline("> ");

	while (strcmp(leido, "")) {
		log_info(logger, leido);
		leido = readline("> ");
	}

	free(1);
}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	paquete = crear_paquete();



	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	if (logger != NULL) {
		log_destroy(logger);
	}

	if (config != NULL) {
		config_destroy(config);
	}

	liberar_conexion(conexion);
}
