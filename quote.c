#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  char *home = getenv("HOME");
  if (home == NULL) {
    printf("HOME environment variable not set.\n");
    return 1;
  }

  char path[512];
  snprintf(path, sizeof(path), "%s/.config/quotes.txt", home);

  FILE *file = fopen(path, "r");
  if (file == NULL) {
    printf("Failed to load file: %s\n", path);
    return 1;
  }

  char quotes[100][256];
  int count = 0;

  char *colors[] = {
    "\033[1;31m",  // Red
    "\033[1;32m",  // Green
    "\033[1;33m",  // Yellow
    "\033[1;34m",  // Blue
    "\033[1;35m"   // Magenta
  };

  int color_index = rand() % 5;

  while (fgets(quotes[count], sizeof(quotes[count]), file)) {
    quotes[count][strcspn(quotes[count], "\n")] = '\0';
    count++;

    if (count >= 100) break; 
  }

  fclose(file);

  int index = rand() % count;
  printf("%s%s\033[0m\n", colors[color_index], quotes[index]);

  return 0;
}

