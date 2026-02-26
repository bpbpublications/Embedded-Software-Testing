/* We do not use the assert macro from <assert.h>, because that one
 * does not generate any object code when compiled in release mode
 * and we must compile our unit tests with exactly the same compiler
 * settings as we compile production code. 
 * The macro we define here still is anything else than comfortable but it 
 * suffices demonstrating how a component test can look like.  
 */
#define MY_ASSERT(exp) if (!exp) \
   printf("ERROR in %s:%d\n",__FILE__, __LINE__); \
   else printf("Assertion in %s:%d PASSED\n",__FILE__, __LINE__);

