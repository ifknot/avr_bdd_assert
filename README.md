# avr_bdd_assert
C++ compact string free behaviour reporting 

Combining concepts from behavior-driven development (BDD) with the Barr Group web article 
[How to Define Your Own assert Macro for Embedded Systems](https://barrgroup.com/embedded-systems/how-to/define-assert-macro
It is a combination of comments for the BDD and REQUIRE macro generating 32 bit error/reporting codes based on software version, file id and line number

## example
```cpp

#include "require.h"

SET_VERSION(0x21);  // version 2.1
SET_FILE_ID(0x0B);  // unique file id 11

int main() { 
  
  //SCENARIO some things to test 
    ...
  //GIVEN those things
    ...
    REQUIRE( 1 == 1 );
    REQUIRE( false );
    ...
  //WHEN something else happens
    ...     
  //THEN there are expected consequences
    REQUIRE( true);
    REQUIRE( 2 < 0 );          
    ...

```
