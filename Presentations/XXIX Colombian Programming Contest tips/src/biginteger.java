// DO NOT EVER INCLUDE A PACKAGE.

import java.util.*;
import java.math.BigInteger;

// BE CAREFUL WITH THE CLASS NAME.
// It should be the same as the problem basename in BOCA Problems tab.
public class biginteger {
  public static void main (String [] args) {
    Scanner in = new Scanner(System.in);
    BigInteger a = in.nextBigInteger();
    BigInteger b = in.nextBigInteger();
    System.out.println(a.add(b));
  }
}
