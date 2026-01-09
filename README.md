# get_next_line

Lecture ligne par ligne depuis un file descriptor - Projet 42 Paris

## À propos

Get Next Line est un projet qui consiste à créer une fonction capable de lire une ligne complète depuis un file descriptor, peu importe la taille de la ligne ou la taille du buffer.

C'est un projet intéressant qui m'a fait comprendre la gestion de la mémoire dynamique et la lecture par chunks. J'ai appris à gérer des buffers, à lire par petits morceaux, et à reconstruire des lignes complètes même quand elles dépassent la taille du buffer.

## Compilation

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

Ou avec le bonus (plusieurs file descriptors) :

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c
```

## Utilisation

```c
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Fonctionnalités

- Lecture ligne par ligne depuis un file descriptor
- Gestion de buffers de taille variable (définie par BUFFER_SIZE)
- Gestion de plusieurs file descriptors (version bonus)
- Gestion mémoire correcte (pas de fuites)
- Gestion des cas limites (fichier vide, ligne très longue, etc.)

## Version bonus

La version bonus permet de gérer plusieurs file descriptors simultanément. Chaque appel à `get_next_line` avec un file descriptor différent maintient son propre état de lecture.

## Ce que j'ai appris

- Gestion de la mémoire avec buffers statiques
- Lecture par chunks depuis un file descriptor
- Gestion des cas limites (fichier vide, ligne très longue, EOF)
- Allocation dynamique de mémoire
- Gestion de plusieurs file descriptors simultanément (bonus)

---

**Projet réalisé dans le cadre du cursus 42 Paris**

**Note obtenue : 125/100**

![Note 125/100](notes/get_next_line_note.png)
