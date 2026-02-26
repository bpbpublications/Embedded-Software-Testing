extern bool boolA;
extern bool boolB;

/* Here is the original function:
 * void test(void) { if (boolA && boolB) printf("Hallo!"); }
 * Here is the instrumented function: */

void test(void)
{
   // Instrumentation variables initialization
   _cth_i _cth_flg = 0;
   _cth_i _cth_ignoreretn = 0;
   _cth_w _cth_boolvalues[2][2];
   _cth_i _cth_fnid = _cth_recordinstr(
                         _cth_filename,
                         &_cth_funcname[0],
                         (_cth_i) 1,
                         &_cth_instrs[0],
                         &_cth_dectab[0],
                         &_cth_statetab[0],
                         &_cth_complexity[0][0],
                         &_cth_asserttab[0],
                         _cth_timestamp,
                         &_cth_callpair_l[0],
                         741873471);

   _cth_i _cth_recordfiledummy = 
     _cth_recordfile(_cth_fnid,
                     _cth_fileanal,
                     _cth_preprocanal);

   _cth_i _cth_initbooldummy = _cth_initbool(_cth_fnid, 
                                  &_cth_booltab[0],
                                  &_cth_funcname[0]);

   _cth_i _cth_dummyvar = _cth_usevars \ 
                          (&_cth_recordfiledummy,
                           &_cth_initbooldummy, 
                           &_cth_ignoreretn,
                           &_cth_boolvalues[0][0], 
                           &_cth_flg, 
                           &_cth_dummyvar);

   /* STATEMENT 1 */
   _cth_ignoreretn = _cth_logstate(_cth_fnid , 1);

   if (
      /* DECISION 1 */
      _cth_logdec ( _cth_fnid , 1 , 
        !!((_cth_startbool(_cth_fnid, 
                           _cth_boolvalues, 0, 1),
        _cth_logbool(_cth_fnid, _cth_boolvalues, 0, 1,  
           !!(_cth_logsubbool(_cth_fnid, _cth_boolvalues,
              0, 1, 1, !!(boolA)) &&
        _cth_logsubbool(_cth_fnid, 
                        _cth_boolvalues, 0, 1, 2, 
                        !!(boolB)))))))) 
   {
      /* STATEMENT 2 */
      _cth_ignoreretn = _cth_logstate(_cth_fnid , 2);

      /* CALL PAIR 1 */
      (_cth_logcallpair ( _cth_fnid , 1 ),
      printf("Hallo!"));
   } /* if */
} /* test() */
