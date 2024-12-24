
#include "fractol.h"
int get_smooth_color_julia(int iter, double w_re, double w_im, double bailout)
{
    // Calcoliamo la magnitudine di w (modulo complesso)
    double w2 = w_re * w_re + w_im * w_im;

    // Se la magnitudine supera il valore di bailout, il punto non appartiene al frattale (quindi è nero)
    if (w2 > bailout * bailout)
        return 0x000000;  // Colore nero per i punti che non appartengono al frattale

    // Estimazione della distanza in base a w2 e d2
    double d2 = 1.0;  // Inizializzazione di d2 (può essere affinato)
    double d = sqrt(w2 / d2) * log(w2);  // Stima della distanza

    // Applicazione della fineness per regolare la sfumatura del colore
    float dist = (sqrt(d * pow(2, 2)));  // Regolazione della distanza per la colorazione

    // Calcoliamo la proporzione di iterazioni rispetto al numero massimo di iterazioni
    double t = (double)iter / MAX_ITER;  // Proporzione di iterazioni
	if (iter == 75)
		return 0x333333;

    // Calcolo del colore basato sul valore di t (iterazioni)
    int r = (int)(9 * (1 - t) * t * 255);
    int g = (int)(15 * (1 - t) * t * t * 255);
    int b = (int)(8.5 * (1 - t) * t * t * t * 255);

    // Regolazione dei colori in base alla distanza stimata (per aggiungere variazione)
    r = (int)(r * (1.0 + dist));  // Aumenta l'intensità del rosso in base alla distanza
    g = (int)(g * (1.0 + dist));  // Aumenta l'intensità del verde in base alla distanza
    b = (int)(b * (1.0 + dist));  // Aumenta l'intensità del blu in base alla distanza

    // Assicurarsi che i colori non diventino troppo scuri, impostiamo una soglia minima
    r = (r < 50) ? 50 : r;
    g = (g < 50) ? 50 : g;
    b = (b < 50) ? 50 : b;

    // Normalizzazione dei colori per non superare il valore massimo di 255
    r = (r > 255) ? 255 : r;
    g = (g > 255) ? 255 : g;
    b = (b > 255) ? 255 : b;

    // Restituisce il colore in formato 0xRRGGBB
    return (r << 16) | (g << 8) | b;
}

int get_smooth_color_pow(int iter, double z_re, double z_im) {
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
}


int get_smooth_color(int iter, double z_re, double z_im) {
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
}

int get_smooth_color_basic(int iter, double z_re, double z_im)
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
}

int get_smooth_color_limit(int iter, double z_re, double z_im)
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

