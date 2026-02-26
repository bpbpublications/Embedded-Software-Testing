try
{
  if (reso == null)
  { 
     File f = new File(name);
     reader = new FileReader(f);
  }
  else
  {
     reader = new InputStreamReader(reso.openStream());
  }
}
catch (Exception)
{
  // At this point we have lost the stack trace, making it harder
  // to debug the code when the exception is thrown in the try-block.
  throw new IOException("Cannot open the reader");
}
