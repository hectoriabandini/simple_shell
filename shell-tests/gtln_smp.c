#define _GNU_SOURCE
       #include <stdio.h>
       #include <stdlib.h>

       int
       main(int argc, char *argv[])
       {
           char stream;
           char *line;
           size_t len = 0;
           ssize_t nread;

           //if (argc != 2) {
             //  fprintf(stderr, "Usage: %s <file>\n", argv[0]);
              // exit(EXIT_FAILURE);
           //}

           //stream = fopen(argv[1], "r");
           //if (stream == NULL) {
              // perror("fopen");
               //exit(EXIT_FAILURE);
           //}

           while ((nread = getline(&line, &len, stdin)) != -1) {
               printf("Retrieved line of length %zd:\n", nread);
               fwrite(line, nread, 1, stdout);
           }

           free(line);
           //fclose(stream);
           exit(EXIT_SUCCESS);
       }
