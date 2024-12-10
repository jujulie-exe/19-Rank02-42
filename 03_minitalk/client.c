/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:49:52 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/10 17:02:00 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"
#include "mini_talk.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

void send_bit(pid_t server_pid, int bit) {
    if (bit == 0) {
        if (kill(server_pid, SIGUSR1) == -1) {
            write(2, "Error sending SIGUSR1\n", 23);
            exit(1);
        }
    } else if (bit == 1) {
        if (kill(server_pid, SIGUSR2) == -1) {
            write(2, "Error sending SIGUSR2\n", 23);
            exit(1);
        }
    }
    usleep(200); // Pausa per dare tempo al server di processare il segnale
}

void send_number(pid_t server_pid, unsigned int number, int bits) {
    int i = bits - 1;

    while (i >= 0) {
        send_bit(server_pid, (number >> i) & 1);
        i--;
    }
}

void send_message(pid_t server_pid, const char *message) {
    while (*message) {
        send_number(server_pid, *message, 8); // Invia un carattere (8 bit)
        message++;
    }
    send_number(server_pid, '\0', 8); // Invia il carattere nullo per terminare il messaggio
}

#define PID_BITS 32

// Funzione per inviare il PID al server tramite segnali
void send_pid(pid_t pid, pid_t server_pid) {
    for (int i = PID_BITS - 1; i >= 0; i--) {
        int bit = (pid >> i) & 1;
        if (bit == 0) {
            kill(server_pid, SIGUSR1);  // Invio di SIGUSR1 per 0
        } else {
            kill(server_pid, SIGUSR2);  // Invio di SIGUSR2 per 1
        }
        usleep(100);  // Piccola pausa tra i segnali per non sovraccaricare il sistema
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        write(2, "Usage: ./client <server_pid>\n", 28);
        return 1;
    }

    pid_t server_pid = atoi(argv[1]);
    pid_t client_pid = getpid();  // Ottieni il PID del client

    send_pid(client_pid, server_pid);  // Invia il PID del client al server

    return 0;
}

