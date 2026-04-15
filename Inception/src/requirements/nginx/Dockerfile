FROM debian:bookworm

#Install nginx
RUN apt-get update && apt-get install -y nginx openssl

# Creation of certification
RUN mkdir -p /etc/nginx/ssl

# Generate certificate auto-signed for TLS
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=IT/ST=Florence/L=Florence/O=42/OU=42/CN=xhamzall.42.fr/UID=xhamzall"

#delete defolt folder
RUN rm -rf /etc/nginx/sites-enabled/default

# Copy of my configurate folder in default.conf
COPY conf/nginx.conf /etc/nginx/conf.d/default.conf

# Run nginx
CMD [ "nginx", "-g", "daemon off;" ]
