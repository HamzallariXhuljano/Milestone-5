FROM debian:bookworm

RUN apt-get update && apt-get install -y nginx openssl

# Creazione cartella per i certificati
RUN mkdir -p /etc/nginx/ssl

# Generazione certificato auto-firmato (per il protocollo TLS)
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=IT/ST=Florence/L=Florence/O=42/OU=42/CN=login.42.fr/UID=login"

# Copia della tua configurazione personalizzata
COPY conf/nginx.conf /etc/nginx/conf.d/default.conf

# Lancio di Nginx in primo piano (daemon off)
CMD [ "nginx", "-g", "daemon off;" ]
