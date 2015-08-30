import java.io.*;
import java.util.*;

class Main {
  public static void main(String [] args)
    throws FileNotFoundException {
    
    System.setIn(new FileInputStream("file.in"));
    System.setOut(new PrintStream("file.out"));
    
    Scanner in = new Scanner(System.in);
    int n = in.nextInt(); String a = in.next();
  }
}
