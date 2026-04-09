#!/bin/bash

# 1. Check se il database esiste già (Persistenza)
if [ -d "/var/lib/mysql/$MYSQL_DATABASE" ]
then
	echo "MariaDB: Database già presente. Salto la configurazione iniziale."
else
	echo "MariaDB: Database mancante. Inizio installazione..."

	# Inizializza le tabelle di sistema
	mysql_install_db --user=mysql --datadir=/var/lib/mysql

	# Avvio temporaneo in background per la configurazione
	# Usiamo --user=mysql per evitare problemi di permessi root
	mysqld_safe --user=mysql --datadir=/var/lib/mysql &

	# 2. Attesa dinamica
	until mysqladmin ping >/dev/null 2>&1; do
		echo "MariaDB: In attesa dell'avvio temporaneo..."
		sleep 1
	done

	# 3. Esecuzione SQL (Metodo Heredoc - Pulito e sicuro)
	mysql -u root << EOF
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
CREATE USER IF NOT EXISTS \`${MYSQL_USER}\`@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO \`${MYSQL_USER}\`@'%';
CREATE USER IF NOT EXISTS \`${MYSQL_USER}\`@'localhost' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO \`${MYSQL_USER}\`@'localhost';
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
FLUSH PRIVILEGES;
EOF

	echo "MariaDB: Configurazione SQL completata con successo."

	# 4. Spegnimento dell'istanza temporanea
	# Usiamo la nuova password di root appena impostata
	mysqladmin -u root -p"${MYSQL_ROOT_PASSWORD}" shutdown

	# Aspettiamo che il processo background sparisca davvero per liberare la porta 3306
	while pgrep mariadbd >/dev/null; do sleep 1; done
fi
# --- IL PEZZO MANCANTE ---
exec mysqld_safe --user=mysql --datadir=/var/lib/mysql
