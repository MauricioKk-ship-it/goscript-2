/*
** GoScript (GJS) Header
** GOPU INC - 2026
** Defining the core structures for the GoScript Runtime.
*/

#ifndef GSC_H
#define GSC_H

#include <stdio.h>

/* --- Configuration & Version --- */
#define GSC_VERSION "1.0.0"
typedef float fe_Number; /* Type numérique de base */

/* --- Types d'objets GoScript --- */
enum {
  FE_TPAIR,      /* Liste / Paire cons */
  FE_TFREE,      /* Objet libre (Garbage Collector) */
  FE_TNIL,       /* Valeur nulle / Fin de liste */
  FE_TNUMBER,    /* Nombre (float) */
  FE_TSYMBOL,    /* Symbole / Identifiant */
  FE_TSTRING,    /* Chaîne de caractères */
  FE_TFUNC,      /* Fonction (Closure) */
  FE_TMACRO,     /* Macro */
  FE_TPRIM,      /* Primitive native (C interne) */
  FE_TCFUNC,     /* Fonction C externe (Callback) */
  FE_TPTR        /* Pointeur brut (pour extensions) */
};

/* --- Définitions des types opaques --- */
typedef struct fe_Object fe_Object;
typedef struct fe_Context fe_Context;

/* --- Prototypes des fonctions de rappel (Callbacks) --- */
typedef fe_Object* (*fe_CFunc)(fe_Context *ctx, fe_Object *args);
typedef void (*fe_ErrorFn)(fe_Context *ctx, const char *err, fe_Object *cl);
typedef void (*fe_WriteFn)(fe_Context *ctx, void *udata, char chr);
typedef char (*fe_ReadFn)(fe_Context *ctx, void *udata);

typedef struct {
  fe_ErrorFn error;
  fe_CFunc mark;
  fe_CFunc gc;
} fe_Handlers;

/* --- Fonctions de Gestion du Contexte --- */
fe_Context* fe_open(void *ptr, int size);
void fe_close(fe_Context *ctx);
fe_Handlers* fe_handlers(fe_Context *ctx);
void fe_error(fe_Context *ctx, const char *msg);

/* --- Fonctions du Garbage Collector (GC) --- */
void fe_pushgc(fe_Context *ctx, fe_Object *obj);
void fe_restoregc(fe_Context *ctx, int idx);
int fe_savegc(fe_Context *ctx);
void fe_mark(fe_Context *ctx, fe_Object *obj);

/* --- Création d'objets --- */
fe_Object* fe_cons(fe_Context *ctx, fe_Object *car, fe_Object *cdr);
fe_Object* fe_bool(fe_Context *ctx, int b);
fe_Object* fe_number(fe_Context *ctx, fe_Number n);
fe_Object* fe_string(fe_Context *ctx, const char *str);
fe_Object* fe_symbol(fe_Context *ctx, const char *name);
fe_Object* fe_cfunc(fe_Context *ctx, fe_CFunc fn);
fe_Object* fe_ptr(fe_Context *ctx, void *ptr);
fe_Object* fe_list(fe_Context *ctx, fe_Object **objs, int n);

/* --- Accès aux données des objets --- */
fe_Object* fe_car(fe_Context *ctx, fe_Object *obj);
fe_Object* fe_cdr(fe_Context *ctx, fe_Object *obj);
fe_Object* fe_nextarg(fe_Context *ctx, fe_Object **arg);
int fe_type(fe_Context *ctx, fe_Object *obj);
int fe_isnil(fe_Context *ctx, fe_Object *obj);
fe_Number fe_tonumber(fe_Context *ctx, fe_Object *obj);
void fe_tostring(fe_Context *ctx, fe_Object *obj, char *dst, int size);
void* fe_toptr(fe_Context *ctx, fe_Object *obj);

/* --- Entrées / Sorties --- */
fe_Object* fe_read(fe_Context *ctx, fe_ReadFn fn, void *udata);
void fe_write(fe_Context *ctx, fe_Object *obj, fe_WriteFn fn, void *udata, int quoted);

/* --- Fonctions utilitaires (facultatif mais pratique) --- */
/* Pour transformer gsc.c en standalone */
void fe_set(fe_Context *ctx, fe_Object *sym, fe_Object *v);

fe_Object* fe_readfp(fe_Context *ctx, FILE *fp);
fe_Object* fe_eval(fe_Context *ctx, fe_Object *obj);
/* --- Nouveau : Prototypes pour les modules natifs --- */
void fs_init(fe_Context *ctx);

#endif /* GSC_H */
