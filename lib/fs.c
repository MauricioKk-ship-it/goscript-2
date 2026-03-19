#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gsc.h"

/* (fs/read-file "path") */
static gs_Object* f_fs_read(gs_Context *ctx, gs_Object *args) {
  char path[256], *buf;
  long sz;
  gs_Object *res;
  
  gs_tostring(ctx, gs_nextarg(ctx, &args), path, sizeof(path));
  
  FILE *f = fopen(path, "rb");
  if (!f) return gs_bool(ctx, 0); // Retourne nil si échec

  fseek(f, 0, SEEK_END);
  sz = ftell(f);
  fseek(f, 0, SEEK_SET);
  
  buf = (char*)malloc(sz + 1);
  if (!buf) {
    fclose(f);
    return gs_bool(ctx, 0);
  }
  
  fread(buf, 1, sz, f);
  buf[sz] = '\0';
  fclose(f);

  res = gs_string(ctx, buf);
  free(buf);
  return res;
}

/* (fs/write-file "path" "content") */
static gs_Object* f_fs_write(gs_Context *ctx, gs_Object *args) {
  char path[256];
  char content[1024]; // Ajuste la taille si besoin
  
  gs_tostring(ctx, gs_nextarg(ctx, &args), path, sizeof(path));
  gs_tostring(ctx, gs_nextarg(ctx, &args), content, sizeof(content));
  
  FILE *f = fopen(path, "wb");
  if (!f) return gs_bool(ctx, 0);
  
  fprintf(f, "%s", content);
  fclose(f);
  return gs_bool(ctx, 1); // Retourne t
}

/* Enregistrement des fonctions */
void fs_init(gs_Context *ctx) {
  gs_set(ctx, gs_symbol(ctx, "fs/read-file"), gs_cfunc(ctx, f_fs_read));
  gs_set(ctx, gs_symbol(ctx, "fs/write-file"), gs_cfunc(ctx, f_fs_write));
}
