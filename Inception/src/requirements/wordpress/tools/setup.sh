#!/bin/bash
until mariadb-admin ping -h"mariadb" --silent; do
	echo "waiting for mariadb is ready"
	sleep 3
done;
if [ ! -f /var/www/html/wp-config.php ]; then
	echo "starting the install of wordpress..."

	#downloading of the last stable version
	wp core download --allow-root

	#creating of the file wp-config.php (the bridge to the db)
	wp config create --allow-root \
		--dbname=$MYSQL_DATABASE \
		--dbuser=$MYSQL_USER \
		--dbpass=$MYSQL_PASSWORD\
		--dbhost=mariadb:3306

	#Install the site (configuration of the admin)
	wp core install --allow-root \
		--url=$DOMAIN_NAME \
		--title="INCEPTION" \
		--admin_user=$WP_ADMIN_USER \
		--admin_password=$WP_ADMIN_PASSWORD \
		--admin_email=$WP_ADMIN_EMAIL

	#Create the second user
	wp user create $WP_USER $WP_USER_EMAIL \
		--user_pass=$WP_USER_PASSWORD \
		--role=author \
		--allow-root
	echo "Succesfull installed"
else
	echo "Wordpress allready installed skip the configuration"
fi
echo "Starting of PHP-FPM"

exec php-fpm -F

