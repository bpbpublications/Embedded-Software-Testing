#ifdef COVERAGE
#define BNE(destination) bne destination##_expand
#else
#define BNE(destination) bne destination
#endif
