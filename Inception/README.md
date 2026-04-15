*This project has been created as part of the 42 curriculum by [xhamzall].*

# Inception - System Administration with Docker

## Description
The **Inception** project is an in-depth exploration of infrastructure virtualization using Docker. The primary goal is to build a complete, reproducible, and secure system composed of multiple services, each isolated within its own dedicated container. This project emphasizes system administration best practices, networking, and volume management.

### Use of Docker and Design Choices
Each service is built from scratch using **Debian Bookworm** as the base image. Using Docker allows for a "clean" environment where dependencies are strictly controlled and services are isolated from the host system.
- **Modularity**: Every service (NGINX, WordPress, MariaDB) runs in its own container to ensure that a failure in one does not directly compromise the others.
- **Controlled Entrypoint**: NGINX is the only service that interacts with the external network, acting as a secure gateway.

### Technical Comparisons
- **Virtual Machines vs Docker**: Virtual Machines (VMs) virtualize physical hardware, requiring a full guest OS for each instance, which leads to high resource overhead. Docker virtualizes the OS kernel, allowing containers to share the host kernel while maintaining isolation, making them significantly more lightweight and faster.
- **Secrets vs Environment Variables**: Environment variables are useful for general configuration but can be easily viewed via system commands. Secrets (handled here through a protected `.env` file) are intended for sensitive data like passwords, ensuring they are only accessible to the authorized services.
- **Docker Network vs Host Network**: A Host network shares the host machine's IP and port space directly, offering no isolation. A Docker Network (Bridge) creates a private virtual network where containers communicate using internal DNS (service names), isolating internal traffic from the outside world.
- **Docker Volumes vs Bind Mounts**: Docker Volumes are managed by the Docker daemon and abstracted from the host file system structure. Bind Mounts (used in this project) link a specific, absolute path on the host to a path in the container, providing direct control over where persistent data is stored on the host machine.

## Instructions

### Execution Flow
The project is fully automated via a Makefile. To deploy the entire infrastructure:
```bash
make all

Resources:
   Docker Documentation
   NGINX SSL/TLS Configuration
   WP-CLI Handbook

AI Usage
   AI was utilized for the following tasks:
   Architectural Guidance: Designing the communication bridge between MariaDB and WordPress.
   Troubleshooting: Diagnosing TLS handshake issues and NGINX upstream synchronization.
   Scripting: Optimizing setup.sh to ensure database readiness before WordPress installation.
   Documentation: Structuring technical comparisons and drafting Markdown files in English.

Project Structure:

.
├── Makefile                # Lifecycle automation
├── README.md               # Main project overview
├── USER_DOC.md             # End-user documentation
├── DEV_DOC.md              # Technical developer documentation
└── src/
    ├── .env                # Sensitive configuration (not tracked by Git)
    ├── docker-compose.yml  # Orchestration of the service stack
    └── requirements/
        ├── mariadb/
        │   ├── conf/       # MariaDB server configuration
        │   ├── tools/      # Initialization scripts
        │   └── Dockerfile
        ├── nginx/
        │   ├── conf/       # TLS and NGINX configuration
        │   └── Dockerfile
        └── wordpress/
            ├── conf/       # PHP-FPM configuration
            ├── tools/      # WordPress setup and CLI scripts
            └── Dockerfile
