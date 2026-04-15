
# Developer Documentation

## Prerequisites
- Docker & Docker Compose.
- Correct mapping in `/etc/hosts` for `xhamzall.42.fr`.
- A valid `.env` file in the `src/` directory.

## Setup & Execution
The developer must use the following Makefile commands:
- `make setup`: **Crucial Step.** Creates `/home/xhamzall/data/mariadb` and `/home/xhamzall/data/wordpress` on the host machine. Docker will fail to mount volumes if this step is skipped.
- `make build`: Triggers the Docker build process for all images.
- `make up`: Launches the containers in detached mode.

## Data Management
- **Persistence**: Data is stored on the host in the `/home/xhamzall/data/` directory.
- **Database Entry**:
  ```bash
  sudo docker exec -it mariadb mariadb -u root -p

## Building and Launching
The infrastructure is built and managed using the Makefile:

**make setup**: This is the first critical step. It creates the persistence directories: /home/xhamzall/data/mariadb and /home/xhamzall/data/wordpress.

**make build**: Compiles the Dockerfiles located in src/requirements/.

**make up**: Orchestrates the launch using docker-compose.yml.

## Data Persistence
  Project data is stored on the host machine to ensure persistence across container restarts or deletions. The data is located at:

  **MariaDB Data**: /home/xhamzall/data/mariadb

  **WordPress Site Files**: /home/xhamzall/data/wordpress

## Service Verification
  At the start of the evaluation, the services are configured on the following standard ports:

**NGINX**: Port 443 (HTTPS).

**MariaDB**: Port 3306 (Internal).

**WordPress**: Port 9000 (PHP-FPM).

## SSL and Protocol Verification
To verify that NGINX is correctly using TLSv1.2/v1.3 and providing a secure response, use:

Bash
  curl -vI -k https://xhamzall.42.fr


