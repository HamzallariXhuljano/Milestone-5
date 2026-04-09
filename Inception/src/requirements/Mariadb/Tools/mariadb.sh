#!/bin/bash

# 1. Check se il database esiste già (Persistenza)
if [ ! -d "/var/lib/mysql/mysql" ]; then

	mysql_install_db --user=mysql --datadir=/var/lib/mysql
fi

cat << EOF > /tmp/mariadb.sql
CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
CREATE USER IF NOT EXISTS 'root'@'%' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' WITH GRANT OPTION;
DELETE FROM mysql.user WHERE User='';
FLUSH PRIVILEGES;
EOF

exec mysqld --user=mysql --init-file=/tmp/mariadb.sql
