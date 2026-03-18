#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fe.h"

/* Cette fonction reste statique car elle n'est utilisée que dans ce fichier */
static fe_Object* load_module(fe_Context *ctx, fe_Object *args, int is_local) {
  fe_Object *arg = fe_nextarg(ctx, &args);
  char path_buf[256];
  char file_path[512];
  char target_symbol[128] = "";
  char *first_sep;
  FILE *fp;
  int gc;
  fe_Object *obj;

  fe_tostring(ctx, arg, path_buf, sizeof(path_buf));

  first_sep = strstr(path_buf, "::");
  if (first_sep) {
    char *last_sep, *temp;
    *first_sep = '\0'; 
    last_sep = first_sep + 2;
    while ((temp = strstr(last_sep, "::")) != NULL) {
      last_sep = temp + 2;
    }
    strcpy(target_symbol, last_sep);
  }

  if (is_local) {
    snprintf(file_path, sizeof(file_path), "./%s.fe", path_buf);
  } else {
    snprintf(file_path, sizeof(file_path), "/usr/local/lib/goscript/%s.fe", path_buf);
  }

  fp = fopen(file_path, "rb");
  if (!fp) {
    char err[512];
    snprintf(err, sizeof(err), "Module not found: %s", file_path);
    fe_error(ctx, err);
  }

  gc = fe_savegc(ctx);
  while ((obj = fe_readfp(ctx, fp))) {
    fe_eval(ctx, obj);
    fe_restoregc(ctx, gc);
  }
  fclose(fp);

  if (target_symbol[0] != '\0') {
    return fe_eval(ctx, fe_symbol(ctx, target_symbol));
  }
  return fe_bool(ctx, 1);
}

/* Ces fonctions NE DOIVENT PAS être static pour être vues par fe.c */
fe_Object* f_use(fe_Context *ctx, fe_Object *args) {
  return load_module(ctx, args, 0);
}

fe_Object* f_nm(fe_Context *ctx, fe_Object *args) {
  return load_module(ctx, args, 1);
}
