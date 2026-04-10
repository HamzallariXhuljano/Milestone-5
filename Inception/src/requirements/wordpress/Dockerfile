# 1. Zona d'atterraggio: Debian Bookworm
FROM debian:bookworm

# 2. Installazione pacchetti: Il minimo indispensabile per il combattimento
# php-fpm: Il motore
# php-mysql: Il traduttore per parlare con MariaDB
# mariadb-client: Per controllare se il DB è pronto
# curl: Per scaricare il WP-CLI
RUN apt-get update && apt-get install -y \
	php-fpm \
	php-mysql \
	mariadb-client \
	curl \
	&& rm -rf /var/lib/apt/lists/*

# 3. Configurazione Universale della Frequenza (Porta 9000)
# Modifichiamo il file di configurazione per ascoltare sulla rete e non sul socket locale.
RUN sed -i 's/listen = \/run\/php\/php[0-9.]*-fpm.sock/listen = 9000/g' /etc/php/[0-9.]*/fpm/pool.d/www.conf


RUN ln -s $(ls /usr/sbin/php-fpm*) /usr/sbin/php-fpm

# Copia della configurazione personalizzata (Senza versione hardcoded)
COPY conf/www.conf /tmp/www.conf
RUN mv /tmp/www.conf /etc/php/$(ls /etc/php)/fpm/pool.d/www.conf
# 4. Installazione del WP-CLI (Il tuo coltellino svizzero)
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
	&& chmod +x wp-cli.phar \
	&& mv wp-cli.phar /usr/local/bin/wp

# 5. Preparazione del terreno
# Creiamo la cartella per i file di processo (PID) altrimenti PHP-FPM non parte.
RUN mkdir -p /run/php

# 6. Definizione dell'area di lavoro
WORKDIR /var/www/html

# 7. Inserimento dello Script Operativo (L'intelligenza del container)
# Copiamo lo script di setup che gestirà lo scaricamento di WordPress
COPY tools/setup.sh /usr/local/bin/setup.sh
RUN chmod +x /usr/local/bin/setup.sh

# 8. Segnale di avvio
# Usiamo ENTRYPOINT per assicurarci che lo script venga sempre eseguito.
ENTRYPOINT ["/usr/local/bin/setup.sh"]
