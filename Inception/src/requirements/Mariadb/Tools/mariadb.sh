#!/bin/bash
if [ -d "var/lib/mysql/$MYSQL_DATABASE" ]
then
	echo "The databese is already present"
else
	echo "The database is missing: creating..."

	mysqld_safe &

	sleep 5

	mysql -e "CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;"
	mysql -e "CREATE USER IF NOT EXISTS\`${MYSQL_USER}\`@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';"
	mysql -e "GRANT ALL PRIVILEGES ON\`${MYSQL_DATABASE}\`.* TO \`${MYSQL_USER}\`@'%';"
	mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOTPASSWORD}';"
	mysql -e "FLUSH PRIVILEGES;"
	mysqladmin -u root -p${MYSQL_ROOTPASSWORD} shutdown
fi

exec mysqld_safe
