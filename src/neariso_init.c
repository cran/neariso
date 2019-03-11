#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* FIXME: 
   Check these declarations against the C/Fortran source code.
*/

/* .Call calls */
extern SEXP NIR(SEXP);
extern SEXP NIRexplicitSolution(SEXP, SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"NIR",                 (DL_FUNC) &NIR,                 1},
    {"NIRexplicitSolution", (DL_FUNC) &NIRexplicitSolution, 2},
    {NULL, NULL, 0}
};

void R_init_neariso(DllInfo *dll)
{
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
