
#include "fractol.h"
/*int get_smooth_color(int iter, double z_re, double z_im) {
    if (iter == MAX_ITER)
        return 0x000000; // Nero per i punti nel frattale

    // Calcolo della parte "frazionaria" per il colore
    double magnitude = sqrt(z_re * z_re + z_im * z_im);
    double smooth_iter = iter + 1 - log2(log2(magnitude));

    // Normalizzazione del valore smooth_iter tra 0 e 1
    double t = smooth_iter / MAX_ITER;

    // Correzione gamma per un output visivamente più gradevole
    t = pow(t, 0.8); // Gamma correction con esponente 0.8

    // Mappatura RGB con gradienti personalizzati
    int r = (int)(9 * (1 - t) * t * 255);
    int g = (int)(15 * (1 - t) * t * t * 255);
    int b = (int)(8.5 * (1 - t) * t * t * t * 255);

    // Componi il colore in formato 0xRRGGBB
    return (r << 16) | (g << 8) | b;
}*/


/*int get_smooth_color(int iter, double z_re, double z_im) {
    if (iter == MAX_ITER)
        return 0x000000;

    // Calcolo della parte frazionaria
    double magnitude = sqrt(z_re * z_re + z_im * z_im);
    double smooth_iter = iter + 1 - log2(log2(magnitude));

    // Normalizzazione tra 0 e 1
    double t = smooth_iter / MAX_ITER;

    // Gradiente basato su funzioni sinusoidali
    int r = (int)(128 + 127 * sin(5.0 * M_PI * t));
    int g = (int)(128 + 127 * sin(5.0 * M_PI * t + 2.0));
    int b = (int)(128 + 127 * sin(5.0 * M_PI * t + 4.0));

    return (r << 16) | (g << 8) | b;
}*/

/*int get_smooth_color(int iter, double z_re, double z_im)
{
    double smooth_iter;
    int color;

    if (iter == MAX_ITER)
        return 0x000000; // Colore nero per i punti all'interno del frattale

    // Calcolo della parte "frazionaria" per la sfumatura
    double magnitude = sqrt(z_re * z_re + z_im * z_im);
    smooth_iter = iter + 1 - log2(log2(magnitude));

    // Usa smooth_iter per calcolare una sfumatura RGB
    int r = (int)(9 * (1 - smooth_iter / MAX_ITER) * 255);
    int g = (int)(15 * (1 - smooth_iter / MAX_ITER) * 255);
    int b = (int)(8.5 * (1 - smooth_iter / MAX_ITER) * 255);

    // Componi il colore in formato 0xRRGGBB
    color = (r << 16) | (g << 8) | b;
    return color;
}*/
int get_smooth_color(int iter, double z_re, double z_im)
{
    // Se il numero di iterazioni è massimo, il pixel non appartiene al frattale, quindi è nero
    if (iter == MAX_ITER)
        return 0x000000;  // Colore nero per i punti che non appartengono al frattale

    // Calcoliamo la magnitudine di z (modulo complesso)
    double magnitude = sqrt(z_re * z_re + z_im * z_im);

    // Calcolo della parte frazionaria per la sfumatura
    double smooth_iter = iter + 1 - log2(log2(magnitude));

    // Normalizzazione del valore di smooth_iter
    double t = smooth_iter / MAX_ITER;



    // Calcoliamo il colore in base al valore di t
    int r = (int)(9 * (1 - t) * t * 255);
    int g = (int)(15 * (1 - t) * t * t * 255);
    int b = (int)(8.5 * (1 - t) * t * t * t * 255);

    // Assicuriamoci che i colori non diventino troppo scuri, impostiamo una soglia minima
    r = (r < 30) ? 30 : r;  // Imposto un minimo valore di rosso
    g = (g < 30) ? 30 : g;  // Imposto un minimo valore di verde
    b = (b < 30) ? 30 : b;  // Imposto un minimo valore di blu

    // Restituisci il colore in formato 0xRRGGBB
    return (r << 16) | (g << 8) | b;
}

