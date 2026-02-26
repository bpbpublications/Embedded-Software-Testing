if ((a == b) && (b == c)) 

{

   outbound_value = "equal"; 

}

else

{

   outbound_value = "nope";

}

The test tool would (amongst other mutations) create a mutant that looks like:
if ((a == b) || (b == c)) 

{

   outbound_value = "equal"; 

}

else

{

   outbound_value = "nope";

}
