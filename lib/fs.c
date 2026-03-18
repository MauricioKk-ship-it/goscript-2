#include <stdio.h>
#include <stdlib.h>
#include "../src/fe.h"

/* (fs/read-file "path") */
static fe_Object* f_fs_read(fe_Context *ctx, fe_Object *args) {
  char path[256], *buf;
  long sz;
  fe_Object *res;
  fe_tostring(ctx, fe_nextarg(ctx, &args), path, sizeof(path));
  
  FILE *f = fopen(path, "rb");
  if (!f) return fe_bool(ctx, 0); // Retourne nil si échec

  fseek(f, 0, SEEK_END);
  sz = ftell(f);
  fseek(f, 0, SEEK_SET);
  
  buf = malloc(sz + 1);
  fread(buf, 1, sz, f);
  buf[sz] = '\0';
  fclose(f);

  res = fe_string(ctx, buf);
  free(buf);
  return res;
}

/* (fs/write-file "path" "content") */
static fe_Object* f_fs_write(fe_Context *ctx, fe_Object *args) {
  char path[256], content[1024]; // Ajuste la taille si besoin
  fe_tostring(ctx, fe_nextarg(ctx, &args), path, sizeof(path));
  fe_tostring(ctx, fe_nextarg(ctx, &args), content, sizeof(content));
  
  FILE *f = fopen(path, "wb");
  if (!f) return fe_bool(ctx, 0);
  
  fprintf(f, "%s", content);
  fclose(f);
  return fe_bool(ctx, 1); // Retourne t
}

/* Enregistrement des fonctions */
void fs_init(fe_Context *ctx) {
  fe_set(ctx, fe_symbol(ctx, "fs/read-file"), fe_cfunc(ctx, f_fs_read));
  fe_set(ctx, fe_symbol(ctx, "fs/write-file"), fe_cfunc(ctx, f_fs_write));
}
